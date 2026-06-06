/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** The event.c
*/
/**
 * @file event.c
 * @brief The event_basic.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static void event_main(main_radar_t *radar)
{
    click_exit_main(radar);
    click_play_main(radar);
    if (radar->st_main == PLAY && sfKeyboard_isKeyPressed(sfKeyDown))
        radar->st_main = LEAVE;
    if (radar->st_main == LEAVE && sfKeyboard_isKeyPressed(sfKeyUp))
        radar->st_main = PLAY;
}

static void event_pause(main_radar_t *radar)
{
    click_exit_pause(radar);
    click_resume_pause(radar);
    if (radar->st_pause == RESUME && sfKeyboard_isKeyPressed(sfKeyDown))
        radar->st_pause = QUIT;
    if (radar->st_pause == QUIT && sfKeyboard_isKeyPressed(sfKeyUp))
        radar->st_pause = RESUME;
}

static void event_game(main_radar_t *radar)
{
    click_resume_pause(radar);
    if (radar->event.type == sfEvtKeyReleased
        && radar->event.key.code == sfKeyL)
        radar->disp_hitbox = radar->disp_hitbox == sfTrue ? sfFalse : sfTrue;
    if (radar->event.type == sfEvtKeyReleased
        && radar->event.key.code == sfKeyS)
        radar->disp_sprite = radar->disp_sprite == sfTrue ? sfFalse : sfTrue;
}

void event_basic(main_radar_t *radar)
{
    while (sfRenderWindow_pollEvent(radar->window, &radar->event)) {
        if (radar->event.type == sfEvtClosed || radar->st_game == EXIT)
            sfRenderWindow_close(radar->window);
        if (radar->st_game == MAIN)
            event_main(radar);
        if (radar->st_game == PAUSE)
            event_pause(radar);
        if (radar->st_game == GAME)
            event_game(radar);
        if (radar->event.type == sfEvtKeyReleased
            && radar->event.key.code == sfKeyEscape)
            radar->st_game = radar->st_game == GAME ? PAUSE : GAME;
    }
}

void display_state(main_radar_t *radar)
{
    if (radar->st_game == MAIN)
        display_main_menu(radar);
    if (radar->st_game == GAME)
        display_game(radar);
    if (radar->st_game == PAUSE)
        display_pause(radar);
}
