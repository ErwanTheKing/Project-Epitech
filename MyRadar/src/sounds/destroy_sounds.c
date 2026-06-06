/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** The destroy_sounds.c
*/
/**
 * @file destroy_sounds.c
 * @brief The destroy_sounds.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static void destroy_effects(main_radar_t *radar)
{
    sfMusic_destroy(radar->sounds.click);
    sfMusic_destroy(radar->sounds.select);
}

static void destroy_music(main_radar_t *radar)
{
    sfMusic_destroy(radar->sounds.music);
}

void destroy_sounds(main_radar_t *radar)
{
    destroy_effects(radar);
    destroy_music(radar);
}
