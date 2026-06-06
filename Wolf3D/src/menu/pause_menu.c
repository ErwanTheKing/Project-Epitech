/*
** EPITECH PROJECT, 2026
** menu
** File description:
** pause menu
*/

#include "../../include/wolf3d.h"

void init_pause_buttons(wolf_t *wolf, window_t *window)
{
    char *names[] = {"pause_resume", "pause_settings", "pause_save",
        "pause_restart", "pause_main_menu", "pause_quit"};
    char *contents[] = {"RESUME", "SETTINGS", "SAVE",
        "RESTART", "MAIN MENU", "QUIT"};
    text_t infos[6];
    float start_y = window->height / 2.2f;

    for (int i = 0; i < 6; i++) {
        infos[i] = (text_t){names[i], contents[i], i, TYPE_MENU,
            NULL, sfTrue, NULL, NULL};
        push_front(&wolf->list[PAUSE][TEXT],
            create_text(&infos[i], wolf->data->font,
                &(sfVector2f){window->width / 10.0f, start_y + 90.0f * i},
                &(sfVector2f){1.5f, 1.5f}));
    }
}

void manage_pause(wolf_t *wolf, sfEvent event)
{
    char *actions[] = {"pause_resume", "pause_settings", "pause_save",
        "pause_restart", "pause_main_menu", "pause_quit"};

    if (handle_save_input(wolf, event))
        return;
    if (is_pause_key(wolf->settings, event) ||
        joystick_action_event(wolf->settings, CTRL_PAUSE, event))
        wolf->state = GAME;
    if ((iskeypressed(sfKeyUp, event) || joystick_menu_up(event)) &&
        wolf->menu_state > 0)
        wolf->menu_state -= 1;
    if ((iskeypressed(sfKeyDown, event) || joystick_menu_down(event)) &&
        wolf->menu_state < 5)
        wolf->menu_state += 1;
    if (iskeypressed(sfKeyEnter, event) ||
        joystick_menu_confirm(wolf->settings, event))
        pause_apply_action(wolf, actions[wolf->menu_state]);
}
