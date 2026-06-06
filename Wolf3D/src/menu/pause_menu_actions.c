/*
** EPITECH PROJECT, 2026
** menu
** File description:
** pause menu actions
*/

#include "../../include/wolf3d.h"
#include <stdio.h>

static void apply_pause_navigation(wolf_t *wolf, const char *name)
{
    if (strcmp(name, "pause_save") == 0) {
        start_save_input(wolf, SAVE_INPUT_SAVE);
        return;
    }
    if (strcmp(name, "pause_settings") == 0) {
        wolf->return_state = PAUSE;
        wolf->state = SETTINGS;
    }
    if (strcmp(name, "pause_main_menu") == 0) {
        wolf->menu_state = NEWGAME;
        wolf->state = MENU;
    }
}

static void apply_pause_game_action(wolf_t *wolf, const char *name)
{
    if (strcmp(name, "pause_restart") == 0) {
        wolf->score = 0;
        wolf->stage = 0;
        reset_game_run(wolf);
        notify_game_reset(wolf);
    }
    if (strcmp(name, "pause_restart") == 0 ||
        strcmp(name, "pause_resume") == 0) {
        wolf->ignore_shot_until_release = sfTrue;
        wolf->state = GAME;
    }
}

void pause_apply_action(wolf_t *wolf, const char *name)
{
    apply_pause_navigation(wolf, name);
    apply_pause_game_action(wolf, name);
    if (strcmp(name, "pause_quit") == 0)
        sfRenderWindow_close(wolf->window_data->window);
}
