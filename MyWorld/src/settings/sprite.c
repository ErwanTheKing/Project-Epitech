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

#include "../../lib/my/headers/myworld.h"
#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/macros.h"

static int background(settings_t *settings)
{
    sfVector2u textureSize;

    settings->settings.texture = sfTexture_createFromFile(SETTINGS_MENU, NULL);
    if (!settings->settings.texture)
        return FAILURE;
    settings->settings.sprite = sfSprite_create();
    sfSprite_setTexture(settings->settings.sprite,
        settings->settings.texture, sfTrue);
    textureSize = sfTexture_getSize(settings->settings.texture);
    sfSprite_setOrigin(settings->settings.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(settings->settings.sprite,
        (sfVector2f){1920 * 960 / 1920, 1080 * 540 / 1080});
    sfSprite_setScale(settings->settings.sprite, (sfVector2f){1, 1});
    return SUCCESS;
}

static int settings_back_button(settings_t *settings, world_t *world)
{
    sfVector2u textureSize;

    settings->back.texture = sfTexture_createFromFile(BACK, NULL);
    if (!settings->back.texture)
        return FAILURE;
    settings->back.sprite = sfSprite_create();
    sfSprite_setTexture(settings->back.sprite,
        settings->back.texture, sfTrue);
    textureSize = sfTexture_getSize(settings->back.texture);
    sfSprite_setOrigin(settings->back.sprite, (sfVector2f){textureSize.x / 2,
            textureSize.y / 2});
    sfSprite_setPosition(settings->back.sprite,
        (sfVector2f){world->mode.width / 2, world->mode.height * 0.753});
    sfSprite_setScale(settings->back.sprite, (sfVector2f){0.45, 0.45});
    return SUCCESS;
}

static int settings_full_button(settings_t *settings, world_t *world)
{
    sfFloatRect scale;

    settings->full_case.texture = sfTexture_createFromFile(BACK_SQUARE, NULL);
    if (!settings->full_case.texture)
        return FAILURE;
    settings->full_case.sprite = sfSprite_create();
    sfSprite_setTexture(settings->full_case.sprite,
        settings->full_case.texture, sfTrue);
    scale = sfSprite_getGlobalBounds(settings->full_case.sprite);
    sfSprite_setOrigin(settings->full_case.sprite, (sfVector2f){scale.width / 2,
            scale.height / 2});
    sfSprite_setPosition(settings->full_case.sprite,
        (sfVector2f){world->mode.width / 2.74, world->mode.height / 3.08});
    sfSprite_setScale(settings->full_case.sprite,
        (sfVector2f){0.1, 0.1});
    return SUCCESS;
}

static int settings_full_check(settings_t *settings, world_t *world)
{
    sfFloatRect scale;

    settings->full_check.texture = sfTexture_createFromFile(CHECK, NULL);
    if (!settings->full_check.texture)
        return FAILURE;
    settings->full_check.sprite = sfSprite_create();
    sfSprite_setTexture(settings->full_check.sprite,
        settings->full_check.texture, sfTrue);
    scale = sfSprite_getGlobalBounds(settings->full_check.sprite);
    sfSprite_setOrigin(settings->full_check.sprite,
        (sfVector2f){scale.width / 2, scale.height / 2});
    sfSprite_setPosition(settings->full_check.sprite,
        (sfVector2f){world->mode.width / 2.75, world->mode.height / 3.1});
    sfSprite_setScale(settings->full_check.sprite,
        (sfVector2f){0.15, 0.15});
    return SUCCESS;
}

static int settings_vsync_button(settings_t *settings, world_t *world)
{
    sfFloatRect scale;

    settings->vsync_case.texture = sfTexture_createFromFile(BACK_SQUARE, NULL);
    if (!settings->vsync_case.texture)
        return FAILURE;
    settings->vsync_case.sprite = sfSprite_create();
    sfSprite_setTexture(settings->vsync_case.sprite,
        settings->vsync_case.texture, sfTrue);
    scale = sfSprite_getGlobalBounds(settings->vsync_case.sprite);
    sfSprite_setOrigin(settings->vsync_case.sprite,
        (sfVector2f){scale.width / 2, scale.height / 2});
    sfSprite_setPosition(settings->vsync_case.sprite,
        (sfVector2f){world->mode.width / 2.74, world->mode.height / 2.5});
    sfSprite_setScale(settings->vsync_case.sprite,
        (sfVector2f){0.1, 0.1});
    return SUCCESS;
}

static int settings_vsync_check(settings_t *settings, world_t *world)
{
    sfFloatRect scale;

    settings->vsync_check.texture = sfTexture_createFromFile(CHECK, NULL);
    if (!settings->vsync_check.texture)
        return FAILURE;
    settings->vsync_check.sprite = sfSprite_create();
    sfSprite_setTexture(settings->vsync_check.sprite,
        settings->vsync_check.texture, sfTrue);
    scale = sfSprite_getGlobalBounds(settings->vsync_check.sprite);
    sfSprite_setOrigin(settings->vsync_check.sprite,
        (sfVector2f){scale.width / 2, scale.height / 2});
    sfSprite_setPosition(settings->vsync_check.sprite,
        (sfVector2f){world->mode.width / 2.75, world->mode.height / 2.52});
    sfSprite_setScale(settings->vsync_check.sprite,
        (sfVector2f){0.15, 0.15});
    return SUCCESS;
}

static int settings_res_button(settings_t *settings, world_t *world)
{
    sfVector2u textureSize;

    settings->res_case.texture = sfTexture_createFromFile(BACK, NULL);
    if (!settings->res_case.texture)
        return FAILURE;
    settings->res_case.sprite = sfSprite_create();
    sfSprite_setTexture(settings->res_case.sprite,
        settings->res_case.texture, sfTrue);
    textureSize = sfTexture_getSize(settings->res_case.texture);
    sfSprite_setOrigin(settings->res_case.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(settings->res_case.sprite,
        (sfVector2f){world->mode.width / 2.4, world->mode.height / 2.1});
    sfSprite_setScale(settings->res_case.sprite, (sfVector2f){0.35, 0.25});
    return SUCCESS;
}

static int settings_frame_button(settings_t *settings, world_t *world)
{
    sfVector2u textureSize;

    settings->frame_case.texture = sfTexture_createFromFile(BACK, NULL);
    if (!settings->frame_case.texture)
        return FAILURE;
    settings->frame_case.sprite = sfSprite_create();
    sfSprite_setTexture(settings->frame_case.sprite,
        settings->frame_case.texture, sfTrue);
    textureSize = sfTexture_getSize(settings->frame_case.texture);
    sfSprite_setOrigin(settings->frame_case.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(settings->frame_case.sprite,
        (sfVector2f){world->mode.width / 1.72, world->mode.height / 2.1});
    sfSprite_setScale(settings->frame_case.sprite, (sfVector2f){0.35, 0.25});
    return SUCCESS;
}

int sprite_settings(settings_t *settings, world_t *world)
{
    if (background(settings) == FAILURE)
        return FAILURE;
    if (settings_back_button(settings, world) == FAILURE)
        return FAILURE;
    if (settings_full_button(settings, world) == FAILURE)
        return FAILURE;
    if (settings_full_check(settings, world) == FAILURE)
        return FAILURE;
    if (settings_vsync_button(settings, world) == FAILURE)
        return FAILURE;
    if (settings_vsync_check(settings, world) == FAILURE)
        return FAILURE;
    if (settings_res_button(settings, world) == FAILURE)
        return FAILURE;
    if (settings_frame_button(settings, world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
