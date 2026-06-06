/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Minimap rendering
*/

#include "../../include/wolf3d.h"
#include <math.h>

static void get_mm_layout(wolf_t *wolf, sfVector2f *origin, float *ts)
{
    float w = (float)wolf->window_data->width;
    float size = w * MINIMAP_SIZE_RATIO;
    float margin = w * MINIMAP_MARGIN;

    *ts = size / MAP_WIDTH;
    origin->x = w - size - margin;
    origin->y = margin;
}

static void draw_mm_row(wolf_t *wolf, sfVector2f *origin, float ts, int y)
{
    hud_t *hud = &wolf->game->hud;
    window_t *win = wolf->window_data;
    sfColor c;
    int x;

    for (x = 0; x < MAP_WIDTH; x++) {
        if (wolf->game->wall->map[y][x] != 0)
            c = (sfColor){160, 160, 185, 215};
        else
            c = (sfColor){22, 22, 36, 180};
        sfRectangleShape_setFillColor(hud->mm_tile, c);
        sfRectangleShape_setSize(hud->mm_tile,
            (sfVector2f){ts - 1.0f, ts - 1.0f});
        sfRectangleShape_setPosition(hud->mm_tile,
            (sfVector2f){origin->x + x * ts, origin->y + y * ts});
        sfRenderWindow_drawRectangleShape(win->window, hud->mm_tile, NULL);
    }
}

static void draw_mm_tiles(wolf_t *wolf, sfVector2f *origin, float ts)
{
    int y;

    for (y = 0; y < MAP_HEIGHT; y++)
        draw_mm_row(wolf, origin, ts, y);
}

static sfColor get_mm_entity_color(int type)
{
    if (type == GARBAGE)
        return (sfColor){50, 220, 80, 230};
    return (sfColor){220, 50, 50, 230};
}

static void draw_mm_entities(wolf_t *wolf, sfVector2f *origin, float ts,
    int type)
{
    hud_t *hud = &wolf->game->hud;
    window_t *win = wolf->window_data;
    player_t *entity;
    list_t *c;
    float dot = ts * 0.5f;
    float ex;
    float ey;

    sfRectangleShape_setFillColor(hud->mm_enemy, get_mm_entity_color(type));
    for (c = wolf->list[GAME][type]; c; c = c->next) {
        entity = (player_t *)c->data;
        if (!entity->alive)
            continue;
        ex = origin->x + entity->x * ts - dot * 0.5f;
        ey = origin->y + entity->y * ts - dot * 0.5f;
        sfRectangleShape_setSize(hud->mm_enemy, (sfVector2f){dot, dot});
        sfRectangleShape_setPosition(hud->mm_enemy, (sfVector2f){ex, ey});
        sfRenderWindow_drawRectangleShape(win->window, hud->mm_enemy, NULL);
    }
}

static void draw_player_dot(wolf_t *wolf, sfVector2f *origin,
    player_t *player, float ts)
{
    hud_t *hud = &wolf->game->hud;
    window_t *win = wolf->window_data;
    float dot = ts * 0.55f;
    float px = origin->x + player->x * ts;
    float py = origin->y + player->y * ts;
    float dx = px + cosf(player->angle) * ts * 1.6f;
    float dy = py + sinf(player->angle) * ts * 1.6f;
    sfVertex dir[2] = {0};

    sfRectangleShape_setSize(hud->mm_player, (sfVector2f){dot, dot});
    sfRectangleShape_setPosition(hud->mm_player,
        (sfVector2f){px - dot * 0.5f, py - dot * 0.5f});
    sfRenderWindow_drawRectangleShape(win->window, hud->mm_player, NULL);
    dir[0].position = (sfVector2f){px, py};
    dir[0].color = sfWhite;
    dir[1].position = (sfVector2f){dx, dy};
    dir[1].color = (sfColor){255, 255, 255, 0};
    sfRenderWindow_drawPrimitives(win->window, dir, 2, sfLines, NULL);
}

void draw_minimap(wolf_t *wolf, player_t *player)
{
    hud_t *hud = &wolf->game->hud;
    window_t *win = wolf->window_data;
    sfVector2f origin;
    float ts;
    float size;

    get_mm_layout(wolf, &origin, &ts);
    size = ts * MAP_WIDTH;
    sfRectangleShape_setSize(hud->mm_bg, (sfVector2f){size, size});
    sfRectangleShape_setPosition(hud->mm_bg, origin);
    sfRenderWindow_drawRectangleShape(win->window, hud->mm_bg, NULL);
    draw_mm_tiles(wolf, &origin, ts);
    draw_mm_entities(wolf, &origin, ts, MONSTER);
    draw_mm_entities(wolf, &origin, ts, GARBAGE);
    draw_player_dot(wolf, &origin, player, ts);
}
