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
    world->choose.size = SIZE8;
    world->choose.count_map = 0;
    world->choose.len = 0;
    world->choose.up_down = 0;
    world->choose.index_selected = 0;
}

int create_choose(world_t *world)
{
    if (sprite_choose(&world->choose, world) == FAILURE)
        return FAILURE;
    if (text_choose(&world->choose, world) == FAILURE)
        return FAILURE;
    circle_choose(&world->choose, world);
    if (textbox(&world->choose, world) == FAILURE)
        return FAILURE;
    init(world);
    create_disp_maps(&world->choose);
    return SUCCESS;
}
