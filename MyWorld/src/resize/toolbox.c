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

static void text(toolbox_t *toolbox, world_t *world, float sx, float scale)
{
    resize_text(toolbox->raise_t,
        &(sfVector2f){world->mode.width / 25.f, world->mode.height / 7},
        (unsigned int)(12.f * scale));
    resize_text(toolbox->decrease_t,
        &(sfVector2f){world->mode.width / 25.f, world->mode.height * 0.230f},
        (unsigned int)(12.f * sx));
    resize_text(toolbox->point_t,
        &(sfVector2f){world->mode.width / 25.f, world->mode.height * 0.310f},
        (unsigned int)(12.f * scale));
    resize_text(toolbox->area_t,
        &(sfVector2f){world->mode.width / 25.f, world->mode.height * 0.387f},
        (unsigned int)(12.f * scale));
}

static void sprite(toolbox_t *toolbox, world_t *world, float sx, float sy)
{
    resize_sprite(toolbox->tool.sprite,
        &(sfVector2f){world->mode.width / 25, world->mode.height / 17},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
    resize_sprite(toolbox->close.sprite,
        &(sfVector2f){world->mode.width / 25, world->mode.height / 17},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
    resize_sprite(toolbox->raise.sprite,
        &(sfVector2f){world->mode.width / 25, world->mode.height / 7},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
    resize_sprite(toolbox->decrease.sprite,
        &(sfVector2f){world->mode.width / 25, world->mode.height * 0.230},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
    resize_sprite(toolbox->point.sprite,
        &(sfVector2f){world->mode.width / 25, world->mode.height * 0.310},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
    resize_sprite(toolbox->area.sprite,
        &(sfVector2f){world->mode.width / 25, world->mode.height * 0.387},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
}

void resize_toolbox(toolbox_t *toolbox, world_t *world)
{
    float sx = (float)world->mode.width / 1920.f;
    float sy = (float)world->mode.height / 1080.f;
    float scale = sx < sy ? sx : sy;

    sprite(toolbox, world, sx, sy);
    text(toolbox, world, sx, scale);
}
