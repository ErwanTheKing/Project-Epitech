/*
** EPITECH PROJECT, 2026
** main
** File description:
** main
*/

#include "../../include/wolf3d.h"

int is_in_range(player_t *player, player_t *monster)
{
    float dx = player->x - monster->x;
    float dy = player->y - monster->y;

    return sqrtf(dx * dx + dy * dy) < MONSTER_ATTACK_RANGE;
}

static void damage_player(wolf_t *wolf, player_t *player,
    uint32_t player_id)
{
    if (wolf->connected && network_is_host(wolf) &&
        player_id != wolf->net.player_id) {
        network_send_player_damage(wolf, player_id, MONSTER_ATTACK_DMG);
        return;
    }
    player->hp -= MONSTER_ATTACK_DMG;
    player->took_damage = sfTrue;
    if (player->damage_clock)
        sfClock_restart(player->damage_clock);
}

static void attack_target(wolf_t *wolf, player_t *monster,
    player_t *player, uint32_t player_id)
{
    float elapsed;

    if (monster->alive == sfFalse || player->alive == sfFalse)
        return;
    if (!is_in_range(player, monster))
        return;
    elapsed = sfClock_getElapsedTime(monster->attack_clock).microseconds
        / 1000000.0f;
    if (elapsed < MONSTER_ATTACK_CD)
        return;
    sfClock_restart(monster->attack_clock);
    damage_player(wolf, player, player_id);
}

void is_near_monster(wolf_t *wolf, player_t *player)
{
    player_t *monster;

    if (wolf->connected && !network_is_host(wolf))
        return;
    for (list_t *curr = wolf->list[GAME][MONSTER]; curr; curr = curr->next) {
        monster = (player_t *)curr->data;
        attack_target(wolf, monster, player, wolf->net.player_id);
        if (!wolf->connected)
            continue;
        for (int i = 0; i < wolf->nb_others; i++)
            attack_target(wolf, monster, &wolf->others[i], (uint32_t)i);
    }
}
