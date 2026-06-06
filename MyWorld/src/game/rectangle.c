/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The rectangle.c
*/
/**
 * @file rectangle.c
 * @brief The rectangle.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/myworld.h"

static int back(help_t *help, world_t *world)
{
    help->rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(help->rectangle, (sfVector2f){350, 350});
    sfRectangleShape_setOutlineThickness(help->rectangle, 3);
    sfRectangleShape_setOutlineColor(help->rectangle,
        sfColor_fromRGB(165, 253, 254));
    sfRectangleShape_setFillColor(help->rectangle,
        sfColor_fromRGBA(0, 0, 0, 125));
    sfRectangleShape_setOrigin(help->rectangle, (sfVector2f){175, 175});
    sfRectangleShape_setPosition(help->rectangle,
        (sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2});
    return SUCCESS;
}

int rectangle_help(help_t *help, world_t *world)
{
    back(help, world);
    return SUCCESS;
}
