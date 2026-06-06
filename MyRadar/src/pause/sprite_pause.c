/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** The sprite_main.c
*/
/**
 * @file sprite_main.c
 * @brief The sprite_main.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static int create_background(main_radar_t *radar)
{
    radar->pause.background.texture = sfTexture_createFromFile(BACK_PAUSE,
        NULL);
    if (!radar->pause.background.texture)
        return FAILURE;
    radar->pause.background.sprite = sfSprite_create();
    sfSprite_setTexture(radar->pause.background.sprite,
        radar->pause.background.texture, sfTrue);
    return SUCCESS;
}

static int create_logo(main_radar_t *radar)
{
    radar->pause.logo.texture = sfTexture_createFromFile(LOGO, NULL);
    if (!radar->pause.logo.texture)
        return FAILURE;
    radar->pause.logo.sprite = sfSprite_create();
    sfSprite_setTexture(radar->pause.logo.sprite,
        radar->pause.logo.texture, sfTrue);
    sfSprite_setPosition(radar->pause.logo.sprite,
        (sfVector2f){0.0f, 50.0f});
    return SUCCESS;
}

static int create_overlay_pause(main_radar_t *radar)
{
    radar->pause.over_pause.texture = sfTexture_createFromFile(OVER_PAUSE,
        NULL);
    if (!radar->pause.over_pause.texture)
        return FAILURE;
    radar->pause.over_pause.sprite = sfSprite_create();
    sfSprite_setTexture(radar->pause.over_pause.sprite,
        radar->pause.over_pause.texture, sfTrue);
    sfSprite_setPosition(radar->pause.over_pause.sprite,
        (sfVector2f){600.0f, 50.0f});
    return SUCCESS;
}

int create_sprite_pause(main_radar_t *radar)
{
    if (create_background(radar) == FAILURE || create_logo(radar) == FAILURE)
        return FAILURE;
    if (create_overlay_pause(radar) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
