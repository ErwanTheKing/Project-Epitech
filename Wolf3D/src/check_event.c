/*
** EPITECH PROJECT, 2026
** main
** File description:
** event check
*/

#include "../include/wolf3d.h"

static void check_game_event(sfEvent event, wolf_t *wolf)
{
    if (is_pause_key(wolf->settings, event) ||
        joystick_action_event(wolf->settings, CTRL_PAUSE, event)) {
        wolf->menu_state = 0;
        wolf->state = PAUSE;
    }
    if (isactionpressed(wolf->settings, CTRL_FLASHLIGHT, event))
        wolf->flashlight_on = !wolf->flashlight_on;
}

static void close_inventory(wolf_t *wolf, inv_t *inv)
{
    inv->open = sfFalse;
    sfRenderWindow_setMouseCursorVisible(wolf->window_data->window, sfFalse);
    sfMouse_setPositionRenderWindow((sfVector2i){wolf->window_data->width / 2,
            wolf->window_data->height / 2}, wolf->window_data->window);
    for (int i = 0; i < 8; i++)
        inv->slot[i].selected = sfFalse;
}

static void handle_escape(sfEvent event, wolf_t *wolf)
{
    if (!is_pause_key(wolf->settings, event) &&
        !joystick_action_event(wolf->settings, CTRL_PAUSE, event))
        return;
    if (wolf->state == NEWGAME_MENU) {
        wolf->state = MENU;
        wolf->menu_state = NEWGAME;
        return;
    }
    if (wolf->state == LOBBY)
        back_to_newgame_menu(wolf);
}

static void handle_menu_state_event(wolf_t *wolf, sfEvent event)
{
    if (wolf->state == MENU)
        return manage_menu(wolf, event);
    if (wolf->state == NEWGAME_MENU)
        return manage_newgame_menu(wolf, event);
    if (wolf->state == LOBBY)
        return manage_lobby(wolf, event);
    if (wolf->state == GAME_OVER)
        return manage_game_over(wolf, event);
}

static void handle_game_state_event(wolf_t *wolf, sfEvent event)
{
    sfBool pause = is_pause_key(wolf->settings, event) ||
        joystick_action_event(wolf->settings, CTRL_PAUSE, event);

    if (wolf->state == GAME) {
        if (wolf->game->inv.open && pause)
            return close_inventory(wolf, &wolf->game->inv);
        open_inventory(wolf, event, &wolf->game->inv);
        return check_game_event(event, wolf);
    }
    if (wolf->state == PAUSE)
        return manage_pause(wolf, event);
    if (wolf->state == SETTINGS)
        return manage_settings(wolf, event);
}

void check_event(sfRenderWindow *window, sfEvent event, wolf_t *wolf)
{
    if (event.type == sfEvtClosed || wolf->state == QUIT)
        sfRenderWindow_close(window);
    handle_escape(event, wolf);
    handle_menu_state_event(wolf, event);
    handle_game_state_event(wolf, event);
}
