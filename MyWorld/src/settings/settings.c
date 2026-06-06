/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The settings.c
*/
/**
 * @file settings.c
 * @brief The settings.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"
#include "../../lib/my/headers/defines.h"

static void init(settings_t *settings)
{
    settings->fullscreen = sfFalse;
    settings->vsync = sfTrue;
    settings->vsync_int = 60;
}

int create_settings(world_t *world)
{
    if (sprite_settings(&world->settings, world) == FAILURE)
        return FAILURE;
    if (text_settings(&world->settings, world) == FAILURE)
        return FAILURE;
    if (sprite_musics(&world->settings, world) == FAILURE)
        return FAILURE;
    init(&world->settings);
    return SUCCESS;
}
