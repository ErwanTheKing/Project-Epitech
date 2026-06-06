/*
** EPITECH PROJECT, 2026
** weapon
** File description:
** weapon
*/

#include "../../../include/wolf3d.h"

static void handle_monster_death(wolf_t *wolf, player_t *monster)
{
    if (rand() % 3 == 0)
        push_front(&wolf->list[GAME][HEAL], init_player(NULL, HEAL_T,
                &(sfVector2f){monster->x, monster->y}));
    monster->alive = sfFalse;
    if (monster->type == ENNEMY)
        wolf->score += 100;
    else if (monster->type == GARBAGE_T)
        wolf->score += 50;
}

static int get_list_index(p_type_t type)
{
    if (type == ENNEMY)
        return MONSTER;
    if (type == GARBAGE_T)
        return GARBAGE;
    return -1;
}

static player_t *get_monster_by_id(wolf_t *wolf, p_type_t type, int net_id)
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

static int get_monster_id(wolf_t *wolf, player_t *monster)
{
    (void)wolf;
    return monster->net_id;
}

void damage_monster_by_index(wolf_t *wolf, p_type_t type,
    int entity_id, int damage)
{
    player_t *monster = get_monster_by_id(wolf, type, entity_id);

    if (!monster || monster->alive == sfFalse)
        return;
    monster->hp -= damage;
    if (monster->hp <= 0)
        handle_monster_death(wolf, monster);
    if (network_is_host(wolf))
        network_send_entity_state(wolf, type, entity_id, monster);
}

static sfBool can_damage_monster(weapon_t *weapon, wolf_t *wolf,
    player_draw_t *draw, player_t *monster)
{
    int shot = wolf->window_data->width / 2;

    if (draw->transform.y <= 0 || draw->sprite_width <= 0
        || draw->sprite_height <= 0)
        return sfFalse;
    if ((weapon->type == VACUUM && monster->type != GARBAGE_T) ||
        (weapon->type != VACUUM && monster->type != ENNEMY))
        return sfFalse;
    if ((weapon->type == SHOTGUN && draw->distance > 8) ||
        (weapon->type == VACUUM && draw->distance > 3))
        return sfFalse;
    return (shot >= draw->drawStart.x && shot <= draw->drawEnd.x);
}

static void send_damage_to_host(wolf_t *wolf, p_type_t type,
    int entity_id, int damage)
{
    network_packet_t pkt;

    if (!wolf->connected || network_is_host(wolf) || entity_id < 0)
        return;
    memset(&pkt, 0, sizeof(pkt));
    pkt.type = PKT_ENTITY_DAMAGE;
    pkt.timestamp = entity_id;
    pkt.data[0] = (uint8_t)type;
    memcpy(&pkt.data[4], &damage, sizeof(damage));
    client_send_packet(&wolf->net, &pkt);
}

void damage_monster(weapon_t *weapon, wolf_t *wolf,
    player_draw_t *draw, player_t *monster)
{
    int entity_id = -1;

    if (!can_damage_monster(weapon, wolf, draw, monster))
        return;
    entity_id = get_monster_id(wolf, monster);
    if (wolf->connected && !network_is_host(wolf)) {
        send_damage_to_host(wolf, monster->type, entity_id,
            weapon->damage);
        return;
    }
    damage_monster_by_index(wolf, monster->type, entity_id,
        weapon->damage);
}
