/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The exec.c
*/
/**
 * @file exec.c
 * @brief The exec.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../../lib/my/headers/myworld.h"

void click_quit_p(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(world->pause.quit.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->st_game = EXIT;
    }
}

void click_resume(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(world->pause.resume.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->st_game = GAME;
    }
}

void click_settings_p(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(world->pause.settings.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->st_game = SETTINGS_M;
    }
}

void click_main(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(world->pause.main.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->st_game = MAIN;
        world->old_st = MAIN_O;
    }
}
