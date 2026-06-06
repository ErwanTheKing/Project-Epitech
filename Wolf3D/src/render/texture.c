/*
** EPITECH PROJECT, 2026
** rays
** File description:
** draw other players
*/

#include "../../include/wolf3d.h"

sfUint8 *get_texture(wall_t *wall, player_draw_t *d)
{
    switch (d->type) {
        case ENNEMY:
            return wall->decor_arr[3];
        case GARBAGE_T:
            return wall->decor_arr[4];
        case PLAYER:
            return wall->decor_arr[2];
        case HEAL_T:
            return wall->decor_arr[5];
        default:
            return NULL;
    }
}
