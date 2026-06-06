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

static int background(choose_t *choose, world_t *world)
{
    sfVector2u textureSize;

    choose->background.texture = sfTexture_createFromFile(BACK_CHOOSE, NULL);
    if (!choose->background.texture)
        return FAILURE;
    choose->background.sprite = sfSprite_create();
    sfSprite_setTexture(choose->background.sprite,
        choose->background.texture, sfTrue);
    textureSize = sfTexture_getSize(choose->background.texture);
    sfSprite_setOrigin(choose->background.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(choose->background.sprite,
        (sfVector2f){world->mode.width / 2, world->mode.height / 2});
    sfSprite_setScale(choose->background.sprite, (sfVector2f){1, 1});
    return SUCCESS;
}

static int back(choose_t *choose, world_t *world)
{
    sfVector2u textureSize;

    choose->back.texture = sfTexture_createFromFile(BACK, NULL);
    if (!choose->back.texture)
        return FAILURE;
    choose->back.sprite = sfSprite_create();
    sfSprite_setTexture(choose->back.sprite,
        choose->back.texture, sfTrue);
    textureSize = sfTexture_getSize(choose->back.texture);
    sfSprite_setOrigin(choose->back.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(choose->back.sprite,
        (sfVector2f){world->mode.width / 2, world->mode.height / 1.26});
    sfSprite_setScale(choose->back.sprite, (sfVector2f){0.45, 0.35});
    return SUCCESS;
}

static int create(choose_t *choose, world_t *world)
{
    sfVector2u textureSize;

    choose->create.texture = sfTexture_createFromFile(BACK, NULL);
    if (!choose->create.texture)
        return FAILURE;
    choose->create.sprite = sfSprite_create();
    sfSprite_setTexture(choose->create.sprite,
        choose->create.texture, sfTrue);
    textureSize = sfTexture_getSize(choose->create.texture);
    sfSprite_setOrigin(choose->create.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(choose->create.sprite,
        (sfVector2f){world->mode.width / 2.75, world->mode.height / 1.44});
    sfSprite_setScale(choose->create.sprite, (sfVector2f){0.45, 0.35});
    return SUCCESS;
}

static int load(choose_t *choose, world_t *world)
{
    sfVector2u textureSize;

    choose->load.texture = sfTexture_createFromFile(BACK, NULL);
    if (!choose->load.texture)
        return FAILURE;
    choose->load.sprite = sfSprite_create();
    sfSprite_setTexture(choose->load.sprite,
        choose->load.texture, sfTrue);
    textureSize = sfTexture_getSize(choose->load.texture);
    sfSprite_setOrigin(choose->load.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(choose->load.sprite,
        (sfVector2f){world->mode.width / 1.57, world->mode.height / 1.44});
    sfSprite_setScale(choose->load.sprite, (sfVector2f){0.45, 0.35});
    return SUCCESS;
}

int sprite_choose(choose_t *choose, world_t *world)
{
    if (background(choose, world) == FAILURE)
        return FAILURE;
    if (back(choose, world) == FAILURE)
        return FAILURE;
    if (create(choose, world) == FAILURE)
        return FAILURE;
    if (load(choose, world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
