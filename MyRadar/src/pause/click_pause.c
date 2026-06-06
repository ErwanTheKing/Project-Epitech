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

static void touch_resume(main_radar_t *radar)
{
    if (radar->pause.touch_resume == 0) {
        sfMusic_play(radar->sounds.select);
        radar->pause.touch_resume = 1;
    }
}

static void touch_exit(main_radar_t *radar)
{
    if (radar->pause.touch_exit == 0) {
        sfMusic_play(radar->sounds.select);
        radar->pause.touch_exit = 1;
    }
}

void click_exit_pause(main_radar_t *radar)
{
    if (radar->st_pause == QUIT) {
        sfText_setColor(radar->pause.exit,
            sfColor_fromRGB(251, 199, 25));
        sfText_setScale(radar->pause.exit, (sfVector2f){1.2f, 1.2f});
        touch_exit(radar);
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            sfMusic_play(radar->sounds.click);
            radar->st_game = EXIT;
        }
    } else {
        sfText_setColor(radar->pause.exit, sfWhite);
        sfText_setScale(radar->pause.exit, (sfVector2f){1.0f, 1.0f});
        radar->pause.touch_exit = 0;
    }
}

void click_resume_pause(main_radar_t *radar)
{
    if (radar->st_pause == RESUME) {
        sfText_setColor(radar->pause.resume,
            sfColor_fromRGB(251, 199, 25));
        sfText_setScale(radar->pause.resume, (sfVector2f){1.2f, 1.2f});
        touch_resume(radar);
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            sfMusic_play(radar->sounds.click);
            radar->st_game = GAME;
        }
    } else {
        sfText_setColor(radar->pause.resume, sfWhite);
        sfText_setScale(radar->pause.resume, (sfVector2f){1.0f, 1.0f});
        radar->pause.touch_resume = 0;
    }
}
