/*
** EPITECH PROJECT, 2026
** ~/Epitech/Project/Wolf3d/src/settings
** File description:
** manage_settings
*/

#include "wolf3d.h"

static int in_list_top(char *name)
{
    char *names[] = {"graphics", "audio", "gameplay", "controls",
        "controller", "accessibility"};

    for (int i = 0; i < 6; i++) {
        if (strcmp(name, names[i]) == 0)
            return 0;
    }
    return 84;
}

static void action_button(wolf_t *wolf, char *name, int state)
{
    if (in_list_top(name) == 0) {
        wolf->settings_state = state;
        wolf->rebinding_control_action = -1;
    }
    if (strcmp(name, "back") == 0)
        wolf->state = wolf->return_state;
    if (strcmp(name, "apply") == 0)
        apply_settings(wolf);
    if (strcmp(name, "reset") == 0) {
        wolf->rebinding_control_action = -1;
        reset_settings(wolf);
    }
}

static void click_button(wolf_t *wolf, sfEvent event)
{
    rect_t *rect = NULL;
    sfFloatRect bounds;

    for (list_t *c = wolf->list[SETTINGS][RECT]; c; c = c->next) {
        rect = (rect_t *)c->data;
        bounds = sfRectangleShape_getGlobalBounds(rect->rect);
        if (sfFloatRect_contains(&bounds, event.mouseButton.x,
                event.mouseButton.y)) {
            action_button(wolf, rect->name, rect->state);
            break;
        }
    }
}

static void hover_button(wolf_t *wolf, sfEvent event)
{
    rect_t *rect = NULL;
    sfFloatRect bounds;

    for (list_t *c = wolf->list[SETTINGS][RECT]; c; c = c->next) {
        rect = (rect_t *)c->data;
        bounds = sfRectangleShape_getGlobalBounds(rect->rect);
        if (sfFloatRect_contains(&bounds, event.mouseMove.x,
                event.mouseMove.y) && wolf->settings_state != rect->state)
            sfRectangleShape_setFillColor(rect->rect, sfColor_fromRGBA(255,
                    255, 255, 125));
        else
            sfRectangleShape_setFillColor(rect->rect, sfColor_fromRGBA(255,
                    255, 255, 255));
    }
}

static sfBool handle_settings_back(wolf_t *wolf, sfEvent event)
{
    if (wolf->rebinding_control_action >= 0)
        return sfFalse;
    if (!is_pause_key(wolf->tmp_settings, event) &&
        !joystick_action_event(wolf->tmp_settings, CTRL_PAUSE, event))
        return sfFalse;
    wolf->state = wolf->return_state;
    return sfTrue;
}

static void handle_settings_joystick(wolf_t *wolf, sfEvent event)
{
    if (joystick_menu_right(event) && wolf->settings_state < ACCESSIBILITY)
        wolf->settings_state++;
    if (joystick_menu_left(event) && wolf->settings_state > GRAPHICS)
        wolf->settings_state--;
}

void manage_settings(wolf_t *wolf, sfEvent event)
{
    if (handle_settings_back(wolf, event))
        return;
    if (handle_rebind_key(wolf, event))
        return;
    if (handle_rebind_joystick(wolf, event))
        return;
    if (iskeypressed(sfKeyRight, event) && wolf->settings_state < ACCESSIBILITY)
        wolf->settings_state++;
    if (iskeypressed(sfKeyLeft, event) && wolf->settings_state > GRAPHICS)
        wolf->settings_state--;
    handle_settings_joystick(wolf, event);
    if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft
        && click_controls_value(wolf, event) == sfFalse
        && click_settings_triangle(wolf, event) == sfFalse)
        click_button(wolf, event);
    if (event.type == sfEvtMouseMoved) {
        hover_button(wolf, event);
        hover_settings_triangle(wolf, event);
    }
}
