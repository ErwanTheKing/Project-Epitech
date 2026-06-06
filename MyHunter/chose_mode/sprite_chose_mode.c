/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The sprite_loose.c
*/
/**
 * @file sprite_loose.c
 * @brief The sprite_loose.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../include/includes.h"

static void create_bg(button_chose_mode_t *manage_sprite)
{
    manage_sprite->background.texture
    = sfTexture_createFromFile("asset/bg/chosemode.jpg", NULL);
    if (!manage_sprite->background.texture)
        return;
    manage_sprite->background.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->background.sprite,
        manage_sprite->background.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->background.sprite, (sfVector2f){0, 0});
    sfSprite_setScale(manage_sprite->background.sprite,
        (sfVector2f){0.55f, 0.6f});
}

static void create_eric(button_chose_mode_t *manage_sprite)
{
    manage_sprite->eric.texture
    = sfTexture_createFromFile("asset/button/eric.png", NULL);
    if (!manage_sprite->eric.texture)
        return;
    manage_sprite->eric.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->eric.sprite,
        manage_sprite->eric.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->eric.sprite, (sfVector2f){410, 200});
    sfSprite_setScale(manage_sprite->eric.sprite,
        (sfVector2f){0.5f, 0.5f});
}

static void create_renaud(button_chose_mode_t *manage_sprite)
{
    manage_sprite->renaud.texture
    = sfTexture_createFromFile("asset/button/renaud.png", NULL);
    if (!manage_sprite->renaud.texture)
        return;
    manage_sprite->renaud.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->renaud.sprite,
        manage_sprite->renaud.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->renaud.sprite, (sfVector2f){190, 200});
    sfSprite_setScale(manage_sprite->renaud.sprite,
        (sfVector2f){0.5f, 0.5f});
}

static void create_back(button_chose_mode_t *manage_sprite)
{
    manage_sprite->back.texture
    = sfTexture_createFromFile("asset/button/back.jpg", NULL);
    if (!manage_sprite->back.texture)
        return;
    manage_sprite->back.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->back.sprite,
        manage_sprite->back.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->back.sprite, (sfVector2f){50, 500});
    sfSprite_setScale(manage_sprite->back.sprite,
        (sfVector2f){0.1f, 0.1f});
}

int click_eric(sfSprite *sprite, sfRenderWindow *window,
    music_t *music, bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        bool->mode = 1;
        my_hunter(window, music, bool);
    }
    return 0;
}

int click_renaud(sfSprite *sprite, sfRenderWindow *window,
    music_t *music, bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        bool->mode = 0;
        my_hunter(window, music, bool);
    }
    return 0;
}

int click_back_chose(sfSprite *sprite, sfRenderWindow *window, music_t *music,
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

void create_sprite_chose(button_chose_mode_t *manage_sprite)
{
    create_bg(manage_sprite);
    create_eric(manage_sprite);
    create_renaud(manage_sprite);
    create_back(manage_sprite);
}
