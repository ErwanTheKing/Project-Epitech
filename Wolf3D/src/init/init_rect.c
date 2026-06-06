/*
** EPITECH PROJECT, 2026
** ~/Epitech/Project/Wolf3d/src/init
** File description:
** init_rectangle
*/

#include "wolf3d.h"

static void set_param(rect_t *rect, sfVector2f *scale, sfVector2f *pos)
{
    sfFloatRect rect_txt;

    sfRectangleShape_setSize(rect->rect, *scale);
    rect_txt = sfRectangleShape_getGlobalBounds(rect->rect);
    sfRectangleShape_setOrigin(rect->rect, (sfVector2f){rect_txt.width / 2,
            0});
    sfRectangleShape_setPosition(rect->rect, *pos);
    sfRectangleShape_setTexture(rect->rect, rect->texture, sfTrue);
}

static int init_rect_assets(rect_t *rect, const char *texture_path)
{
    rect->texture = sfTexture_createFromFile("assets/settings_button.png",
        NULL);
    rect->click_texture = sfTexture_createFromFile(texture_path, NULL);
    return rect->texture && rect->click_texture;
}

static void set_line_style(rect_t *line, sfVector2f *pos, sfVector2f *scale)
{
    sfRectangleShape_setSize(line->rect, (sfVector2f){1.0f, 1.0f});
    sfRectangleShape_setPosition(line->rect, *pos);
    sfRectangleShape_setFillColor(line->rect, sfColor_fromRGB(90, 75, 60));
    sfRectangleShape_setSize(line->rect, *scale);
}

static void free_rect(rect_t *rect)
{
    if (rect->texture)
        sfTexture_destroy(rect->texture);
    if (rect->click_texture)
        sfTexture_destroy(rect->click_texture);
    if (rect->rect)
        sfRectangleShape_destroy(rect->rect);
    free(rect);
}

rect_t *create_rectangles(rect_t *data, const char *texture_path,
    sfVector2f *pos, sfVector2f *scale)
{
    rect_t *rect = calloc(1, sizeof(rect_t));

    if (!rect)
        return NULL;
    rect->rect = sfRectangleShape_create();
    if (!rect->rect) {
        free(rect);
        return NULL;
    }
    rect->name = data->name;
    rect->state = data->state;
    rect->type = data->type;
    rect->always_display = data->always_display;
    if (!rect->name || !init_rect_assets(rect, texture_path)) {
        free_rect(rect);
        return NULL;
    }
    set_param(rect, scale, pos);
    return rect;
}

rect_t *create_line(rect_t *data, sfVector2f *pos, sfVector2f *scale)
{
    rect_t *line = calloc(1, sizeof(rect_t));

    if (!line)
        return NULL;
    line->rect = sfRectangleShape_create();
    if (!line->rect) {
        free(line);
        return NULL;
    }
    line->name = data->name;
    line->state = data->state;
    line->type = data->type;
    line->always_display = data->always_display;
    if (!line->name) {
        free_rect(line);
        return NULL;
    }
    set_line_style(line, pos, scale);
    return line;
}
