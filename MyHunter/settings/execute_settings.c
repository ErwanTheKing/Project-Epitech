/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The button_settings.c
*/
/**
 * @file button_settings.c
 * @brief The button_settings.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../include/includes.h"

int click_back(sfSprite *sprite, sfRenderWindow *window, music_t *music,
    bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        if (bool->game_on == 0)
            return -1;
        main_menu(window, music, bool);
    }
    return 0;
}

void click_more(sfSprite *sprite, sfRenderWindow *window, music_t *music)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    int volume = sfMusic_getVolume(music->music);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        sfMusic_setVolume(music->music, volume + 10);
        sfMusic_setVolume(music->snowball, volume + 10);
    }
}

void click_less(sfSprite *sprite, sfRenderWindow *window, music_t *music)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    float volume = sfMusic_getVolume(music->music);
    float newvolume = volume - 10;

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        if (newvolume < 0.0f)
            newvolume = 0.0f;
        sfMusic_setVolume(music->music, newvolume);
        sfMusic_setVolume(music->snowball, newvolume);
    }
}

void click_res(button_setting_t *manage_button, sfRenderWindow *window,
    bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = {0, 0, 0, 0};

    if (bool->res_on == sfTrue) {
        bounds = sfSprite_getGlobalBounds(manage_button->res800.sprite);
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
            bool->res_on = sfFalse;
            sfRenderWindow_setSize(window, (sfVector2u){1920, 1080});
            sfRenderWindow_setPosition(window, (sfVector2i){0, 0});
        }
    } else {
        bounds = sfSprite_getGlobalBounds(manage_button->res1920.sprite);
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
            bool->res_on = sfTrue;
            sfRenderWindow_setSize(window, (sfVector2u){800, 600});
        }
    }
}

void click_vsync(button_setting_t *manage_button, sfRenderWindow *window,
    bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = {0, 0, 0, 0};

    if (bool->vsync_on == sfTrue) {
        bounds = sfSprite_getGlobalBounds(manage_button->enable.sprite);
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
            bool->vsync_on = sfFalse;
            sfRenderWindow_setVerticalSyncEnabled(window, sfFalse);
        }
    } else {
        bounds = sfSprite_getGlobalBounds(manage_button->disable.sprite);
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
            bool->vsync_on = sfTrue;
            sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
        }
    }
}
