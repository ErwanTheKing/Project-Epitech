/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The button.c
*/
/**
 * @file button.c
 * @brief The button.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

void click_play(sfSprite *sprite, sfRenderWindow *window, music_t *music,
    bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        chose_mode(window, bool, music);
    }
}

void click_settings(sfSprite *sprite, sfRenderWindow *window, music_t *music,
    bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        if (bool->game_on == 1)
            bool->settings_game = 1;
        settings_menu(window, music, bool);
    }
}

void click_exit(sfSprite *sprite, sfRenderWindow *window)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        sfRenderWindow_close(window);
    }
}
