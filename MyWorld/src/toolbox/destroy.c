/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The destroy.c
*/
/**
 * @file destroy.c
 * @brief The destroy.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"

static void texture(toolbox_t *toolbox)
{
    sfTexture_destroy(toolbox->tool.texture);
    sfTexture_destroy(toolbox->close.texture);
    sfTexture_destroy(toolbox->raise.texture);
    sfTexture_destroy(toolbox->decrease.texture);
    sfTexture_destroy(toolbox->point.texture);
    sfTexture_destroy(toolbox->area.texture);
}

static void sprite(toolbox_t *toolbox)
{
    sfSprite_destroy(toolbox->tool.sprite);
    sfSprite_destroy(toolbox->close.sprite);
    sfSprite_destroy(toolbox->raise.sprite);
    sfSprite_destroy(toolbox->decrease.sprite);
    sfSprite_destroy(toolbox->point.sprite);
    sfSprite_destroy(toolbox->area.sprite);
}

static void text(toolbox_t *toolbox)
{
    sfText_destroy(toolbox->raise_t);
    sfText_destroy(toolbox->decrease_t);
    sfText_destroy(toolbox->point_t);
    sfText_destroy(toolbox->area_t);
}

void destroy_toolbox(toolbox_t *toolbox)
{
    texture(toolbox);
    sprite(toolbox);
    text(toolbox);
}
