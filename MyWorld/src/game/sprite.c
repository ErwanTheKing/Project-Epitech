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

#include "../../lib/my/headers/myworld.h"
#include "../../lib/my/headers/macros.h"
#include "../../lib/my/headers/defines.h"

static int background(map_t *map)
{
    map->background.texture = sfTexture_createFromFile(BACK_GAME, NULL);
    if (!map->background.texture)
        return FAILURE;
    map->background.sprite = sfSprite_create();
    sfSprite_setTexture(map->background.sprite,
        map->background.texture, sfTrue);
    sfSprite_setScale(map->background.sprite, (sfVector2f){1.3, 1.1});
    return SUCCESS;
}

static int ground(map_t *map)
{
    map->ground.texture = sfTexture_createFromFile(GROUND, NULL);
    if (!map->ground.texture)
        return FAILURE;
    map->ground.sprite = sfSprite_create();
    sfSprite_setTexture(map->ground.sprite,
        map->ground.texture, sfTrue);
    sfSprite_setScale(map->ground.sprite, (sfVector2f){1, 1});
    return SUCCESS;
}

static int mountain(map_t *map)
{
    map->mountain.texture = sfTexture_createFromFile(MOUNTAIN, NULL);
    if (!map->mountain.texture)
        return FAILURE;
    map->mountain.sprite = sfSprite_create();
    sfSprite_setTexture(map->mountain.sprite,
        map->mountain.texture, sfTrue);
    sfSprite_setScale(map->mountain.sprite, (sfVector2f){1, 1});
    return SUCCESS;
}

static int underground(map_t *map)
{
    map->underground.texture = sfTexture_createFromFile(LAVA, NULL);
    if (!map->underground.texture)
        return FAILURE;
    map->underground.sprite = sfSprite_create();
    sfSprite_setTexture(map->underground.sprite,
        map->underground.texture, sfTrue);
    sfSprite_setScale(map->underground.sprite, (sfVector2f){1, 1});
    return SUCCESS;
}

static int save(map_t *map)
{
    sfVector2u textureSize;

    map->save.texture = sfTexture_createFromFile(SAVE, NULL);
    if (!map->save.texture)
        return FAILURE;
    map->save.sprite = sfSprite_create();
    sfSprite_setTexture(map->save.sprite,
        map->save.texture, sfTrue);
    textureSize = sfTexture_getSize(map->save.texture);
    sfSprite_setOrigin(map->save.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(map->save.sprite,
        (sfVector2f){1920 / 14, 1080 / 1.05});
    sfSprite_setScale(map->save.sprite, (sfVector2f){0.2, 0.2});
    return SUCCESS;
}

int sprite_game(map_t *map)
{
    if (background(map) == FAILURE || ground(map) == FAILURE ||
        underground(map) == FAILURE || mountain(map) == FAILURE)
        return FAILURE;
    if (save(map) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
