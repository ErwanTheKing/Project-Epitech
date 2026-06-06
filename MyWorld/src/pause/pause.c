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

int create_pause(world_t *world)
{
    if (sprite_pause(&world->pause, world) == FAILURE)
        return FAILURE;
    if (text_pause(&world->pause, world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
