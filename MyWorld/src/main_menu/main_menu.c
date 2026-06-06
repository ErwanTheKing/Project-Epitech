/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The main_menu.c
*/
/**
 * @file main_menu.c
 * @brief The main_menu.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/myworld.h"

static void init(world_t *world)
{
    sfMusic_play(world->main_menu.music);
}

int create_main(world_t *world)
{
    if (sprite_main(&world->main_menu, world) == FAILURE)
        return FAILURE;
    init(world);
    return SUCCESS;
}
