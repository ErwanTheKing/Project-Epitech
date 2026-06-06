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

#include "../include/includes.h"

static void create_bg(button_loose_t *manage_sprite)
{
    manage_sprite->background.texture
    = sfTexture_createFromFile("asset/bg/loosemenu.jpg", NULL);
    if (!manage_sprite->background.texture)
        return;
    manage_sprite->background.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->background.sprite,
        manage_sprite->background.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->background.sprite,
        (sfVector2f){0, 0});
    sfSprite_setScale(manage_sprite->background.sprite,
        (sfVector2f){0.78f, 0.6f});
}

static void create_retry(button_loose_t *manage_sprite)
{
    manage_sprite->retry.texture
    = sfTexture_createFromFile("asset/button/retry.png", NULL);
    if (!manage_sprite->retry.texture)
        return;
    manage_sprite->retry.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->retry.sprite,
        manage_sprite->retry.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->retry.sprite,
        (sfVector2f){335, 400});
    sfSprite_setScale(manage_sprite->retry.sprite,
        (sfVector2f){0.2f, 0.2f});
}

static void create_mainmenu(button_loose_t *manage_sprite)
{
    manage_sprite->mainmenu.texture
    = sfTexture_createFromFile("asset/button/mainmenu_loose.png", NULL);
    if (!manage_sprite->mainmenu.texture)
        return;
    manage_sprite->mainmenu.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->mainmenu.sprite,
        manage_sprite->mainmenu.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->mainmenu.sprite,
        (sfVector2f){326, 470});
    sfSprite_setScale(manage_sprite->mainmenu.sprite,
        (sfVector2f){0.2f, 0.2f});
}

int click_mainmenu_loose(sfSprite *sprite, sfRenderWindow *window,
    music_t *music, bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        main_menu(window, music, bool);
    }
    return 0;
}

int click_retry(sfSprite *sprite, sfRenderWindow *window,
    music_t *music, bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        my_hunter(window, music, bool);
    }
    return 0;
}

void create_sprite_loose(button_loose_t *manage_sprite)
{
    create_bg(manage_sprite);
    create_retry(manage_sprite);
    create_mainmenu(manage_sprite);
}
