/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The execute_settings2.c
*/
/**
 * @file execute_settings2.c
 * @brief The execute_settings2.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../include/includes.h"

static void fps_120(sfVector2f *mouse, bool_t *bool, sfRenderWindow *window,
    sfFloatRect *bounds)
{
    if (sfFloatRect_contains(bounds, mouse->x, mouse->y)) {
        bool->fps_on = 2;
        sfRenderWindow_setFramerateLimit(window, 120);
    }
}

static void fps_unlimited(sfVector2f *mouse, bool_t *bool,
    sfRenderWindow *window, sfFloatRect *bounds)
{
    if (sfFloatRect_contains(bounds, mouse->x, mouse->y)) {
        bool->fps_on = 3;
        sfRenderWindow_setFramerateLimit(window, 0);
    }
}

static void fps_30(sfVector2f *mouse, bool_t *bool, sfRenderWindow *window,
    sfFloatRect *bounds)
{
    if (sfFloatRect_contains(bounds, mouse->x, mouse->y)) {
        bool->fps_on = 0;
        sfRenderWindow_setFramerateLimit(window, 30);
    }
}

static void fps_60(sfVector2f *mouse, bool_t *bool, sfRenderWindow *window,
    sfFloatRect *bounds)
{
    if (sfFloatRect_contains(bounds, mouse->x, mouse->y)) {
        bool->fps_on = 1;
        sfRenderWindow_setFramerateLimit(window, 60);
    }
}

static void click_fps2(button_setting_t *manage_button, sfRenderWindow *window,
    bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = {0, 0, 0, 0};

    switch (bool->fps_on) {
        case 2:
            bounds = sfSprite_getGlobalBounds(manage_button->fps120.sprite);
            fps_unlimited(&mouse, bool, window, &bounds);
            break;
        case 3:
            bounds = sfSprite_getGlobalBounds(manage_button->unlimited.sprite);
            fps_30(&mouse, bool, window, &bounds);
            break;
        default:
            break;
    }
}

void click_fps(button_setting_t *manage_button, sfRenderWindow *window,
    bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = {0, 0, 0, 0};

    switch (bool->fps_on) {
        case 0:
            bounds = sfSprite_getGlobalBounds(manage_button->fps30.sprite);
            fps_60(&mouse, bool, window, &bounds);
            break;
        case 1:
            bounds = sfSprite_getGlobalBounds(manage_button->fps60.sprite);
            fps_120(&mouse, bool, window, &bounds);
            break;
        default:
            break;
    }
    click_fps2(manage_button, window, bool);
}
