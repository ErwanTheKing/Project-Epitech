/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The hover.c
*/
/**
 * @file hover.c
 * @brief The hover.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"

static void hover_raise(world_t *world, toolbox_t *toolbox)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(toolbox->raise.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        toolbox->raise_h = sfTrue;
        sfRenderWindow_drawText(world->window, toolbox->raise_t, NULL);
        sfSprite_setColor(toolbox->raise.sprite,
            sfColor_fromRGBA(255, 165, 0, 255));
    } else {
        toolbox->raise_h = sfFalse;
        sfSprite_setColor(toolbox->raise.sprite,
            sfColor_fromRGBA(255, 255, 255, 125));
    }
}

static void hover_decrease(world_t *world, toolbox_t *toolbox)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(toolbox->decrease.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        toolbox->decrease_h = sfTrue;
        sfRenderWindow_drawText(world->window, toolbox->decrease_t, NULL);
        sfSprite_setColor(toolbox->decrease.sprite,
            sfColor_fromRGBA(255, 165, 0, 255));
    } else {
        toolbox->decrease_h = sfFalse;
        sfSprite_setColor(toolbox->decrease.sprite,
            sfColor_fromRGBA(255, 255, 255, 125));
    }
}

static void hover_point(world_t *world, toolbox_t *toolbox)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(toolbox->point.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        toolbox->point_h = sfTrue;
        sfRenderWindow_drawText(world->window, toolbox->point_t, NULL);
        sfSprite_setColor(toolbox->point.sprite,
            sfColor_fromRGBA(255, 165, 0, 255));
    } else {
        toolbox->point_h = sfFalse;
        sfSprite_setColor(toolbox->point.sprite,
            sfColor_fromRGBA(255, 255, 255, 125));
    }
}

static void hover_area(world_t *world, toolbox_t *toolbox)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(toolbox->area.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        toolbox->area_h = sfTrue;
        sfSprite_setColor(toolbox->area.sprite,
            sfColor_fromRGBA(255, 165, 0, 255));
    } else {
        toolbox->area_h = sfFalse;
        sfSprite_setColor(toolbox->area.sprite,
            sfColor_fromRGBA(255, 255, 255, 125));
    }
}

void hover(world_t *world)
{
    if (world->map->toolbox.sens == RAISE_T)
        hover_decrease(world, &world->map->toolbox);
    else
        hover_raise(world, &world->map->toolbox);
    if (world->map->toolbox.size == POINT_T)
        hover_area(world, &world->map->toolbox);
    else
        hover_point(world, &world->map->toolbox);
}
