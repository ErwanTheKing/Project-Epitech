/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** network entity sync
*/

#include "../include/wolf3d.h"

int network_is_host(wolf_t *wolf)
{
    return wolf && wolf->connected && wolf->net.player_id == 0;
}

static int get_list_index(p_type_t type)
{
    if (type == ENNEMY)
        return MONSTER;
    if (type == GARBAGE_T)
        return GARBAGE;
    if (type == HEAL_T)
        return HEAL;
    return -1;
}

player_t *network_get_entity_by_id(wolf_t *wolf, p_type_t type, int net_id)
{
    int list_index = get_list_index(type);

    if (list_index < 0)
        return NULL;
    for (list_t *curr = wolf->list[GAME][list_index]; curr;
        curr = curr->next) {
        if (((player_t *)curr->data)->net_id == net_id)
            return (player_t *)curr->data;
    }
    return NULL;
}

player_t *network_get_or_create_entity(wolf_t *wolf, p_type_t type,
    int net_id, sfVector2f *pos)
{
    player_t *entity = network_get_entity_by_id(wolf, type, net_id);
    int list_index = get_list_index(type);

    if (entity || list_index < 0)
        return entity;
    entity = init_player(wolf->window_data, type, pos);
    if (!entity)
        return NULL;
    entity->net_id = net_id;
    push_front(&wolf->list[GAME][list_index], entity);
    return entity;
}

void network_send_entity_state(wolf_t *wolf, p_type_t type,
    int entity_id, player_t *entity)
{
    network_packet_t pkt;

    if (!wolf->connected || wolf->net.player_id == MAX_PLAYERS || !entity)
        return;
    memset(&pkt, 0, sizeof(pkt));
    pkt.type = PKT_ENTITY_STATE;
    pkt.x = entity->x;
    pkt.y = entity->y;
    pkt.angle = entity->angle;
    pkt.data[0] = (uint8_t)type;
    pkt.data[1] = entity->alive ? 1 : 0;
    memcpy(&pkt.data[4], &entity_id, sizeof(entity_id));
    memcpy(&pkt.data[8], &entity->hp, sizeof(entity->hp));
    client_send_packet(&wolf->net, &pkt);
}

static void send_entity_list(wolf_t *wolf, int list_index, p_type_t type)
{
    player_t *entity;

    for (list_t *curr = wolf->list[GAME][list_index]; curr;
        curr = curr->next) {
        entity = (player_t *)curr->data;
        network_send_entity_state(wolf, type, entity->net_id, entity);
    }
}

void network_send_entity_states(wolf_t *wolf)
{
    if (!network_is_host(wolf))
        return;
    send_entity_list(wolf, MONSTER, ENNEMY);
    send_entity_list(wolf, GARBAGE, GARBAGE_T);
    send_entity_list(wolf, HEAL, HEAL_T);
}
