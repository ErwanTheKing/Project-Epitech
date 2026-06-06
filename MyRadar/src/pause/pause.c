/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** The main_menu.c
*/
/**
 * @file main_menu.c
 * @brief The main_menu.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static void init(main_radar_t *radar)
{
    radar->pause.touch_resume = 0;
    radar->pause.touch_exit = 0;
    radar->escape_pause = sfFalse;
    sfMusic_play(radar->sounds.music);
}

int create_pause(main_radar_t *radar)
{
    if (create_sprite_pause(radar) == FAILURE
        || create_text_pause(radar) == FAILURE)
        return FAILURE;
    init(radar);
    return SUCCESS;
}
