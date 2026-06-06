/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** The effects.c
*/
/**
 * @file effects.c
 * @brief The effects.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static int create_click(main_radar_t *radar)
{
    radar->sounds.click = sfMusic_createFromFile(CLICK);
    if (!radar->sounds.click)
        return FAILURE;
    sfMusic_setVolume(radar->sounds.click, 50);
    return SUCCESS;
}

static int create_select(main_radar_t *radar)
{
    radar->sounds.select = sfMusic_createFromFile(SELECT);
    if (!radar->sounds.select)
        return FAILURE;
    sfMusic_setVolume(radar->sounds.select, 50);
    return SUCCESS;
}

int create_effects(main_radar_t *radar)
{
    if (create_click(radar) == FAILURE)
        return FAILURE;
    if (create_select(radar) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
