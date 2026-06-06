/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Joystick input helpers
*/

#include "../../include/wolf3d.h"

static sfBool joystick_connected(void)
{
    return sfJoystick_isConnected(JOYSTICK_ID);
}

float joystick_axis(sfJoystickAxis axis)
{
    float position;

    if (!joystick_connected())
        return 0.0f;
    position = sfJoystick_getAxisPosition(JOYSTICK_ID, axis);
    if (fabsf(position) < JOYSTICK_DEADZONE)
        return 0.0f;
    return position / 100.0f;
}

static int default_action_button(control_action_t action)
{
    switch (action) {
        case CTRL_SPRINT:
            return JOY_BTN_LSTICK;
        case CTRL_INVENTORY:
            return JOY_BTN_INVENTORY;
        case CTRL_EQUIP:
            return JOY_BTN_EQUIP;
        case CTRL_HEAL:
            return JOY_BTN_HEAL;
        case CTRL_RELOAD:
            return JOY_BTN_RELOAD;
        case CTRL_FLASHLIGHT:
            return JOY_BTN_FLASHLIGHT;
        case CTRL_PAUSE:
            return JOY_BTN_OPTIONS;
        default:
            return -1;
    }
}

static int action_button(settings_game_t *settings, control_action_t action)
{
    if (action >= CTRL_SLOT_1)
        return -1;
    if (settings && settings->joystick_bindings[action] >= 0)
        return settings->joystick_bindings[action];
    return default_action_button(action);
}

int joystick_bound_button(settings_game_t *settings, control_action_t action,
    int fallback)
{
    if (settings && settings->joystick_bindings[action] >= 0)
        return settings->joystick_bindings[action];
    return fallback;
}

sfBool joystick_action_down(settings_game_t *settings,
    control_action_t action)
{
    int button = action_button(settings, action);

    if (button < 0 || !joystick_connected())
        return sfFalse;
    return sfJoystick_isButtonPressed(JOYSTICK_ID, button);
}

sfBool joystick_action_event(settings_game_t *settings,
    control_action_t action, sfEvent event)
{
    int button = action_button(settings, action);

    return button >= 0 && event.type == sfEvtJoystickButtonPressed &&
        event.joystickButton.joystickId == JOYSTICK_ID &&
        event.joystickButton.button == (unsigned int)button;
}

sfBool joystick_shoot_down(void)
{
    return joystick_connected() &&
        sfJoystick_isButtonPressed(JOYSTICK_ID, JOY_BTN_SHOOT);
}
