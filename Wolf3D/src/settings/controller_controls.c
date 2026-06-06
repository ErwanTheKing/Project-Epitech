/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Controller controls settings
*/

#include "wolf3d.h"

static const char *get_controller_label(int id)
{
    const char *labels[] = {
        "MOVE FORWARD", "MOVE BACKWARD", "MOVE LEFT", "MOVE RIGHT",
        "TURN LEFT", "TURN RIGHT", "SPRINT", "INVENTORY", "EQUIP / USE",
        "RELOAD", "FLASHLIGHT", "HEAL", "PAUSE", "SLOT 1",
        "SLOT 2", "SLOT 3", "SLOT 4", "SLOT 5", "SLOT 6", "SLOT 7",
        "SLOT 8"
    };

    return labels[id];
}

static const char *get_controller_name(int id)
{
    const char *names[] = {
        "controller_forward_value", "controller_backward_value",
        "controller_left_value", "controller_right_value",
        "controller_turn_left_value", "controller_turn_right_value",
        "controller_sprint_value", "controller_inventory_value",
        "controller_equip_value", "controller_reload_value",
        "controller_flashlight_value", "controller_heal_value",
        "controller_pause_value", "controller_slot_prev_value",
        "controller_slot_next_value", "controller_slot_3_value",
        "controller_slot_4_value", "controller_slot_5_value",
        "controller_slot_6_value", "controller_slot_7_value",
        "controller_slot_8_value"
    };

    return names[id];
}

static text_t *find_controller_text(wolf_t *wolf, const char *name)
{
    text_t *text = NULL;

    for (list_t *c = wolf->list[SETTINGS][TEXT]; c; c = c->next) {
        text = (text_t *)c->data;
        if (text && text->name && strcmp(text->name, name) == 0)
            return text;
    }
    return NULL;
}

static const char *get_controller_value(int id)
{
    const char *values[] = {
        "LEFT STICK UP", "LEFT STICK DOWN", "LEFT STICK LEFT",
        "LEFT STICK RIGHT", "RIGHT STICK LEFT", "RIGHT STICK RIGHT",
        "BUTTON 11", "BUTTON 2", "BUTTON 0", "BUTTON 3", "BUTTON 6",
        "BUTTON 1", "BUTTON 9", "BUTTON 4", "BUTTON 5", "FIXED",
        "FIXED", "FIXED", "FIXED", "FIXED", "FIXED"
    };

    return values[id];
}

void sync_controller_values(wolf_t *wolf, settings_game_t *settings)
{
    text_t *text = NULL;
    char buffer[16];

    if (!wolf || !settings)
        return;
    for (int i = 0; i < CTRL_COUNT; i++) {
        text = find_controller_text(wolf, get_controller_name(i));
        if (!text || !text->text)
            continue;
        if (i < CTRL_SPRINT)
            sfText_setString(text->text, get_controller_value(i));
        else {
            snprintf(buffer, sizeof(buffer), "BUTTON %d",
                settings->joystick_bindings[i]);
            sfText_setString(text->text, buffer);
        }
    }
}

static void add_controller_text(wolf_t *wolf, int i, sfVector2f *pos,
    sfBool is_value)
{
    char *content = is_value ? (char *)get_controller_value(i) :
        (char *)get_controller_label(i);
    char *name = is_value ? (char *)get_controller_name(i) :
        (char *)get_controller_label(i);
    text_t data = {name, content, CONTROLLER, TYPE_SETTINGS, NULL, sfFalse,
        NULL, NULL};

    push_front(&wolf->list[SETTINGS][TEXT],
        create_text(&data, wolf->data->font, pos,
            &(sfVector2f){0.75f, 0.75f}));
}

static void add_controller_line(wolf_t *wolf, window_t *window, int i,
    sfVector2f *pos)
{
    rect_t data = {(char *)get_controller_label(i), CONTROLLER, NULL, NULL,
        NULL, TYPE_SETTINGS, sfFalse};

    push_front(&wolf->list[SETTINGS][LINE],
        create_line(&data, pos, &(sfVector2f){window->width / 3.1f, 1.0f}));
}

static void add_controller_row(wolf_t *wolf, window_t *window, int i, int rows)
{
    float step = (window->height / 1.25f - 88.0f -
        window->height / 3.05f) / (float)(rows - 1);
    float x = window->width / 6.8f + window->width * 0.38f * (i / rows);
    float y = window->height / 3.05f + step * (i % rows);

    if (step > 39.0f)
        step = 39.0f;
    if (step < 29.0f)
        step = 29.0f;
    add_controller_text(wolf, i, &(sfVector2f){x + window->width * 0.22f, y},
        sfTrue);
    add_controller_text(wolf, i, &(sfVector2f){x, y}, sfFalse);
    add_controller_line(wolf, window, i, &(sfVector2f){x - 11, y + 24});
}

void init_controller_controls(wolf_t *wolf, window_t *window)
{
    int rows = (CTRL_COUNT + 1) / 2;

    for (int i = 0; i < CTRL_COUNT; i++)
        add_controller_row(wolf, window, i, rows);
}

int get_controller_action_by_name(const char *name)
{
    if (!name)
        return -1;
    for (int i = CTRL_SPRINT; i <= CTRL_SLOT_2; i++)
        if (strcmp(name, get_controller_name(i)) == 0)
            return i;
    return -1;
}
