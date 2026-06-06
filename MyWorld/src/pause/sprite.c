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

static int resume(pause_t *pause, world_t *world)
{
    sfVector2u textureSize;

    pause->resume.texture = sfTexture_createFromFile(BACK, NULL);
    if (!pause->resume.texture)
        return FAILURE;
    pause->resume.sprite = sfSprite_create();
    sfSprite_setTexture(pause->resume.sprite,
        pause->resume.texture, sfTrue);
    textureSize = sfTexture_getSize(pause->resume.texture);
    sfSprite_setOrigin(pause->resume.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(pause->resume.sprite,
        (sfVector2f){world->mode.width / 3, world->mode.height / 3});
    sfSprite_setScale(pause->resume.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

static int settings(pause_t *pause, world_t *world)
{
    sfVector2u textureSize;

    pause->settings.texture = sfTexture_createFromFile(BACK, NULL);
    if (!pause->settings.texture)
        return FAILURE;
    pause->settings.sprite = sfSprite_create();
    sfSprite_setTexture(pause->settings.sprite,
        pause->settings.texture, sfTrue);
    textureSize = sfTexture_getSize(pause->settings.texture);
    sfSprite_setOrigin(pause->settings.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(pause->settings.sprite,
        (sfVector2f){world->mode.width / 1.5, world->mode.height / 3});
    sfSprite_setScale(pause->settings.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

static int quit(pause_t *pause, world_t *world)
{
    sfVector2u textureSize;

    pause->quit.texture = sfTexture_createFromFile(BACK, NULL);
    if (!pause->quit.texture)
        return FAILURE;
    pause->quit.sprite = sfSprite_create();
    sfSprite_setTexture(pause->quit.sprite,
        pause->quit.texture, sfTrue);
    textureSize = sfTexture_getSize(pause->quit.texture);
    sfSprite_setOrigin(pause->quit.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(pause->quit.sprite,
        (sfVector2f){world->mode.width / 2, world->mode.height / 1.5});
    sfSprite_setScale(pause->quit.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

static int main_b(pause_t *pause, world_t *world)
{
    sfVector2u textureSize;

    pause->main.texture = sfTexture_createFromFile(BACK, NULL);
    if (!pause->main.texture)
        return FAILURE;
    pause->main.sprite = sfSprite_create();
    sfSprite_setTexture(pause->main.sprite,
        pause->main.texture, sfTrue);
    textureSize = sfTexture_getSize(pause->main.texture);
    sfSprite_setOrigin(pause->main.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(pause->main.sprite,
        (sfVector2f){world->mode.width / 2, world->mode.height / 1.25});
    sfSprite_setScale(pause->main.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

int sprite_pause(pause_t *pause, world_t *world)
{
    if (resume(pause, world) == FAILURE)
        return FAILURE;
    if (settings(pause, world) == FAILURE)
        return FAILURE;
    if (quit(pause, world) == FAILURE)
        return FAILURE;
    if (main_b(pause, world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
