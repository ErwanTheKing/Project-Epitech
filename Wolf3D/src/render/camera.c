/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Camera view effects
*/

#include "../../include/wolf3d.h"

static sfBool is_sprint_moving(wolf_t *wolf, player_t *player)
{
    settings_game_t *settings = wolf->settings;

    if (!player->running)
        return sfFalse;
    if (joystick_axis(sfJoystickY) < 0.0f)
        return sfTrue;
    if (joystick_axis(sfJoystickX) != 0.0f)
        return sfTrue;
    if (sfKeyboard_isKeyPressed(settings->key_bindings[CTRL_FORWARD]))
        return sfTrue;
    if (sfKeyboard_isKeyPressed(settings->key_bindings[CTRL_LEFT]))
        return sfTrue;
    if (sfKeyboard_isKeyPressed(settings->key_bindings[CTRL_RIGHT]))
        return sfTrue;
    return sfFalse;
}

static sfVector2f get_camera_target(wolf_t *wolf, player_t *player)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(
            wolf->game->clock[GLOBAL]));
    sfVector2f target = {0.0f, 0.0f};

    if (!is_sprint_moving(wolf, player))
        return target;
    target.x = sinf(time * CAMERA_SWAY_SPEED) * CAMERA_SWAY_AMOUNT;
    target.y = -fabsf(cosf(time * CAMERA_SWAY_SPEED)) * CAMERA_BOB_AMOUNT;
    return target;
}

static sfView *create_window_view(window_t *win)
{
    return sfView_createFromRect((sfFloatRect){0.0f, 0.0f,
            win->width, win->height});
}

static sfView *create_sway_view(window_t *win)
{
    float width = win->width - CAMERA_SWAY_AMOUNT * 2.0f;
    float height = win->height - CAMERA_BOB_AMOUNT * 3.0f;

    if (width < win->width * 0.8f)
        width = win->width * 0.8f;
    if (height < win->height * 0.8f)
        height = win->height * 0.8f;
    return sfView_createFromRect((sfFloatRect){0.0f, 0.0f,
            width, height});
}

void apply_camera_sway(wolf_t *wolf, player_t *player)
{
    sfVector2f target = get_camera_target(wolf, player);
    sfView *view = create_sway_view(wolf->window_data);
    sfVector2f center = {0.0f, 0.0f};

    if (!view)
        return;
    wolf->game->camera_sway += (target.x - wolf->game->camera_sway)
        * CAMERA_SWAY_SMOOTH;
    wolf->game->camera_bob += (target.y - wolf->game->camera_bob)
        * CAMERA_SWAY_SMOOTH;
    center.x = wolf->window_data->width / 2.0f + wolf->game->camera_sway;
    center.y = wolf->window_data->height / 2.0f + wolf->game->camera_bob;
    sfView_setCenter(view, center);
    sfRenderWindow_setView(wolf->window_data->window, view);
    sfView_destroy(view);
}

void reset_camera_view(wolf_t *wolf)
{
    sfView *view = create_window_view(wolf->window_data);

    if (!view)
        return;
    sfRenderWindow_setView(wolf->window_data->window, view);
    sfView_destroy(view);
}
