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

#include "../../lib/my/headers/myworld.h"

static void text(pause_t *pause, world_t *world, float sx, float scale)
{
    resize_text(pause->resume_t,
        &(sfVector2f){world->mode.width / 3.f, world->mode.height / 2.5f},
        (unsigned int)(70.f * scale));
    resize_text(pause->settings_t,
        &(sfVector2f){world->mode.width / 1.5f, world->mode.height / 2.5f},
        (unsigned int)(70.f * sx));
    resize_text(pause->quit_t,
        &(sfVector2f){world->mode.width / 1.5f, world->mode.height / 1.5f},
        (unsigned int)(70.f * scale));
    resize_text(pause->main_t,
        &(sfVector2f){world->mode.width / 3.f, world->mode.height / 1.5f},
        (unsigned int)(70.f * scale));
}

static void sprite(pause_t *pause, world_t *world, float sx, float sy)
{
    resize_sprite(pause->resume.sprite,
        &(sfVector2f){world->mode.width / 3, world->mode.height / 2.5},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
    resize_sprite(pause->settings.sprite,
        &(sfVector2f){world->mode.width / 1.5, world->mode.height / 2.5},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
    resize_sprite(pause->quit.sprite,
        &(sfVector2f){world->mode.width / 1.5, world->mode.height / 1.5},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
    resize_sprite(pause->main.sprite,
        &(sfVector2f){world->mode.width / 3, world->mode.height / 1.5},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
}

void resize_pause(pause_t *pause, world_t *world)
{
    float sx = (float)world->mode.width / 1920.f;
    float sy = (float)world->mode.height / 1080.f;
    float scale = sx < sy ? sx : sy;

    sprite(pause, world, sx, sy);
    text(pause, world, sx, scale);
}
