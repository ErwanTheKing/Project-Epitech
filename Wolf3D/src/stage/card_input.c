/*
** EPITECH PROJECT, 2026
** stage
** File description:
** card input
*/

#include "../include/wolf3d.h"

static void hoover_card(window_t *win, intermission_t *inter)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win->window);
    sfFloatRect rect;
    card_t *c;

    for (int i = 0; i < 3; i++) {
        c = &inter->card[i];
        rect = sfRectangleShape_getGlobalBounds(c->rect);
        if (sfFloatRect_contains(&rect, pos.x, pos.y) && !c->hoover) {
            sfRectangleShape_move(c->rect,
                (sfVector2f){0, -(win->height / 15)});
            c->hoover = sfTrue;
            continue;
        }
        if (!sfFloatRect_contains(&rect, pos.x, pos.y) && c->hoover) {
            sfRectangleShape_move(c->rect,
                (sfVector2f){0, (win->height / 15)});
            c->hoover = sfFalse;
        }
    }
}

static int get_card_player_count(wolf_t *wolf)
{
    int count = wolf->lobby.nb_connected;

    if (count < wolf->nb_others)
        count = wolf->nb_others;
    if (wolf->net.player_id != MAX_PLAYERS &&
        count < (int)wolf->net.player_id + 1)
        count = (int)wolf->net.player_id + 1;
    if (count < 1)
        count = 1;
    if (count > MAX_PLAYERS)
        count = MAX_PLAYERS;
    return count;
}

static sfBool are_cards_ready(wolf_t *wolf)
{
    int count = get_card_player_count(wolf);

    for (int i = 0; i < count; i++) {
        if (!wolf->card_ready[i])
            return sfFalse;
    }
    return sfTrue;
}

static void start_next_round(wolf_t *wolf)
{
    reset_round_run(wolf);
    if (network_is_host(wolf))
        notify_next_round(wolf);
    wolf->game->state = STAGE;
    sfMouse_setPositionRenderWindow((sfVector2i){wolf->window_data->width / 2,
            wolf->window_data->height / 2}, wolf->window_data->window);
    sfRenderWindow_setMouseCursorVisible(wolf->window_data->window, sfFalse);
}

static void after_card_pick(wolf_t *wolf, intermission_t *inter)
{
    if (inter->round == 0) {
        recreate_card_set(wolf, wolf->window_data, inter);
        inter->round = 1;
        inter->done = sfFalse;
        inter->selected = sfFalse;
        sfClock_restart(inter->clock);
        return;
    }
    if (!wolf->connected || wolf->net.player_id == MAX_PLAYERS) {
        reset_round_run(wolf);
        return;
    }
    wolf->card_ready[wolf->net.player_id] = 1;
    notify_card_ready(wolf);
    if (network_is_host(wolf) && are_cards_ready(wolf))
        start_next_round(wolf);
}

static void click_card(wolf_t *wolf, window_t *win, intermission_t *inter)
{
    card_t *card;

    hoover_card(win, inter);
    if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        inter->selected = sfFalse;
        return;
    }
    if (inter->selected)
        return;
    for (int i = 0; i < 3; i++) {
        card = &inter->card[i];
        if (card && card->hoover) {
            inter->selected = sfTrue;
            apply_card(wolf, wolf->player, card);
            return after_card_pick(wolf, inter);
        }
    }
}

static void select_card_by_key(wolf_t *wolf, intermission_t *inter,
    int card_idx)
{
    if (card_idx >= 3 || !inter->done || inter->selected)
        return;
    inter->selected = sfTrue;
    apply_card(wolf, wolf->player, &inter->card[card_idx]);
    after_card_pick(wolf, inter);
}

static void handle_card_joystick(wolf_t *wolf, intermission_t *inter,
    sfEvent event)
{
    int index = hovered_card(inter);
    sfBool pressed = joystick_action_down(wolf->settings, CTRL_EQUIP);

    (void)event;
    if (!pressed) {
        inter->confirm_down = sfFalse;
        return;
    }
    if (inter->confirm_down)
        return;
    inter->confirm_down = sfTrue;
    if (index < 0)
        index = card_under_cursor(wolf, inter);
    if (index >= 0)
        select_card_by_key(wolf, inter, index);
}

void handle_card_input(wolf_t *wolf, intermission_t *inter, sfEvent event)
{
    move_card_cursor(wolf);
    click_card(wolf, wolf->window_data, inter);
    handle_card_joystick(wolf, inter, event);
    if (iskeypressed(sfKeyA, event))
        select_card_by_key(wolf, inter, 0);
    if (iskeypressed(sfKeyC, event))
        select_card_by_key(wolf, inter, 1);
}
