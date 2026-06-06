/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** network state packets
*/

#include "../include/wolf3d.h"

static int get_network_player_count(wolf_t *wolf)
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

static void start_next_round_when_ready(wolf_t *wolf)
{
    int count = get_network_player_count(wolf);

    if (!network_is_host(wolf))
        return;
    for (int i = 0; i < count; i++) {
        if (!wolf->card_ready[i])
            return;
    }
    reset_round_run(wolf);
    notify_next_round(wolf);
    wolf->state = GAME;
}

void network_handle_start_packet(wolf_t *wolf, network_packet_t *pkt)
{
    window_t *win = wolf->window_data;

    sfMouse_setPositionRenderWindow((sfVector2i){win->width / 2,
            win->height / 2}, win->window);
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    wolf->score = 0;
    wolf->stage = 0;
    reset_game_run_seed(wolf, pkt->timestamp);
    wolf->state = GAME;
}

static sfBool handle_round_state(wolf_t *wolf, network_packet_t *pkt)
{
    if (pkt->data[0] == 'R') {
        wolf->score = 0;
        wolf->stage = 0;
        reset_game_run_seed(wolf, pkt->timestamp);
        wolf->state = GAME;
        return sfTrue;
    }
    if (pkt->data[0] == 'N') {
        reset_round_run_seed(wolf, pkt->timestamp);
        wolf->state = GAME;
        return sfTrue;
    }
    return sfFalse;
}

static sfBool handle_card_state(wolf_t *wolf, network_packet_t *pkt)
{
    if (pkt->data[0] == 'C') {
        wolf->stage++;
        wolf->state = GAME;
        wolf->game->state = CARD;
        memset(wolf->card_ready, 0, sizeof(wolf->card_ready));
        init_card(wolf, &wolf->game->inter);
        return sfTrue;
    }
    if (pkt->data[0] == 'K' && pkt->player_id < MAX_PLAYERS) {
        wolf->card_ready[pkt->player_id] = 1;
        start_next_round_when_ready(wolf);
        return sfTrue;
    }
    return sfFalse;
}

void network_handle_state_packet(wolf_t *wolf, network_packet_t *pkt)
{
    if (handle_round_state(wolf, pkt) || handle_card_state(wolf, pkt))
        return;
    if (pkt->data[0] != 'D' || pkt->player_id >= MAX_PLAYERS)
        return;
    wolf->others[pkt->player_id].alive = sfFalse;
    if (network_is_host(wolf) && are_all_players_dead(wolf)) {
        reset_game_run(wolf);
        notify_game_reset(wolf);
    }
}
