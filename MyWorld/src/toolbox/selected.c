/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The selected.c
*/
/**
 * @file selected.c
 * @brief The selected.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"

static void select_raise(toolbox_t *toolbox)
{
    toolbox->raise_h = sfFalse;
    sfSprite_setColor(toolbox->raise.sprite,
        sfColor_fromRGBA(255, 255, 255, 255));
}

static void select_decrease(toolbox_t *toolbox)
{
    toolbox->decrease_h = sfFalse;
    sfSprite_setColor(toolbox->decrease.sprite,
        sfColor_fromRGBA(255, 255, 255, 255));
}

static void select_point(toolbox_t *toolbox)
{
    toolbox->point_h = sfFalse;
    sfSprite_setColor(toolbox->point.sprite,
        sfColor_fromRGBA(255, 255, 255, 255));
}

static void select_area(toolbox_t *toolbox)
{
    toolbox->area_h = sfFalse;
    sfSprite_setColor(toolbox->area.sprite,
        sfColor_fromRGBA(255, 255, 255, 255));
}

void selected_tool(world_t *world)
{
    if (world->map->toolbox.sens == RAISE_T)
        select_raise(&world->map->toolbox);
    else
        select_decrease(&world->map->toolbox);
    if (world->map->toolbox.size == POINT_T)
        select_point(&world->map->toolbox);
    else
        select_area(&world->map->toolbox);
}
