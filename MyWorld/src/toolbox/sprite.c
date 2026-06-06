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

static int tool(toolbox_t *toolbox, world_t *world)
{
    sfVector2u textureSize;

    toolbox->tool.texture = sfTexture_createFromFile(TOOLBOX, NULL);
    if (!toolbox->tool.texture)
        return FAILURE;
    toolbox->tool.sprite = sfSprite_create();
    sfSprite_setTexture(toolbox->tool.sprite,
        toolbox->tool.texture, sfTrue);
    textureSize = sfTexture_getSize(toolbox->tool.texture);
    sfSprite_setOrigin(toolbox->tool.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(toolbox->tool.sprite,
        (sfVector2f){world->mode.width / 25, world->mode.height / 17});
    sfSprite_setScale(toolbox->tool.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

static int close(toolbox_t *toolbox, world_t *world)
{
    sfVector2u textureSize;

    toolbox->close.texture = sfTexture_createFromFile(CLOSE, NULL);
    if (!toolbox->close.texture)
        return FAILURE;
    toolbox->close.sprite = sfSprite_create();
    sfSprite_setTexture(toolbox->close.sprite,
        toolbox->close.texture, sfTrue);
    textureSize = sfTexture_getSize(toolbox->close.texture);
    sfSprite_setOrigin(toolbox->close.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(toolbox->close.sprite,
        (sfVector2f){world->mode.width / 25, world->mode.height / 17});
    sfSprite_setScale(toolbox->close.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

static int raise(toolbox_t *toolbox, world_t *world)
{
    sfVector2u textureSize;

    toolbox->raise.texture = sfTexture_createFromFile(RAISE, NULL);
    if (!toolbox->raise.texture)
        return FAILURE;
    toolbox->raise.sprite = sfSprite_create();
    sfSprite_setTexture(toolbox->raise.sprite,
        toolbox->raise.texture, sfTrue);
    textureSize = sfTexture_getSize(toolbox->raise.texture);
    sfSprite_setOrigin(toolbox->raise.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(toolbox->raise.sprite,
        (sfVector2f){world->mode.width / 25, world->mode.height / 7});
    sfSprite_setScale(toolbox->raise.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

static int decrease(toolbox_t *toolbox, world_t *world)
{
    sfVector2u textureSize;

    toolbox->decrease.texture = sfTexture_createFromFile(DECREASE, NULL);
    if (!toolbox->decrease.texture)
        return FAILURE;
    toolbox->decrease.sprite = sfSprite_create();
    sfSprite_setTexture(toolbox->decrease.sprite,
        toolbox->decrease.texture, sfTrue);
    textureSize = sfTexture_getSize(toolbox->decrease.texture);
    sfSprite_setOrigin(toolbox->decrease.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(toolbox->decrease.sprite,
        (sfVector2f){world->mode.width / 25, world->mode.height * 0.230});
    sfSprite_setScale(toolbox->decrease.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

static int point(toolbox_t *toolbox, world_t *world)
{
    sfVector2u textureSize;

    toolbox->point.texture = sfTexture_createFromFile(POINT, NULL);
    if (!toolbox->point.texture)
        return FAILURE;
    toolbox->point.sprite = sfSprite_create();
    sfSprite_setTexture(toolbox->point.sprite,
        toolbox->point.texture, sfTrue);
    textureSize = sfTexture_getSize(toolbox->point.texture);
    sfSprite_setOrigin(toolbox->point.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(toolbox->point.sprite,
        (sfVector2f){world->mode.width / 25, world->mode.height * 0.310});
    sfSprite_setScale(toolbox->point.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

static int area(toolbox_t *toolbox, world_t *world)
{
    sfVector2u textureSize;

    toolbox->area.texture = sfTexture_createFromFile(AREA, NULL);
    if (!toolbox->area.texture)
        return FAILURE;
    toolbox->area.sprite = sfSprite_create();
    sfSprite_setTexture(toolbox->area.sprite,
        toolbox->area.texture, sfTrue);
    textureSize = sfTexture_getSize(toolbox->area.texture);
    sfSprite_setOrigin(toolbox->area.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(toolbox->area.sprite,
        (sfVector2f){world->mode.width / 25, world->mode.height * 0.387});
    sfSprite_setScale(toolbox->area.sprite, (sfVector2f){0.7, 0.7});
    return SUCCESS;
}

int sprite_toolbox(toolbox_t *toolbox, world_t *world)
{
    if (tool(toolbox, world) == FAILURE)
        return FAILURE;
    if (close(toolbox, world) == FAILURE)
        return FAILURE;
    if (raise(toolbox, world) == FAILURE)
        return FAILURE;
    if (decrease(toolbox, world) == FAILURE)
        return FAILURE;
    if (point(toolbox, world) == FAILURE)
        return FAILURE;
    if (area(toolbox, world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
