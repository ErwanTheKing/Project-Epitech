/*
** EPITECH PROJECT, 2026
** stage
** File description:
** stage
*/

#include "../include/wolf3d.h"
#include <time.h>

static void render_all(wolf_t *wolf, player_t *player, sfEvent event)
{
    (void)event;
    cast_all_rays(wolf, wolf->window_data, player, wolf->game);
    draw_other_entities(wolf, player);
    render_pixels(wolf, wolf->game, wolf->window_data);
}

static void handle_weapon_input(wolf_t *wolf, player_t *player)
{
    if (wolf->ignore_shot_until_release) {
        if (!sfMouse_isButtonPressed(sfMouseLeft) && !joystick_shoot_down())
            wolf->ignore_shot_until_release = sfFalse;
        return;
    }
    use_weapon(&wolf->music, wolf->game, player->weapon, wolf->settings);
}

void stage_action(wolf_t *wolf, player_t *player, sfEvent event)
{
    if (!wolf->game->inv.open) {
        sprint_player(player, wolf->game, wolf->settings);
        move_player(wolf, wolf->player, event, wolf->game);
        handle_weapon_input(wolf, player);
    }
    update_monsters(wolf, player);
    is_near_monster(wolf, player);
    check_game_finish(wolf);
    check_player_state(wolf);
    apply_camera_sway(wolf, player);
    render_all(wolf, player, event);
    draw_weapon(wolf, wolf->window_data, player->weapon);
    reset_camera_view(wolf);
    if (!wolf->game->inv.open)
        use_heal(wolf, player);
    draw_hud(wolf, wolf->window_data, player);
    if (!wolf->game->inv.open)
        draw_crosshair(wolf, wolf->window_data);
}

void stage(wolf_t *wolf, player_t *player, sfEvent event)
{
    switch (wolf->game->state) {
        case STAGE:
            stage_action(wolf, player, event);
            break;
        case CARD:
            card_action(wolf, player, event);
            break;
        default:
            break;
    }
}
