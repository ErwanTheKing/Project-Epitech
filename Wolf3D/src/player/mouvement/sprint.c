/*
** EPITECH PROJECT, 2026
** main
** File description:
** main
*/

#include "../../../include/wolf3d.h"

static void drain_stamina(player_t *player, float dt)
{
    player->running = sfTrue;
    player->regen_cd = 1.2f;
    player->stamina -= STAMINA_DRAIN * dt;
    if (player->stamina < 0.0f)
        player->stamina = 0.0f;
}

static void regen_stamina(player_t *player, float dt)
{
    player->running = sfFalse;
    if (player->regen_cd > 0.0f) {
        player->regen_cd -= dt;
        return;
    }
    player->stamina += STAMINA_REGEN * dt;
    if (player->stamina > MAX_STAMINA)
        player->stamina = MAX_STAMINA;
}

void sprint_player(player_t *player, game_t *game, settings_game_t *settings)
{
    float dt;

    dt = sfTime_asSeconds(sfClock_getElapsedTime(game->clock[MOVE_CLOCK]));
    if (isactiondown(settings, CTRL_SPRINT) && player->stamina > 0.0f)
        drain_stamina(player, dt);
    else
        regen_stamina(player, dt);
}

float get_speed(player_t *player, float speed, float accel,
    settings_game_t *settings)
{
    sfBool backward = settings && sfKeyboard_isKeyPressed(
        settings->key_bindings[CTRL_BACKWARD]);

    if ((!settings || (!backward && joystick_axis(sfJoystickY) <= 0.0f)) &&
        player->running)
        return speed + accel;
    return speed;
}
