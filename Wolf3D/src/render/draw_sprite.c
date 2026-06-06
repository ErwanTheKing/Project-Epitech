/*
** EPITECH PROJECT, 2026
** draw
** File description:
** decor
*/

#include "../../include/wolf3d.h"

static void draw_inventory(wolf_t *wolf, sfRenderWindow *win, inv_t *inv)
{
    if (wolf->state != GAME || wolf->game->inv.open != sfTrue)
        return;
    sfRenderWindow_drawRectangleShape(win, wolf->game->inv.rect[9], NULL);
    for (int i = 0; i < 9; i++) {
        sfRenderWindow_drawRectangleShape(win,
            wolf->game->inv.rect[i], NULL);
        if (i == 0)
            continue;
        draw_inventory_item(wolf->window_data, &wolf->game->inv, i);
        sfRectangleShape_setFillColor(inv->rect[i], inv->slot[i - 1].selected ?
            (sfColor){200, 50, 50, 150} : sfWhite);
    }
}

void draw_sprite_list(wolf_t *wolf)
{
    entity_t *entity = NULL;
    sfRenderWindow *win = wolf->window_data->window;

    for (list_t *c = wolf->list[wolf->state][SPRITE]; c; c = c->next) {
        entity = (entity_t *)c->data;
        sfRenderWindow_drawSprite(wolf->window_data->window,
            entity->sprite, NULL);
    }
    draw_inventory(wolf, win, &wolf->game->inv);
}

static sfBool draw_menu_text(wolf_t *wolf, text_t *text)
{
    if (text->type != TYPE_MENU)
        return sfFalse;
    if (text->state >= 0)
        sfText_setColor(text->text,
            wolf->menu_state == text->state ? sfRed : sfWhite);
    sfRenderWindow_drawText(wolf->window_data->window, text->text, NULL);
    return sfTrue;
}

void draw_text_list(wolf_t *wolf)
{
    text_t *text = NULL;

    for (list_t *c = wolf->list[wolf->state][TEXT]; c; c = c->next) {
        text = (text_t *)c->data;
        if (draw_menu_text(wolf, text))
            continue;
        if (text->always_display == sfTrue)
            sfRenderWindow_drawText(wolf->window_data->window, text->text,
                NULL);
        if (text->type == TYPE_SETTINGS && wolf->settings_state == text->state)
            sfRenderWindow_drawText(wolf->window_data->window, text->text,
                NULL);
    }
}

static void draw_rect_item(wolf_t *wolf, rect_t *rect)
{
    sfTexture *texture = NULL;

    if (!rect || !rect->rect)
        return;
    sfRectangleShape_setScale(rect->rect, (sfVector2f){1.0f, 1.0f});
    texture = rect->texture;
    if (rect->always_display == sfTrue)
        sfRenderWindow_drawRectangleShape(wolf->window_data->window,
            rect->rect, NULL);
    if (wolf->settings_state == rect->state) {
        sfRectangleShape_setScale(rect->rect, (sfVector2f){1.0f, 1.2f});
        texture = rect->click_texture;
    }
    if (texture)
        sfRectangleShape_setTexture(rect->rect, texture, sfTrue);
    sfRenderWindow_drawRectangleShape(wolf->window_data->window,
        rect->rect, NULL);
}

void draw_rect_list(wolf_t *wolf)
{
    rect_t *rect = NULL;

    for (list_t *c = wolf->list[wolf->state][RECT]; c; c = c->next) {
        rect = (rect_t *)c->data;
        draw_rect_item(wolf, rect);
    }
}

void draw_line_list(wolf_t *wolf)
{
    rect_t *line = NULL;

    for (list_t *c = wolf->list[wolf->state][LINE]; c; c = c->next) {
        line = (rect_t *)c->data;
        if (!(wolf->state == SETTINGS && line->type == TYPE_SETTINGS
                && wolf->settings_state == line->state))
            continue;
        sfRenderWindow_drawRectangleShape(wolf->window_data->window,
            line->rect, NULL);
    }
}

void draw_triangle_list(wolf_t *wolf)
{
    triangle_t *triangle = NULL;

    for (list_t *c = wolf->list[wolf->state][TRIANGLE]; c; c = c->next) {
        triangle = (triangle_t *)c->data;
        if (!(wolf->state == SETTINGS && triangle->type == TYPE_SETTINGS
                && wolf->settings_state == triangle->state))
            continue;
        sfRenderWindow_drawConvexShape(wolf->window_data->window,
            triangle->shape, NULL);
    }
    draw_selected_item(wolf, &wolf->game->inv);
}
