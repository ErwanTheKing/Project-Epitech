/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Save/load input drawing
*/

#include "../../include/wolf3d.h"

static sfText *new_centered_text(wolf_t *wolf, const char *str,
    float y, unsigned int size)
{
    sfText *text = sfText_create();
    sfFloatRect bounds;

    if (!text)
        return NULL;
    sfText_setFont(text, wolf->data->font);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 1);
    bounds = sfText_getGlobalBounds(text);
    sfText_setPosition(text, (sfVector2f){
            (wolf->window_data->width - bounds.width) / 2.0f, y});
    return text;
}

static void draw_and_free(wolf_t *wolf, sfText *text)
{
    if (!text)
        return;
    sfRenderWindow_drawText(wolf->window_data->window, text, NULL);
    sfText_destroy(text);
}

static const char *get_prompt(save_input_mode_t mode)
{
    if (mode == SAVE_INPUT_SAVE)
        return "Nom de la sauvegarde";
    return "Nom a charger (vide = derniere save)";
}

static void draw_idle_status(wolf_t *wolf)
{
    if (wolf->save_input.status[0] == '\0')
        return;
    draw_and_free(wolf, new_centered_text(wolf, wolf->save_input.status,
            wolf->window_data->height * 0.82f, 28));
}

static void draw_input_name(wolf_t *wolf, float y)
{
    char buffer[128];
    sfText *text = NULL;

    snprintf(buffer, sizeof(buffer), "%.*s_", wolf->save_input.len,
        wolf->save_input.name);
    text = new_centered_text(wolf, buffer, y, 48);
    if (text)
        sfText_setColor(text, sfYellow);
    draw_and_free(wolf, text);
}

static void draw_input_error(wolf_t *wolf, float y)
{
    sfText *text = NULL;

    if (wolf->save_input.status[0] == '\0')
        return;
    text = new_centered_text(wolf, wolf->save_input.status, y, 28);
    if (text)
        sfText_setColor(text, sfRed);
    draw_and_free(wolf, text);
}

void draw_save_input(wolf_t *wolf)
{
    float y = wolf->window_data->height * 0.35f;

    if (wolf->save_input.mode == SAVE_INPUT_NONE)
        return draw_idle_status(wolf);
    draw_and_free(wolf, new_centered_text(wolf,
            get_prompt(wolf->save_input.mode), y, 36));
    draw_input_name(wolf, y + 80.0f);
    draw_input_error(wolf, y + 160.0f);
    draw_and_free(wolf, new_centered_text(wolf,
            "ENTREE pour confirmer  /  ECHAP pour annuler",
            y + 220.0f, 24));
}
