/*
** EPITECH PROJECT, 2026
** create_map
** File description:
** Map Memory Allocation & Initialization
*/

#include <stdlib.h>
#include "../../lib/my/headers/myworld.h"
#include "../../lib/my/headers/defines.h"

static int init_map_points(map_t *map)
{
    for (int y = 0; y != map->height; y++) {
        map->points[y] = malloc(sizeof(vector3f_t) * map->width);
        if (map->points[y] == NULL)
            return FAILURE;
        for (int x = 0; x != map->width; x++) {
            map->points[y][x].x = x;
            map->points[y][x].y = y;
            map->points[y][x].z = 0;
        }
    }
    return SUCCESS;
}

void center_map(map_t *map, int window_width, int window_height)
{
    if (!map)
        return;
    map->offset.x = (float)window_width / 2.0f;
    map->offset.y = (float)window_height / 4.0f;
}

map_t *create_map(world_t *world)
{
    map_t *new_map;

    new_map = malloc(sizeof(map_t));
    if (new_map == NULL)
        return NULL;
    new_map->zoom = 32.0;
    new_map->angle_x = 0.52;
    new_map->angle_y = 0.52;
    new_map->offset.x = 0;
    new_map->offset.y = 0;
    new_map->height = world->coords.x;
    new_map->width = world->coords.y;
    new_map->points = malloc(sizeof(vector3f_t *) * new_map->height);
    if (new_map->points == NULL)
        return NULL;
    if (init_map_points(new_map) == FAILURE)
        return NULL;
    return new_map;
}
