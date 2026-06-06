/*
** EPITECH PROJECT, 2026
** main
** File description:
** main
*/

#include "../../include/wolf3d.h"

static sfBool is_multiplayer_game(wolf_t *wolf)
{
    return wolf->connected || wolf->net.player_id != MAX_PLAYERS;
}

void check_player_state(wolf_t *wolf)
{
    if (wolf->player->hp > 0 || wolf->player->alive == sfFalse)
        return;
    wolf->player->alive = sfFalse;
    wolf->player->hp = 0;
    wolf->player->took_damage = sfFalse;
    notify_player_dead(wolf);
    if (!is_multiplayer_game(wolf) ||
        (network_is_host(wolf) && are_all_players_dead(wolf))) {
        reset_game_run(wolf);
        notify_game_reset(wolf);
    }
    wolf->state = GAME_OVER;
    wolf->menu_state = 0;
    sfRenderWindow_setMouseCursorVisible(wolf->window_data->window, sfTrue);
}
