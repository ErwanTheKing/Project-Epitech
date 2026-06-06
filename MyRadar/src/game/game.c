/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** The game.c
*/
/**
 * @file game.c
 * @brief The game.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static int verif_add(main_radar_t *radar, int i)
{
    if (radar->file_infos[i][0] == 'A') {
        if (add_plane(&(radar->plane), radar->file_infos[i]) == FAILURE)
            return FAILURE;
    }
    if (radar->file_infos[i][0] == 'T') {
        if (add_tower(&(radar->tower), radar->file_infos[i]) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

static int init(main_radar_t *radar)
{
    radar->plane = NULL;
    radar->tower = NULL;
    radar->disp_hitbox = sfTrue;
    radar->disp_sprite = sfTrue;
    radar->seconds = 0;
    radar->minutes = 0;
    radar->first = 1;
    radar->fps = 0;
    for (int i = 0; radar->file_infos[i] != NULL; i++) {
        if (verif_add(radar, i) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

int create_game(main_radar_t *radar)
{
    if (create_sprite_game(radar) == FAILURE)
        return FAILURE;
    if (create_text_game(radar) == FAILURE)
        return FAILURE;
    if (init(radar) == FAILURE) {
        write(2, "Error with file\n", 16);
        return FAILURE;
    }
    return SUCCESS;
}
