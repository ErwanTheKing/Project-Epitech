/*
** EPITECH PROJECT, 2026
** stage
** File description:
** reset game run
*/

#include "../include/wolf3d.h"
#include <time.h>

static void reset_weapon_state(weapon_t *weapon)
{
    if (!weapon || !weapon->entity)
        return;
    weapon->current_ammo = weapon->max_ammo;
    weapon->reloading = 0;
    weapon->current_frame = 0;
    weapon->rect = (sfIntRect){0, 0, 400, 600};
    sfSprite_setTextureRect(weapon->entity->sprite, weapon->rect);
    sfClock_restart(weapon->cd);
}

static void reset_weapon_base(weapon_t *weapon)
{
    if (!weapon)
        return;
    if (weapon->type == GUN) {
        weapon->max_ammo = 9;
        weapon->damage = 34;
        weapon->attack_speed = 0.7f;
    }
    if (weapon->type == SHOTGUN || weapon->type == VACUUM) {
        weapon->max_ammo = 1;
        weapon->damage = 50;
        weapon->attack_speed = 1.1f;
    }
    reset_weapon_state(weapon);
}

void reset_game_clocks(wolf_t *wolf)
{
    if (!wolf->game)
        return;
    wolf->game->has_shot = 0;
    sfClock_restart(wolf->game->clock[GLOBAL]);
    sfClock_restart(wolf->game->clock[MOVE_CLOCK]);
}

void clear_entity_list(list_t **list)
{
    list_t *next = NULL;

    for (list_t *curr = *list; curr; curr = next) {
        next = curr->next;
        destroy_player((player_t *)curr->data);
        free(curr);
    }
    *list = NULL;
}

static void reset_inventory(inv_t *inv)
{
    for (int i = 0; i < 8; i++) {
        if (inv->item[i].data)
            reset_weapon_base((weapon_t *)inv->item[i].data);
        inv->slot[i].item.data = NULL;
        inv->slot[i].selected = sfFalse;
    }
    inv->slot[0].item = inv->item[0];
    inv->slot[1].item = inv->item[2];
    inv->open = sfFalse;
}

static void reset_entity_lists(wolf_t *wolf)
{
    clear_entity_list(&wolf->list[GAME][MONSTER]);
    clear_entity_list(&wolf->list[GAME][GARBAGE]);
    clear_entity_list(&wolf->list[GAME][HEAL]);
}

static void reset_other_players(wolf_t *wolf)
{
    for (int i = 0; i < MAX_PLAYERS; i++) {
        reset_player_state(&wolf->others[i]);
        wolf->others[i].alive = sfFalse;
    }
    wolf->nb_others = 0;
}

static void reset_run_world(wolf_t *wolf)
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

void reset_inventory_round(inv_t *inv)
{
    weapon_t *weapon;

    for (int i = 0; i < 8; i++) {
        inv->slot[i].selected = sfFalse;
        if (!inv->item[i].data)
            continue;
        weapon = (weapon_t *)inv->item[i].data;
        reset_weapon_state(weapon);
    }
    inv->open = sfFalse;
}

void reset_game_run_seed(wolf_t *wolf, uint32_t seed)
{
    if (!wolf || !wolf->game || !wolf->player)
        return;
    wolf->map_seed = seed;
    reset_entity_lists(wolf);
    reset_player_state(wolf->player);
    printf("DEBUG: Player reset to position (%.2f, %.2f)\n",
        wolf->player->x, wolf->player->y);
    reset_other_players(wolf);
    reset_inventory(&wolf->game->inv);
    reset_run_world(wolf);
    printf("DEBUG: Map created for stage %d\n", wolf->stage);
}
