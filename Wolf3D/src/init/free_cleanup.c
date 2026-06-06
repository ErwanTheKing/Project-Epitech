/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** cleanup
*/

#include "../../include/wolf3d.h"

static void free_rect_drawable(void *data)
{
    rect_t *rect = (rect_t *)data;

    if (!rect)
        return;
    if (rect->rect)
        sfRectangleShape_destroy(rect->rect);
    if (rect->texture)
        sfTexture_destroy(rect->texture);
    if (rect->click_texture)
        sfTexture_destroy(rect->click_texture);
    free(rect);
}

static void free_triangle_drawable(void *data)
{
    triangle_t *triangle = (triangle_t *)data;

    if (!triangle)
        return;
    if (triangle->shape)
        sfConvexShape_destroy(triangle->shape);
    free(triangle);
}

static void free_text_drawable(void *data)
{
    text_t *text = (text_t *)data;

    if (!text)
        return;
    if (text->text)
        sfText_destroy(text->text);
    free(text);
}

static void free_entity_drawable(void *data)
{
    entity_t *entity = (entity_t *)data;

    if (!entity)
        return;
    if (entity->clock)
        sfClock_destroy(entity->clock);
    if (entity->sprite)
        sfSprite_destroy(entity->sprite);
    if (entity->texture)
        sfTexture_destroy(entity->texture);
    free(entity);
}

static void free_line_drawable(void *data)
{
    rect_t *line = (rect_t *)data;

    if (!line)
        return;
    if (line->rect)
        sfRectangleShape_destroy(line->rect);
    free(line);
}

void free_player_list(list_t **list)
{
    list_t *curr = NULL;
    list_t *next = NULL;

    if (!list)
        return;
    curr = *list;
    while (curr) {
        next = curr->next;
        destroy_player((player_t *)curr->data);
        free(curr);
        curr = next;
    }
    *list = NULL;
}

void free_draw_list(wolf_t *wolf, int state, int index)
{
    list_t *curr = NULL;
    list_t *next = NULL;

    if (!wolf)
        return;
    for (curr = wolf->list[state][index]; curr; curr = next) {
        next = curr->next;
        if (index == RECT)
            free_rect_drawable(curr->data);
        if (index == TRIANGLE)
            free_triangle_drawable(curr->data);
        if (index == TEXT)
            free_text_drawable(curr->data);
        if (index == SPRITE)
            free_entity_drawable(curr->data);
        if (index == LINE)
            free_line_drawable(curr->data);
        free(curr);
    }
    wolf->list[state][index] = NULL;
}

static void free_game_wall(game_t *game)
{
    int i = 0;

    if (!game->wall)
        return;
    for (i = 0; i < 2; i++) {
        if (game->wall->text_arr[i])
            free(game->wall->text_arr[i]);
    }
    for (i = 0; i < 6; i++) {
        if (game->wall->decor_arr[i])
            free(game->wall->decor_arr[i]);
    }
    if (game->wall->pixel)
        free(game->wall->pixel);
    if (game->wall->texture)
        sfTexture_destroy(game->wall->texture);
    if (game->wall->sprite)
        sfSprite_destroy(game->wall->sprite);
    free(game->wall);
}

static void free_game_ui(game_t *game)
{
    if (game->zbuffer)
        free(game->zbuffer);
    if (game->crosshair.cursor) {
        if (game->crosshair.cursor->clock)
            sfClock_destroy(game->crosshair.cursor->clock);
        if (game->crosshair.cursor->sprite)
            sfSprite_destroy(game->crosshair.cursor->sprite);
        if (game->crosshair.cursor->texture)
            sfTexture_destroy(game->crosshair.cursor->texture);
        free(game->crosshair.cursor);
    }
    if (game->inter.clock)
        sfClock_destroy(game->inter.clock);
    for (int i = 0; i < 3; i++) {
        if (game->inter.card[i].text)
            sfText_destroy(game->inter.card[i].text);
        if (game->inter.card[i].rect)
            sfRectangleShape_destroy(game->inter.card[i].rect);
    }
}

void free_game(game_t *game)
{
    if (!game)
        return;
    for (int i = 0; i < 2; i++) {
        if (game->clock[i])
            sfClock_destroy(game->clock[i]);
    }
    free_game_wall(game);
    free_game_ui(game);
    free_hud(&game->hud);
    free_inv(&game->inv);
    free(game);
}
