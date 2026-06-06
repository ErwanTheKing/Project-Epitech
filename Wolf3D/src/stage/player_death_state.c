/*
** EPITECH PROJECT, 2026
** stage
** File description:
** multiplayer death state
*/

#include "../include/wolf3d.h"

static sfBool is_multiplayer_game(wolf_t *wolf)
{
    return wolf->connected || wolf->net.player_id != MAX_PLAYERS;
}

static int get_player_count(wolf_t *wolf)
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

sfBool are_all_players_dead(wolf_t *wolf)
{
    int count = 0;

    if (!wolf || !wolf->player)
        return sfFalse;
    count = get_player_count(wolf);
    if (!is_multiplayer_game(wolf))
        return wolf->player->alive == sfFalse ? sfTrue : sfFalse;
    for (int i = 0; i < count; i++) {
        if (i == (int)wolf->net.player_id && wolf->player->alive == sfTrue)
            return sfFalse;
        if (i != (int)wolf->net.player_id && wolf->others[i].alive == sfTrue)
            return sfFalse;
    }
    return sfTrue;
}
