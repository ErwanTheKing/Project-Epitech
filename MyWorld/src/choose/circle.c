/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The circle.c
*/
/**
 * @file circle.c
 * @brief The circle.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"
#include "../../lib/my/headers/defines.h"

static int small(choose_t *choose, world_t *world)
{
    choose->small = sfCircleShape_create();
    sfCircleShape_setOutlineColor(choose->small,
        sfColor_fromRGB(31, 107, 170));
    sfCircleShape_setFillColor(choose->small, sfTransparent);
    sfCircleShape_setOutlineThickness(choose->small, 3);
    sfCircleShape_setRadius(choose->small, 10);
    sfCircleShape_setOrigin(choose->small, (sfVector2f){10, 10});
    sfCircleShape_setPosition(choose->small,
        (sfVector2f){world->mode.width / 3.85, world->mode.height / 2.25});
    return SUCCESS;
}

static int medium(choose_t *choose, world_t *world)
{
    choose->medium = sfCircleShape_create();
    sfCircleShape_setOutlineColor(choose->medium,
        sfColor_fromRGB(31, 107, 170));
    sfCircleShape_setFillColor(choose->medium, sfTransparent);
    sfCircleShape_setOutlineThickness(choose->medium, 3);
    sfCircleShape_setRadius(choose->medium, 10);
    sfCircleShape_setOrigin(choose->medium, (sfVector2f){10, 10});
    sfCircleShape_setPosition(choose->medium,
        (sfVector2f){world->mode.width / 3.85, world->mode.height / 2.05});
    return SUCCESS;
}

static int large(choose_t *choose, world_t *world)
{
    choose->large = sfCircleShape_create();
    sfCircleShape_setOutlineColor(choose->large,
        sfColor_fromRGB(31, 107, 170));
    sfCircleShape_setFillColor(choose->large, sfTransparent);
    sfCircleShape_setOutlineThickness(choose->large, 3);
    sfCircleShape_setRadius(choose->large, 10);
    sfCircleShape_setOrigin(choose->large, (sfVector2f){10, 10});
    sfCircleShape_setPosition(choose->large,
        (sfVector2f){world->mode.width / 3.85, world->mode.height / 1.88});
    return SUCCESS;
}

static int custom(choose_t *choose, world_t *world)
{
    choose->custom = sfCircleShape_create();
    sfCircleShape_setOutlineColor(choose->custom,
        sfColor_fromRGB(31, 107, 170));
    sfCircleShape_setFillColor(choose->custom, sfTransparent);
    sfCircleShape_setOutlineThickness(choose->custom, 3);
    sfCircleShape_setRadius(choose->custom, 10);
    sfCircleShape_setOrigin(choose->custom, (sfVector2f){10, 10});
    sfCircleShape_setPosition(choose->custom,
        (sfVector2f){world->mode.width / 3.85, world->mode.height / 1.74});
    return SUCCESS;
}

static int selected(choose_t *choose, world_t *world)
{
    choose->selected = sfCircleShape_create();
    sfCircleShape_setFillColor(choose->selected,
        sfColor_fromRGB(182, 222, 246));
    sfCircleShape_setRadius(choose->selected, 6);
    sfCircleShape_setOrigin(choose->selected, (sfVector2f){6, 6});
    sfCircleShape_setPosition(choose->selected,
        (sfVector2f){world->mode.width / 3.85, world->mode.height / 2.25});
    return SUCCESS;
}

int circle_choose(choose_t *choose, world_t *world)
{
    small(choose, world);
    medium(choose, world);
    large(choose, world);
    custom(choose, world);
    selected(choose, world);
    return SUCCESS;
}
