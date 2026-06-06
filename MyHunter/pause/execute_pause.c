/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The execute_pause.c
*/
/**
 * @file execute_pause.c
 * @brief The execute_pause.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

int click_resume(sfSprite *sprite, sfRenderWindow *window)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        return -1;
    }
    return 0;
}

int click_mainmenu(sfSprite *sprite, sfRenderWindow *window, music_t *music,
    bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        main_menu(window, music, bool);
    }
    return 0;
}
