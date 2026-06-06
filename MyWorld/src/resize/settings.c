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

#include <stdio.h>

#include "../../lib/my/headers/myworld.h"

static void text(settings_t *settings, world_t *world, float sx, float scale)
{
    resize_text(settings->back_t,
        &(sfVector2f){world->mode.width / 2.f, world->mode.height / 1.33f},
        (unsigned int)(70.f * scale));
    resize_text(settings->full_t,
        &(sfVector2f){world->mode.width / 2.25f, world->mode.height / 3.1f},
        (unsigned int)(30.f * sx));
    resize_text(settings->vsync_t,
        &(sfVector2f){world->mode.width / 2.37f, world->mode.height / 2.52f},
        (unsigned int)(30.f * scale));
    resize_text(settings->res_t,
        &(sfVector2f){world->mode.width / 2.4, world->mode.height / 2.1},
        (unsigned int)(18.f * scale));
    resize_text(settings->frame_t,
        &(sfVector2f){world->mode.width / 1.72, world->mode.height / 2.1},
        (unsigned int)(18.f * scale));
}

static void musics(world_t *world, float sx, float sy, float scale)
{
    resize_text(world->settings.musics,
        &(sfVector2f){world->mode.width / 2, world->mode.height / 1.9},
        (unsigned int)(50.f * scale));
    resize_text(world->settings.more_t,
        &(sfVector2f){world->mode.width / 1.8, world->mode.height / 1.7},
        (unsigned int)(60.f * scale));
    resize_text(world->settings.less_t,
        &(sfVector2f){world->mode.width / 2.2, world->mode.height / 1.7},
        (unsigned int)(60.f * scale));
    resize_text(world->settings.volume,
        &(sfVector2f){world->mode.width / 2, world->mode.height / 1.7},
        (unsigned int)(30.f * scale));
    resize_sprite(world->settings.more.sprite,
        &(sfVector2f){world->mode.width / 1.8, world->mode.height / 1.7},
        &(sfVector2f){0.1 * sx, 0.1 * sy});
    resize_sprite(world->settings.less.sprite,
        &(sfVector2f){world->mode.width / 2.2, world->mode.height / 1.7},
        &(sfVector2f){0.1 * sx, 0.1 * sy});
}

static void vsync(settings_t *settings, world_t *world, float sx, float sy)
{
    resize_sprite(settings->vsync_case.sprite,
        &(sfVector2f){world->mode.width / 2.74, world->mode.height / 2.5},
        &(sfVector2f){0.1 * sx, 0.1 * sy});
    resize_sprite(settings->vsync_check.sprite,
        &(sfVector2f){world->mode.width / 2.75, world->mode.height / 2.52},
        &(sfVector2f){0.15 * sx, 0.15 * sy});
}

static void sprite(settings_t *settings, world_t *world, float sx, float sy)
{
    resize_sprite(settings->settings.sprite,
        &(sfVector2f){world->mode.width / 2, world->mode.height / 2},
        &(sfVector2f){sx, sy});
    resize_sprite(settings->back.sprite,
        &(sfVector2f){world->mode.width / 2, world->mode.height * 0.753},
        &(sfVector2f){0.45 * sx, 0.45 * sy});
    resize_sprite(settings->full_case.sprite,
        &(sfVector2f){world->mode.width / 2.74, world->mode.height / 3.08},
        &(sfVector2f){0.1 * sx, 0.1 * sy});
    resize_sprite(settings->full_check.sprite,
        &(sfVector2f){world->mode.width / 2.75, world->mode.height / 3.1},
        &(sfVector2f){0.15 * sx, 0.15 * sy});
    vsync(settings, world, sx, sy);
    resize_sprite(settings->res_case.sprite,
        &(sfVector2f){world->mode.width / 2.4, world->mode.height / 2.1},
        &(sfVector2f){0.35 * sx, 0.25 * sy});
    resize_sprite(settings->frame_case.sprite,
        &(sfVector2f){world->mode.width / 1.72, world->mode.height / 2.1},
        &(sfVector2f){0.35 * sx, 0.25 * sy});
}

void resize_settings(settings_t *settings, world_t *world)
{
    float sx = (float)world->mode.width / 1920.f;
    float sy = (float)world->mode.height / 1080.f;
    float scale = sx < sy ? sx : sy;

    sprite(settings, world, sx, sy);
    text(settings, world, sx, scale);
    musics(world, sx, sy, scale);
}
