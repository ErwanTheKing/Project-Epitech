/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The sprite.c
*/
/**
 * @file sprite.c
 * @brief The sprite.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/macros.h"
#include "../../lib/my/headers/myworld.h"

static int background(main_menu_t *main_menu, world_t *world)
{
    sfVector2u textureSize;
    float scaleX;
    float scaleY;

    main_menu->background.texture = sfTexture_createFromFile(BACK_MAIN, NULL);
    if (!main_menu->background.texture)
        return FAILURE;
    main_menu->background.sprite = sfSprite_create();
    sfSprite_setTexture(main_menu->background.sprite,
        main_menu->background.texture, sfTrue);
    textureSize = sfTexture_getSize(main_menu->background.texture);
    scaleX = (float)world->mode.width / textureSize.x;
    scaleY = (float)world->mode.height / textureSize.y;
    sfSprite_setScale(main_menu->background.sprite,
        (sfVector2f){scaleX, scaleY});
    return SUCCESS;
}

static int start(main_menu_t *main_menu, world_t *world)
{
    sfVector2u textureSize;

    main_menu->start.texture = sfTexture_createFromFile(START, NULL);
    if (!main_menu->start.texture)
        return FAILURE;
    main_menu->start.sprite = sfSprite_create();
    sfSprite_setTexture(main_menu->start.sprite,
        main_menu->start.texture, sfTrue);
    textureSize = sfTexture_getSize(main_menu->start.texture);
    sfSprite_setOrigin(main_menu->start.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(main_menu->start.sprite,
        (sfVector2f){world->mode.width / 2, world->mode.height / 3});
    sfSprite_setScale(main_menu->start.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

static int settings(main_menu_t *main_menu, world_t *world)
{
    sfVector2u textureSize;

    main_menu->settings.texture = sfTexture_createFromFile(SETTINGS, NULL);
    if (!main_menu->settings.texture)
        return FAILURE;
    main_menu->settings.sprite = sfSprite_create();
    sfSprite_setTexture(main_menu->settings.sprite,
        main_menu->settings.texture, sfTrue);
    textureSize = sfTexture_getSize(main_menu->settings.texture);
    sfSprite_setOrigin(main_menu->settings.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(main_menu->settings.sprite,
        (sfVector2f){world->mode.width / 2, world->mode.height / 2.2});
    sfSprite_setScale(main_menu->settings.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

static int quit(main_menu_t *main_menu, world_t *world)
{
    sfVector2u textureSize;

    main_menu->quit.texture = sfTexture_createFromFile(QUIT_, NULL);
    if (!main_menu->quit.texture)
        return FAILURE;
    main_menu->quit.sprite = sfSprite_create();
    sfSprite_setTexture(main_menu->quit.sprite,
        main_menu->quit.texture, sfTrue);
    textureSize = sfTexture_getSize(main_menu->quit.texture);
    sfSprite_setOrigin(main_menu->quit.sprite, (sfVector2f){textureSize.x / 2,
            textureSize.y / 2});
    sfSprite_setPosition(main_menu->quit.sprite,
        (sfVector2f){world->mode.width / 2, world->mode.height / 1.75});
    sfSprite_setScale(main_menu->quit.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

static int logo(main_menu_t *main_menu, world_t *world)
{
    sfVector2u textureSize;

    main_menu->logo.texture = sfTexture_createFromFile(LOGO, NULL);
    if (!main_menu->logo.texture)
        return FAILURE;
    main_menu->logo.sprite = sfSprite_create();
    sfSprite_setTexture(main_menu->logo.sprite,
        main_menu->logo.texture, sfTrue);
    textureSize = sfTexture_getSize(main_menu->logo.texture);
    sfSprite_setOrigin(main_menu->logo.sprite, (sfVector2f){textureSize.x / 2,
            textureSize.y / 2});
    sfSprite_setPosition(main_menu->logo.sprite,
        (sfVector2f){world->mode.width / 9, world->mode.height / 5});
    sfSprite_setScale(main_menu->logo.sprite, (sfVector2f){0.4, 0.4});
    return SUCCESS;
}

static int cursor(main_menu_t *main_menu)
{
    main_menu->cursor.texture = sfTexture_createFromFile(CURSOR, NULL);
    if (!main_menu->cursor.texture)
        return FAILURE;
    main_menu->cursor.sprite = sfSprite_create();
    sfSprite_setTexture(main_menu->cursor.sprite,
        main_menu->cursor.texture, sfTrue);
    sfSprite_setScale(main_menu->cursor.sprite, (sfVector2f){0.1, 0.1});
    return SUCCESS;
}

int sprite_main(main_menu_t *main_menu, world_t *world)
{
    if (background(main_menu, world) == FAILURE)
        return FAILURE;
    if (start(main_menu, world) == FAILURE)
        return FAILURE;
    if (settings(main_menu, world) == FAILURE)
        return FAILURE;
    if (quit(main_menu, world) == FAILURE)
        return FAILURE;
    if (logo(main_menu, world) == FAILURE)
        return FAILURE;
    if (cursor(main_menu) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
