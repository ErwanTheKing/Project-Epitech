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
    radar->main.background.texture = sfTexture_createFromFile(BACK_MAIN, NULL);
    if (!radar->main.background.texture)
        return FAILURE;
    radar->main.background.sprite = sfSprite_create();
    sfSprite_setTexture(radar->main.background.sprite,
        radar->main.background.texture, sfTrue);
    return SUCCESS;
}

static int create_logo(main_radar_t *radar)
{
    radar->main.logo.texture = sfTexture_createFromFile(LOGO, NULL);
    if (!radar->main.logo.texture)
        return FAILURE;
    radar->main.logo.sprite = sfSprite_create();
    sfSprite_setTexture(radar->main.logo.sprite,
        radar->main.logo.texture, sfTrue);
    sfSprite_setPosition(radar->main.logo.sprite,
        (sfVector2f){0.0f, 50.0f});
    return SUCCESS;
}

int create_sprite_main(main_radar_t *radar)
{
    if (create_background(radar) == FAILURE || create_logo(radar) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
