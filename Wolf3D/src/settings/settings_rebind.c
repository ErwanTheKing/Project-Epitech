/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Settings controls rebinding
*/

#include "wolf3d.h"

static sfFloatRect get_control_bounds(text_t *text)
{
    sfFloatRect bounds = sfText_getGlobalBounds(text->text);

    bounds.left -= 25;
    bounds.top -= 12;
    bounds.width += 50;
    bounds.height += 24;
    return bounds;
}

static int get_rebind_action(wolf_t *wolf, text_t *text)
{
    if (wolf->settings_state == CONTROLS)
        return get_control_action_by_name(text->name);
    return get_controller_action_by_name(text->name);
}

static sfBool select_rebind_action(wolf_t *wolf, text_t *text, int action)
{
    wolf->rebinding_control_action = action;
    sfText_setString(text->text, action >= CTRL_COUNT ? "PRESS BUTTON" :
        "PRESS KEY");
    return sfTrue;
}

static sfBool try_click_rebind(wolf_t *wolf, text_t *text, sfEvent event)
{
    sfFloatRect bounds;
    int action = get_rebind_action(wolf, text);

    if (action < 0)
        return sfFalse;
    bounds = get_control_bounds(text);
    if (!sfFloatRect_contains(&bounds, event.mouseButton.x,
            event.mouseButton.y))
        return sfFalse;
    if (wolf->settings_state == CONTROLLER)
        action += CTRL_COUNT;
    return select_rebind_action(wolf, text, action);
}

sfBool click_controls_value(wolf_t *wolf, sfEvent event)
{
    text_t *text = NULL;

    if (wolf->settings_state != CONTROLS && wolf->settings_state != CONTROLLER)
        return sfFalse;
    for (list_t *c = wolf->list[SETTINGS][TEXT]; c; c = c->next) {
        text = (text_t *)c->data;
        if (!text || !text->text || text->state != wolf->settings_state)
            continue;
        if (try_click_rebind(wolf, text, event))
            return sfTrue;
    }
    return sfFalse;
}

sfBool handle_rebind_key(wolf_t *wolf, sfEvent event)
{
    int action = wolf->rebinding_control_action;

    if (event.type != sfEvtKeyPressed || action < 0 || action >= CTRL_COUNT)
        return sfFalse;
    wolf->tmp_settings->key_bindings[action] = event.key.code;
    wolf->rebinding_control_action = -1;
    sync_controls_values(wolf, wolf->tmp_settings);
    return sfTrue;
}

sfBool handle_rebind_joystick(wolf_t *wolf, sfEvent event)
{
    int action = wolf->rebinding_control_action - CTRL_COUNT;

    if (event.type != sfEvtJoystickButtonPressed || action < 0 ||
        action >= CTRL_COUNT)
        return sfFalse;
    wolf->tmp_settings->joystick_bindings[action] = event.joystickButton.button;
    wolf->settings->joystick_bindings[action] = event.joystickButton.button;
    wolf->rebinding_control_action = -1;
    sync_controller_values(wolf, wolf->tmp_settings);
    return sfTrue;
}
