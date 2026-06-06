/*
** EPITECH PROJECT, 2026
** menu
** File description:
** menu
*/

#include "../../include/wolf3d.h"

sfBool iskeypressed(int key, sfEvent event)
{
    return (event.type == sfEvtKeyPressed && event.key.code == key);
}

static void start_game(wolf_t *wolf)
{
    window_t *win = wolf->window_data;

    sfMouse_setPositionRenderWindow((sfVector2i){win->width / 2,
            win->height / 2}, win->window);
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    wolf->score = 0;
    wolf->stage = 0;
    reset_game_run(wolf);
    wolf->state = GAME;
}

static sfBool menu_confirm(settings_game_t *settings, sfEvent event)
{
    return iskeypressed(sfKeyEnter, event) || joystick_menu_confirm(settings,
        event);
}

static void move_menu_cursor(wolf_t *wolf, sfEvent event, int min, int max)
{
    if ((iskeypressed(sfKeyUp, event) || joystick_menu_up(event)) &&
        wolf->menu_state > min)
        wolf->menu_state -= 1;
    if ((iskeypressed(sfKeyDown, event) || joystick_menu_down(event)) &&
        wolf->menu_state < max)
        wolf->menu_state += 1;
}

void manage_newgame_menu(wolf_t *wolf, sfEvent event)
{
    if (menu_confirm(wolf->settings, event) && wolf->menu_state == SOLO)
        start_game(wolf);
    if (menu_confirm(wolf->settings, event) && wolf->menu_state == MULTI) {
        memset(&wolf->lobby, 0, sizeof(wolf->lobby));
        wolf->net.player_id = MAX_PLAYERS;
        wolf->state = LOBBY;
    }
    move_menu_cursor(wolf, event, SOLO, MULTI);
}

static void apply_menu_action(wolf_t *wolf)
{
    if (wolf->menu_state == NEWGAME) {
        wolf->state = NEWGAME_MENU;
        wolf->menu_state = SOLO;
    }
    if (wolf->menu_state == CONTINUE)
        start_save_input(wolf, SAVE_INPUT_LOAD);
    if (wolf->menu_state == OPTIONS) {
        wolf->return_state = MENU;
        wolf->state = SETTINGS;
    }
    if (wolf->menu_state == LEAVE)
        sfRenderWindow_close(wolf->window_data->window);
}

void manage_menu(wolf_t *wolf, sfEvent event)
{
    if (handle_save_input(wolf, event))
        return;
    if (menu_confirm(wolf->settings, event))
        apply_menu_action(wolf);
    move_menu_cursor(wolf, event, 0, LEAVE);
}

void manage_game_over(wolf_t *wolf, sfEvent event)
{
    if (network_is_host(wolf) && wolf->player->alive == sfFalse &&
        wolf->game && wolf->game->state == STAGE)
        return;
    if (!menu_confirm(wolf->settings, event))
        return;
    wolf->state = MENU;
    wolf->menu_state = NEWGAME;
}
