/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The exec.c
*/
/**
 * @file exec.c
 * @brief The exec.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <stdlib.h>

#include "../../lib/my/headers/myworld.h"

void click_back_c(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->choose.back.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->st_game = MAIN;
    }
}

static void click_small(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfCircleShape_getGlobalBounds(world->choose.small);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        sfCircleShape_setPosition(world->choose.selected,
            (sfVector2f){world->mode.width / 3.85, world->mode.height / 2.25});
        world->choose.size = SIZE8;
        world->coords.x = 8;
        world->coords.y = 8;
    }
}

static void click_medium(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfCircleShape_getGlobalBounds(world->choose.medium);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        sfCircleShape_setPosition(world->choose.selected,
            (sfVector2f){world->mode.width / 3.85, world->mode.height / 2.05});
        world->choose.size = SIZE16;
        world->coords.x = 16;
        world->coords.y = 16;
    }
}

static void click_large(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfCircleShape_getGlobalBounds(world->choose.large);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        sfCircleShape_setPosition(world->choose.selected,
            (sfVector2f){world->mode.width / 3.85, world->mode.height / 1.88});
        world->choose.size = SIZE32;
        world->coords.x = 32;
        world->coords.y = 32;
    }
}

static void click_custom(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfCircleShape_getGlobalBounds(world->choose.custom);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        sfCircleShape_setPosition(world->choose.selected,
            (sfVector2f){world->mode.width / 3.85, world->mode.height / 1.74});
        world->choose.size = SIZE0;
    }
}

void click_box(world_t *world, textbox_t *box)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfRectangleShape_getGlobalBounds(box->rectangle);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y))
        box->selected = 1;
    else
        box->selected = 0;
}

void click_size(world_t *world)
{
    click_small(world);
    click_medium(world);
    click_large(world);
    click_custom(world);
}

void click_create(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->choose.create.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        if (world->choose.size == SIZE0)
            get_size_custom(world, world->choose.size_x, world->choose.size_y);
        init_game(world);
        world->st_game = GAME;
        world->old_st = GAME_O;
        world->launch = sfTrue;
    }
}

static void init_load(world_t *world)
{
    world->st_game = GAME;
    world->old_st = GAME_O;
    world->launch = sfTrue;
}

void click_load(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->choose.load.sprite);
    sfVector2u size;
    int selected_index = world->choose.index_selected;

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)
        && selected_index != -1) {
        init_game(world);
        world->choose.index_selected = selected_index;
        free(world->map);
        world->map = load_map(world);
        if (world->map == NULL)
            return;
        size = sfRenderWindow_getSize(world->window);
        center_map(world->map, size.x, size.y);
        init_load(world);
    }
}
