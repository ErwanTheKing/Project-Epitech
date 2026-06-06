/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** program loop
*/

#include "../include/wolf3d.h"

static void check_settings_state(wolf_t *wolf)
{
    sfRenderWindow_setMouseCursorVisible(wolf->window_data->window, sfTrue);
    settings(wolf);
}

static void update_dead_host_round(wolf_t *wolf)
{
    if (!network_is_host(wolf) || wolf->state != GAME_OVER ||
        !wolf->game || wolf->game->state != STAGE)
        return;
    update_monsters(wolf, wolf->player);
    is_near_monster(wolf, wolf->player);
    check_game_finish(wolf);
}

static void check_state(wolf_t *wolf, sfEvent event)
{
    if (wolf->state == MENU || wolf->state == NEWGAME_MENU ||
        wolf->state == LOBBY || wolf->state == GAME_OVER) {
        update_dead_host_round(wolf);
        menu(wolf);
        return;
    }
    if (wolf->state == GAME) {
        sfRenderWindow_setMouseCursorVisible(wolf->window_data->window,
            wolf->game && (wolf->game->inv.open || wolf->game->state == CARD)
            ? sfTrue : sfFalse);
        stage(wolf, wolf->player, event);
        return;
    }
    if (wolf->state == PAUSE)
        sfRenderWindow_setMouseCursorVisible(wolf->window_data->window, sfTrue);
    if (wolf->state == SETTINGS)
        check_settings_state(wolf);
}

static void manage_draw(wolf_t *wolf)
{
    draw_sprite_list(wolf);
    draw_rect_list(wolf);
    draw_text_list(wolf);
    if (wolf->settings && wolf->settings->show_fps)
        draw_fps(wolf);
    draw_line_list(wolf);
    draw_triangle_list(wolf);
    if (wolf->state == LOBBY)
        draw_lobby(wolf);
    draw_save_input(wolf);
}

static void run_loop(wolf_t *wolf, sfClock *send_clock)
{
    sfEvent event;
    sfRenderWindow *current_window = NULL;

    while (sfRenderWindow_isOpen(wolf->window_data->window)) {
        handle_window_recreate(wolf);
        current_window = wolf->window_data->window;
        sfRenderWindow_clear(current_window, sfBlack);
        while (sfRenderWindow_pollEvent(current_window, &event))
            check_event(current_window, event, wolf);
        network_update(wolf, send_clock);
        check_state(wolf, event);
        manage_draw(wolf);
        sfRenderWindow_display(current_window);
    }
}

int program(sfRenderWindow *window, sfEvent event, wolf_t *wolf)
{
    sfClock *send_clock = sfClock_create();

    if (!send_clock)
        return 84;
    (void)window;
    (void)event;
    run_loop(wolf, send_clock);
    sfClock_destroy(send_clock);
    return 0;
}
