/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Monster target selection
*/

#include "../../include/wolf3d.h"

static float get_dist_sq(player_t *a, player_t *b)
{
    float dx = a->x - b->x;
    float dy = a->y - b->y;

    return dx * dx + dy * dy;
}

player_t *get_nearest_enemy(wolf_t *wolf, player_t *monster,
    player_t *player)
{
    player_t *nearest = player->alive ? player : NULL;
    float best = nearest ? get_dist_sq(monster, nearest) : 0.0f;
    float dist;

    if (!wolf->connected)
        return nearest;
    for (int i = 0; i < wolf->nb_others; i++) {
        if (wolf->others[i].alive != sfTrue)
            continue;
        dist = get_dist_sq(monster, &wolf->others[i]);
        if (!nearest || dist < best) {
            nearest = &wolf->others[i];
            best = dist;
        }
    }
    return nearest;
}
