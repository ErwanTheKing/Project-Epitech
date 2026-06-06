/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Joystick weapon slot helpers
*/

#include "../../include/wolf3d.h"

sfBool joystick_slot_previous(settings_game_t *settings, sfEvent event)
{
    int button = joystick_bound_button(settings, CTRL_SLOT_1,
        JOY_BTN_SLOT_PREV);

    return event.type == sfEvtJoystickButtonPressed &&
        event.joystickButton.joystickId == JOYSTICK_ID &&
        event.joystickButton.button == (unsigned int)button;
}

sfBool joystick_slot_next(settings_game_t *settings, sfEvent event)
{
    int button = joystick_bound_button(settings, CTRL_SLOT_2,
        JOY_BTN_SLOT_NEXT);

    return event.type == sfEvtJoystickButtonPressed &&
        event.joystickButton.joystickId == JOYSTICK_ID &&
        event.joystickButton.button == (unsigned int)button;
}
