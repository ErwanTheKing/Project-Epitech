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

#include "../../lib/my/headers/myworld.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

static void display_sprite(world_t *world)
{
    sfRenderWindow_drawSprite(world->window, world->main_menu.background.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->main_menu.start.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->main_menu.settings.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->main_menu.quit.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->main_menu.logo.sprite,
        NULL);
}

void display_cursor(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);

    sfSprite_setPosition(world->main_menu.cursor.sprite, mouse);
    sfRenderWindow_drawSprite(world->window, world->main_menu.cursor.sprite,
        NULL);
}

void display_main(world_t *world)
{
    sfRenderWindow_clear(world->window, sfBlack);
    display_sprite(world);
    display_cursor(world);
}
