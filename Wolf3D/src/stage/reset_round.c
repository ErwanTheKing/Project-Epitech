/*
** EPITECH PROJECT, 2026
** stage
** File description:
** reset round run
*/

#include "../include/wolf3d.h"
#include <time.h>

static uint32_t create_round_seed(wolf_t *wolf)
{
    uint32_t seed = (uint32_t)time(NULL);
    sfInt64 elapsed = 0;

    if (wolf && wolf->game && wolf->game->clock[GLOBAL])
        elapsed = sfClock_getElapsedTime(wolf->game->clock[GLOBAL])
            .microseconds;
    seed ^= (uint32_t)(wolf ? wolf->stage : 0) * 2654435761u;
    seed ^= (uint32_t)elapsed;
    return seed;
}

static void reset_other_players_round(wolf_t *wolf)
{
    for (int i = 0; i < MAX_PLAYERS; i++) {
        reset_player_state(&wolf->others[i]);
        wolf->others[i].alive = sfFalse;
    }
    wolf->nb_others = 0;
}

static void reset_round_world(wolf_t *wolf)
{
    wolf->game->state = STAGE;
    wolf->game->numSprites = 0;
    wolf->game->camera_sway = 0.0f;
    wolf->game->camera_bob = 0.0f;
    wolf->ignore_shot_until_release = sfTrue;
    reset_game_clocks(wolf);
    create_map(wolf, wolf->game->wall);
    sfRenderWindow_setMouseCursorVisible(wolf->window_data->window, sfFalse);
}

void reset_round_run(wolf_t *wolf)
{
    reset_round_run_seed(wolf, create_round_seed(wolf));
}

void reset_round_run_seed(wolf_t *wolf, uint32_t seed)
{
    if (!wolf || !wolf->game || !wolf->player)
        return;
    wolf->map_seed = seed;
    clear_entity_list(&wolf->list[GAME][MONSTER]);
    clear_entity_list(&wolf->list[GAME][GARBAGE]);
    clear_entity_list(&wolf->list[GAME][HEAL]);
    reset_player_round_state(wolf->player);
    reset_other_players_round(wolf);
    reset_inventory_round(&wolf->game->inv);
    memset(wolf->card_ready, 0, sizeof(wolf->card_ready));
    reset_round_world(wolf);
}
