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
    radar->main.touch_play = 0;
    radar->main.touch_exit = 0;
    sfMusic_play(radar->sounds.music);
}

int create_main(main_radar_t *radar)
{
    if (create_sprite_main(radar) == FAILURE
        || create_text_main(radar) == FAILURE)
        return FAILURE;
    init(radar);
    return SUCCESS;
}
