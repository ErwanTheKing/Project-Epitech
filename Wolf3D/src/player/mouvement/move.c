/*
** EPITECH PROJECT, 2026
** main
** File description:
** main
*/

#include "../../../include/wolf3d.h"

static void manage_angle(player_t *player, settings_game_t *settings, float dt)
{
    float rotation_speed = 2.0f;
    float look_x = joystick_axis(sfJoystickU);

    if (sfKeyboard_isKeyPressed(settings->key_bindings[CTRL_TURN_RIGHT]))
        player->angle += rotation_speed * dt;
    if (sfKeyboard_isKeyPressed(settings->key_bindings[CTRL_TURN_LEFT]))
        player->angle -= rotation_speed * dt;
    player->angle += look_x * JOYSTICK_LOOK_SPEED * dt;
}

static void move_forward(sfVector2f *new, move_ctx_t *ctx, float amount)
{
    int sp = ctx->player->speed;

    new->x = ctx->player->x + cosf(ctx->player->angle) *
        (get_speed(ctx->player, sp, sp * 1.1, ctx->settings) / TILE_SIZE) *
        ctx->dt * amount;
    new->y = ctx->player->y + sinf(ctx->player->angle) *
        (get_speed(ctx->player, sp, sp * 1.1, ctx->settings) / TILE_SIZE) *
        ctx->dt * amount;
    if (!check_collision(ctx->wall, new->x, ctx->player->y))
        ctx->player->x = new->x;
    if (!check_collision(ctx->wall, ctx->player->x, new->y))
        ctx->player->y = new->y;
}

static void move_backward(sfVector2f *new, move_ctx_t *ctx, float amount)
{
    new->x = ctx->player->x - cosf(ctx->player->angle) * (100.0 / TILE_SIZE) *
        ctx->dt * amount;
    new->y = ctx->player->y - sinf(ctx->player->angle) * (100.0 / TILE_SIZE) *
        ctx->dt * amount;
    if (!check_collision(ctx->wall, new->x, ctx->player->y))
        ctx->player->x = new->x;
    if (!check_collision(ctx->wall, ctx->player->x, new->y))
        ctx->player->y = new->y;
}

static void move_forward_backward(move_ctx_t *ctx)
{
    float new_x = 0;
    float new_y = 0;
    float move_y = joystick_axis(sfJoystickY);

    if (sfKeyboard_isKeyPressed(ctx->settings->key_bindings[CTRL_FORWARD]))
        move_forward(&(sfVector2f){new_x, new_y}, ctx, 1.0f);
    if (sfKeyboard_isKeyPressed(ctx->settings->key_bindings[CTRL_BACKWARD]))
        move_backward(&(sfVector2f){new_x, new_y}, ctx, 1.0f);
    if (move_y < 0.0f)
        move_forward(&(sfVector2f){new_x, new_y}, ctx, -move_y);
    if (move_y > 0.0f)
        move_backward(&(sfVector2f){new_x, new_y}, ctx, move_y);
}

static void move_left(sfVector2f *new, move_ctx_t *ctx, float amount)
{
    int sp = ctx->player->speed - 40;

    new->x = ctx->player->x + cosf(ctx->player->angle - M_PI / 2) *
        (get_speed(ctx->player, sp, sp / 2, ctx->settings) / TILE_SIZE) *
        ctx->dt * amount;
    new->y = ctx->player->y + sinf(ctx->player->angle - M_PI / 2) *
        (get_speed(ctx->player, sp, sp / 2, ctx->settings) / TILE_SIZE) *
        ctx->dt * amount;
    if (!check_collision(ctx->wall, new->x, ctx->player->y))
        ctx->player->x = new->x;
    if (!check_collision(ctx->wall, ctx->player->x, new->y))
        ctx->player->y = new->y;
}

static void move_right(sfVector2f *new, move_ctx_t *ctx, float amount)
{
    int sp = ctx->player->speed - 40;

    new->x = ctx->player->x + cosf(ctx->player->angle + M_PI / 2) *
        (get_speed(ctx->player, sp, sp / 2, ctx->settings) / TILE_SIZE) *
        ctx->dt * amount;
    new->y = ctx->player->y + sinf(ctx->player->angle + M_PI / 2) *
        (get_speed(ctx->player, sp, sp / 2, ctx->settings) / TILE_SIZE) *
        ctx->dt * amount;
    if (!check_collision(ctx->wall, new->x, ctx->player->y))
        ctx->player->x = new->x;
    if (!check_collision(ctx->wall, ctx->player->x, new->y))
        ctx->player->y = new->y;
}

static void move_side(move_ctx_t *ctx)
{
    float new_x = 0;
    float new_y = 0;
    float move_x = joystick_axis(sfJoystickX);

    if (sfKeyboard_isKeyPressed(ctx->settings->key_bindings[CTRL_LEFT]))
        move_left(&(sfVector2f){new_x, new_y}, ctx, 1.0f);
    if (sfKeyboard_isKeyPressed(ctx->settings->key_bindings[CTRL_RIGHT])) {
        move_right(&(sfVector2f){new_x, new_y}, ctx, 1.0f);
    }
    if (move_x < 0.0f)
        move_left(&(sfVector2f){new_x, new_y}, ctx, -move_x);
    if (move_x > 0.0f)
        move_right(&(sfVector2f){new_x, new_y}, ctx, move_x);
}

void move_player(wolf_t *wolf, player_t *player, sfEvent event, game_t *game)
{
    float dt =
        sfTime_asSeconds(sfClock_getElapsedTime(game->clock[MOVE_CLOCK]));
    move_ctx_t ctx = {0};

    (void)event;
    if (!wolf || !wolf->settings)
        return;
    ctx.wall = game->wall;
    ctx.player = player;
    ctx.settings = wolf->settings;
    ctx.dt = dt;
    sfClock_restart(game->clock[MOVE_CLOCK]);
    move_side(&ctx);
    move_forward_backward(&ctx);
    manage_angle(player, wolf->settings, dt);
}
