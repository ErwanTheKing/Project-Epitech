/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The game.c
*/
/**
 * @file game.c
 * @brief The game.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <string.h>

#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/macros.h"
#include "../../lib/my/headers/myworld.h"

static void sound(map_t *map)
{
    map->up = sfSoundBuffer_createFromFile(UP);
    map->down = sfSoundBuffer_createFromFile(DOWN);
    map->raise = sfSound_create();
    map->decrease = sfSound_create();
    sfSound_setBuffer(map->raise, map->up);
    sfSound_setBuffer(map->decrease, map->down);
}

static void init(world_t *world)
{
    world->map->width = world->coords.x;
    world->map->width = world->coords.y;
    world->map->tool = sfFalse;
    world->map->toolbox.sens = RAISE_T;
    world->map->toolbox.size = POINT_T;
    world->map->toolbox.raise_h = sfFalse;
    world->map->toolbox.decrease_h = sfFalse;
    world->map->toolbox.point_h = sfFalse;
    world->map->toolbox.area_h = sfFalse;
    world->map->help_b = sfFalse;
    sound(world->map);
    world->map->size = 3;
}

int create_game(world_t *world)
{
    if (sprite_game(world->map) == FAILURE)
        return FAILURE;
    if (text_game(&world->map->help, world) == FAILURE)
        return FAILURE;
    rectangle_help(&world->map->help, world);
    init(world);
    if (strcmp(world->choose.name->input, "\0") == 0)
        strcpy(world->choose.name->input, "NoName");
    return SUCCESS;
}
