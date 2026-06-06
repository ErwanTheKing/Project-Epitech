/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** map
*/

#include "../include/wolf3d.h"

int get_map_tile(wall_t *wall, int tile_x, int tile_y)
{
    return wall->map[tile_y][tile_x];
}
