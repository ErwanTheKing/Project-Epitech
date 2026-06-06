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
    sfRenderWindow_drawSprite(world->window, world->main_menu.logo.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->pause.resume.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->pause.settings.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->pause.quit.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->pause.main.sprite,
        NULL);
}

static void display_text(world_t *world)
{
    sfRenderWindow_drawText(world->window, world->pause.resume_t, NULL);
    sfRenderWindow_drawText(world->window, world->pause.settings_t, NULL);
    sfRenderWindow_drawText(world->window, world->pause.quit_t, NULL);
    sfRenderWindow_drawText(world->window, world->pause.main_t, NULL);
}

void display_pause(world_t *world)
{
    sfRenderWindow_clear(world->window, sfBlack);
    display_sprite(world);
    display_text(world);
    display_cursor(world);
}
