/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Player input action helpers
*/

#include "../../include/wolf3d.h"

sfBool isactiondown(settings_game_t *settings, control_action_t action)
{
    return (settings && sfKeyboard_isKeyPressed(settings->key_bindings[action]))
        || joystick_action_down(settings, action);
}

sfBool isactionpressed(settings_game_t *settings, control_action_t action,
    sfEvent event)
{
    return (settings && iskeypressed(settings->key_bindings[action], event)) ||
        joystick_action_event(settings, action, event);
}
