/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The display.c
*/
/**
 * @file display.c
 * @brief The display.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../../lib/my/headers/myworld.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

static void display_sprite(world_t *world, toolbox_t *toolbox)
{
    if (world->map->tool == sfFalse) {
        sfRenderWindow_drawSprite(world->window, toolbox->tool.sprite,
            NULL);
    } else {
        sfRenderWindow_drawSprite(world->window, toolbox->close.sprite,
            NULL);
        sfRenderWindow_drawSprite(world->window, toolbox->raise.sprite,
            NULL);
        sfRenderWindow_drawSprite(world->window, toolbox->decrease.sprite,
            NULL);
        sfRenderWindow_drawSprite(world->window, toolbox->point.sprite,
            NULL);
        sfRenderWindow_drawSprite(world->window, toolbox->area.sprite,
            NULL);
    }
}

static void display_text(world_t *world)
{
    if (world->map->toolbox.raise_h == sfTrue)
        sfRenderWindow_drawText(world->window, world->map->toolbox.raise_t,
            NULL);
    if (world->map->toolbox.decrease_h == sfTrue)
        sfRenderWindow_drawText(world->window, world->map->toolbox.decrease_t,
            NULL);
    if (world->map->toolbox.point_h == sfTrue)
        sfRenderWindow_drawText(world->window, world->map->toolbox.point_t,
            NULL);
    if (world->map->toolbox.area_h == sfTrue)
        sfRenderWindow_drawText(world->window, world->map->toolbox.area_t,
            NULL);
}

void display_toolbox(world_t *world)
{
    display_sprite(world, &world->map->toolbox);
    display_text(world);
}
