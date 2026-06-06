/*
** EPITECH PROJECT, 2026
** stage
** File description:
** reset player state
*/

#include "../include/wolf3d.h"

static void reset_player_clocks(player_t *player)
{
    if (player->ai_clock)
        sfClock_restart(player->ai_clock);
    if (player->attack_clock)
        sfClock_restart(player->attack_clock);
    if (player->damage_clock)
        sfClock_restart(player->damage_clock);
}

void reset_player_state(player_t *player)
{
    player->net_id = PLAYER;
    player->x = 1.5f;
    player->y = 1.5f;
    player->z = 0.0f;
    player->angle = 0.0f;
    player->speed = 100;
    player->max_hp = 100;
    player->hp = 100;
    player->stamina = MAX_STAMINA;
    player->regen_cd = 0.0f;
    player->alive = sfTrue;
    player->running = sfFalse;
    player->took_damage = sfFalse;
    player->weapon = NULL;
    reset_player_clocks(player);
}

void reset_player_round_state(player_t *player)
{
    player->net_id = PLAYER;
    player->x = 1.5f;
    player->y = 1.5f;
    player->z = 0.0f;
    player->angle = 0.0f;
    player->hp = player->max_hp;
    player->stamina = MAX_STAMINA;
    player->regen_cd = 0.0f;
    player->alive = sfTrue;
    player->running = sfFalse;
    player->took_damage = sfFalse;
    reset_player_clocks(player);
}
