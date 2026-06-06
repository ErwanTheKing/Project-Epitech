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

#include "../../lib/my/headers/myworld.h"

void click_tool(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->map->toolbox.tool.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->map->tool = sfTrue;
    }
}

void click_close(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->map->toolbox.close.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->map->tool = sfFalse;
    }
}

static void click_raise(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->map->toolbox.raise.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->map->toolbox.sens = RAISE_T;
    }
}

static void click_decrease(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->map->toolbox.decrease.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->map->toolbox.sens = DECREASE_T;
    }
}

static void click_point(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->map->toolbox.point.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->map->toolbox.size = POINT_T;
    }
}

static void click_area(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->map->toolbox.area.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->map->toolbox.size = AREA_T;
    }
}

void click_toolbox(world_t *world)
{
    click_raise(world);
    click_decrease(world);
    click_point(world);
    click_area(world);
}
