/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Common keyboard and joystick actions
*/

#include "../../include/wolf3d.h"

static sfBool joystick_axis_event(sfEvent event, sfJoystickAxis axis,
    float direction)
{
    float position;

    (void)direction;
    if (event.type != sfEvtJoystickMoved ||
        event.joystickMove.joystickId != JOYSTICK_ID ||
        event.joystickMove.axis != axis)
        return sfFalse;
    position = event.joystickMove.position / 100.0f;
    return position * direction > JOY_TRIGGER_THRESHOLD;
}

sfBool joystick_menu_up(sfEvent event)
{
    return joystick_axis_event(event, sfJoystickPovY, 1.0f) ||
        joystick_axis_event(event, sfJoystickY, -1.0f) ||
        joystick_axis_event(event, sfJoystickV, -1.0f);
}

sfBool joystick_menu_down(sfEvent event)
{
    return joystick_axis_event(event, sfJoystickPovY, -1.0f) ||
        joystick_axis_event(event, sfJoystickY, 1.0f) ||
        joystick_axis_event(event, sfJoystickV, 1.0f);
}

sfBool joystick_menu_left(sfEvent event)
{
    return joystick_axis_event(event, sfJoystickPovX, -1.0f) ||
        joystick_axis_event(event, sfJoystickX, -1.0f) ||
        joystick_axis_event(event, sfJoystickU, -1.0f);
}

sfBool joystick_menu_right(sfEvent event)
{
    return joystick_axis_event(event, sfJoystickPovX, 1.0f) ||
        joystick_axis_event(event, sfJoystickX, 1.0f) ||
        joystick_axis_event(event, sfJoystickU, 1.0f);
}

sfBool joystick_menu_confirm(settings_game_t *settings, sfEvent event)
{
    return joystick_action_event(settings, CTRL_EQUIP, event);
}
