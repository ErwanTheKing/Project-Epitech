/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** The music.c
*/
/**
 * @file music.c
 * @brief The music.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static int create_music_main(main_radar_t *radar)
{
    radar->sounds.music = sfMusic_createFromFile(MUSIC);
    if (!radar->sounds.music)
        return FAILURE;
    sfMusic_setVolume(radar->sounds.music, 25);
    sfMusic_setLoop(radar->sounds.music, sfTrue);
    return SUCCESS;
}

int create_music(main_radar_t *radar)
{
    if (create_music_main(radar) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
