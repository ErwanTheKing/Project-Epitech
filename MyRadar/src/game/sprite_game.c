/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** The sprite_game.c
*/
/**
 * @file sprite_game.c
 * @brief The sprite_game.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static int create_background(main_radar_t *radar)
{
    radar->game.background.texture = sfTexture_createFromFile(BACK_GAME, NULL);
    if (!radar->game.background.texture)
        return FAILURE;
    radar->game.background.sprite = sfSprite_create();
    sfSprite_setTexture(radar->game.background.sprite,
        radar->game.background.texture, sfTrue);
    return SUCCESS;
}

int create_sprite_game(main_radar_t *radar)
{
    if (create_background(radar) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
