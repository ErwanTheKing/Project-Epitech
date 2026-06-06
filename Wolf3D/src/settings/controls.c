/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** controls settings
*/

#include "wolf3d.h"

static const char *get_control_label(int id)
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

static const char *get_control_name(int id)
{
    const char *names[] = {
        "control_forward_value", "control_backward_value",
        "control_left_value", "control_right_value",
        "control_turn_left_value", "control_turn_right_value",
        "control_sprint_value", "control_inventory_value",
        "control_equip_value", "control_reload_value", "control_card_value",
        "control_flashlight_value", "control_heal_value",
        "control_pause_value",
        "control_slot_1_value", "control_slot_2_value",
        "control_slot_3_value", "control_slot_4_value",
        "control_slot_5_value", "control_slot_6_value",
        "control_slot_7_value", "control_slot_8_value"
    };

    return names[id];
}

static text_t *find_settings_text(wolf_t *wolf, const char *name)
{
    text_t *text = NULL;

    for (list_t *c = wolf->list[SETTINGS][TEXT]; c; c = c->next) {
        text = (text_t *)c->data;
        if (text && text->name && strcmp(text->name, name) == 0)
            return text;
    }
    return NULL;
}

void sync_controls_values(wolf_t *wolf, settings_game_t *settings)
{
    text_t *text = NULL;

    if (!wolf || !settings)
        return;
    for (int i = 0; i < CTRL_COUNT; i++) {
        text = find_settings_text(wolf, get_control_name(i));
        if (!text || !text->text)
            continue;
        sfText_setString(text->text, key_to_string(settings->key_bindings[i]));
    }
}

static void add_control_text(wolf_t *wolf, int i, sfVector2f *pos,
    sfBool is_value)
{
    char *name = is_value ? (char *)get_control_name(i) :
        (char *)get_control_label(i);
    char *content = is_value ?
        (char *)key_to_string(wolf->tmp_settings->key_bindings[i]) :
        (char *)get_control_label(i);
    text_t data = {name, content,
        CONTROLS, TYPE_SETTINGS, NULL, sfFalse, NULL, NULL};

    push_front(&wolf->list[SETTINGS][TEXT],
        create_text(&data, wolf->data->font, pos,
            &(sfVector2f){0.75f, 0.75f}));
}

static void add_control_line(wolf_t *wolf, window_t *window, int i,
    sfVector2f *pos)
{
    rect_t data = {(char *)get_control_label(i), CONTROLS, NULL, NULL, NULL,
        TYPE_SETTINGS, sfFalse};

    push_front(&wolf->list[SETTINGS][LINE],
        create_line(&data, pos, &(sfVector2f){window->width / 3.1f, 1.0f}));
}

static float get_control_step(window_t *window, int rows)
{
    float base_y = window->height / 3.05f;
    float bottom_limit = window->height / 1.25f - 88.0f;
    float step = 0.0f;

    if (rows <= 1)
        return 0.0f;
    step = (bottom_limit - base_y) / (float)(rows - 1);
    if (step > 39.0f)
        return 39.0f;
    if (step < 29.0f)
        return 29.0f;
    return step;
}

static void add_control_row(wolf_t *wolf, window_t *window, int i, int rows)
{
    float base_x = window->width / 6.8f;
    float column_width = window->width * 0.38f;
    float base_y = window->height / 3.05f;
    float step = get_control_step(window, rows);
    int column = i / rows;
    int row = i % rows;
    float x = base_x + column_width * column;
    float y = base_y + step * row;
    float value_x = 0;

    value_x = x + window->width * 0.22f;
    add_control_text(wolf, i, &(sfVector2f){value_x, y}, sfTrue);
    add_control_text(wolf, i, &(sfVector2f){x, y}, sfFalse);
    add_control_line(wolf, window, i, &(sfVector2f){x - 11, y + 24});
}

void init_controls(wolf_t *wolf, window_t *window)
{
    int rows = (CTRL_COUNT + 1) / 2;

    for (int i = 0; i < CTRL_COUNT; i++)
        add_control_row(wolf, window, i, rows);
}

int get_control_action_by_name(const char *name)
{
    for (int i = 0; i < CTRL_COUNT; i++)
        if (strcmp(name, get_control_name(i)) == 0)
            return i;
    return -1;
}
