/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** network game update
*/

#include "../include/wolf3d.h"

static void handle_connect_packet(wolf_t *wolf, network_packet_t *pkt)
{
    if (wolf->net.player_id == MAX_PLAYERS) {
        wolf->net.player_id = pkt->player_id;
        wolf->lobby.is_host = (pkt->player_id == 0);
        wolf->lobby.nb_connected = (int)pkt->player_id + 1;
        return;
    }
    if (pkt->player_id != wolf->net.player_id)
        wolf->lobby.nb_connected = (int)pkt->player_id + 1;
}

static void handle_entity_damage_packet(wolf_t *wolf, network_packet_t *pkt)
{
    int damage = 0;
    player_t *heal;

    if (!network_is_host(wolf))
        return;
    if ((p_type_t)pkt->data[0] == HEAL_T) {
        heal = network_get_entity_by_id(wolf, HEAL_T, pkt->timestamp);
        if (heal)
            heal->alive = sfFalse;
        network_send_entity_state(wolf, HEAL_T, pkt->timestamp, heal);
        return;
    }
    memcpy(&damage, &pkt->data[4], sizeof(damage));
    damage_monster_by_index(wolf, (p_type_t)pkt->data[0],
        pkt->timestamp, damage);
}

static void handle_entity_state_packet(wolf_t *wolf, network_packet_t *pkt)
{
    player_t *entity;
    int hp = 0;
    p_type_t type = (p_type_t)pkt->data[0];
    int net_id = 0;
    sfVector2f pos = {pkt->x, pkt->y};

    if (network_is_host(wolf))
        return;
    memcpy(&net_id, &pkt->data[4], sizeof(net_id));
    entity = network_get_or_create_entity(wolf, type, net_id, &pos);
    if (!entity)
        return;
    memcpy(&hp, &pkt->data[8], sizeof(hp));
    entity->net_id = net_id;
    entity->x = pkt->x;
    entity->y = pkt->y;
    entity->angle = pkt->angle;
    entity->hp = hp;
    entity->alive = pkt->data[1] ? sfTrue : sfFalse;
}

static void handle_player_damage_packet(wolf_t *wolf, network_packet_t *pkt)
{
    int damage = 0;

    if (pkt->data[0] != wolf->net.player_id)
        return;
    memcpy(&damage, &pkt->data[4], sizeof(damage));
    wolf->player->hp -= damage;
    wolf->player->took_damage = sfTrue;
    if (wolf->player->damage_clock)
        sfClock_restart(wolf->player->damage_clock);
}

static void handle_recv_packet(wolf_t *wolf, network_packet_t *pkt)
{
    if (pkt->type == PKT_CONNECT)
        return handle_connect_packet(wolf, pkt);
    if (pkt->type == PKT_GAME_START && wolf->state == LOBBY)
        return network_handle_start_packet(wolf, pkt);
    if (pkt->type == PKT_GAME_STATE)
        return network_handle_state_packet(wolf, pkt);
    if (pkt->type == PKT_ENTITY_DAMAGE)
        return handle_entity_damage_packet(wolf, pkt);
    if (pkt->type == PKT_ENTITY_STATE)
        return handle_entity_state_packet(wolf, pkt);
    if (pkt->type == PKT_PLAYER_DAMAGE)
        return handle_player_damage_packet(wolf, pkt);
}

static void handle_recv_position(wolf_t *wolf, network_packet_t *pkt)
{
    if (pkt->type != PKT_PLAYER_POS)
        return;
    if (pkt->player_id == wolf->net.player_id || pkt->player_id >= MAX_PLAYERS)
        return;
    wolf->others[pkt->player_id].x = pkt->x;
    wolf->others[pkt->player_id].y = pkt->y;
    wolf->others[pkt->player_id].angle = pkt->angle;
    wolf->others[pkt->player_id].alive = pkt->data[0] ? sfTrue : sfFalse;
    if ((int)pkt->player_id >= wolf->nb_others)
        wolf->nb_others = (int)pkt->player_id + 1;
}

static void network_send(wolf_t *wolf, sfClock *send_clock)
{
    network_packet_t pkt;

    if (sfTime_asSeconds(sfClock_getElapsedTime(send_clock)) < 0.05f)
        return;
    sfClock_restart(send_clock);
    memset(&pkt, 0, sizeof(pkt));
    pkt.type = PKT_PLAYER_POS;
    pkt.x = wolf->player->x;
    pkt.y = wolf->player->y;
    pkt.angle = wolf->player->angle;
    pkt.data[0] = wolf->player->alive ? 1 : 0;
    if (client_send_packet(&wolf->net, &pkt) < 0)
        wolf->connected = 0;
    network_send_entity_states(wolf);
}

void network_update(wolf_t *wolf, sfClock *send_clock)
{
    network_packet_t pkt;

    if (!wolf->connected)
        return;
    while (client_recv_packet(&wolf->net, &pkt) > 0) {
        handle_recv_packet(wolf, &pkt);
        handle_recv_position(wolf, &pkt);
    }
    if ((wolf->state == GAME || network_is_host(wolf)) &&
        wolf->net.player_id != MAX_PLAYERS)
        network_send(wolf, send_clock);
}
