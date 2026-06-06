/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** The click_main.c
*/
/**
 * @file click_main.c
 * @brief The click_main.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static void touch_play(main_radar_t *radar)
{
    if (radar->main.touch_play == 0) {
        sfMusic_play(radar->sounds.select);
        radar->main.touch_play = 1;
    }
}

static void touch_exit(main_radar_t *radar)
{
    if (radar->main.touch_exit == 0) {
        sfMusic_play(radar->sounds.select);
        radar->main.touch_exit = 1;
    }
}

void click_exit_main(main_radar_t *radar)
{
    if (radar->st_main == LEAVE) {
        sfText_setColor(radar->main.exit,
            sfColor_fromRGB(251, 199, 25));
        sfText_setScale(radar->main.exit, (sfVector2f){1.2f, 1.2f});
        touch_exit(radar);
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            sfMusic_play(radar->sounds.click);
            radar->st_game = EXIT;
        }
    } else {
        sfText_setColor(radar->main.exit, sfWhite);
        sfText_setScale(radar->main.exit, (sfVector2f){1.0f, 1.0f});
        radar->main.touch_exit = 0;
    }
}

void click_play_main(main_radar_t *radar)
{
    if (radar->st_main == PLAY) {
        sfText_setColor(radar->main.play,
            sfColor_fromRGB(251, 199, 25));
        sfText_setScale(radar->main.play, (sfVector2f){1.2f, 1.2f});
        touch_play(radar);
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            sfMusic_play(radar->sounds.click);
            radar->st_game = GAME;
        }
    } else {
        sfText_setColor(radar->main.play, sfWhite);
        sfText_setScale(radar->main.play, (sfVector2f){1.0f, 1.0f});
        radar->main.touch_play = 0;
    }
}
