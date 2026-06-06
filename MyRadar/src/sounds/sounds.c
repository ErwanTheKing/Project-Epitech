/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** The sounds.c
*/
/**
 * @file sounds.c
 * @brief The sounds.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

int create_sounds(main_radar_t *radar)
{
    if (create_effects(radar) == FAILURE)
        return FAILURE;
    if (create_music(radar) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
