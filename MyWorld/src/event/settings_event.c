/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The settings_event.c
*/
/**
 * @file settings_event.c
 * @brief The settings_event.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../../lib/my/headers/myworld.h"

static void exec_button(world_t *world)
{
    if (world->event.type == sfEvtKeyPressed
        && sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (world->old_st == GAME_O)
            world->st_game = GAME;
        else
            world->st_game = MAIN;
    }
    if (world->event.type == sfEvtMouseButtonPressed
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        click_back_s(world);
        click_full(world);
        click_vsync(world);
        click_more(world);
        click_less(world);
        if (world->settings.fullscreen == sfFalse)
            click_res(world);
        if (world->settings.vsync == sfFalse)
            click_frame(world);
    }
}

void event_settings(world_t *world)
{
    exec_button(world);
}
