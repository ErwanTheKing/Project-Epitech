/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The text.c
*/
/**
 * @file text.c
 * @brief The text.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"
#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/macros.h"

static int raise(toolbox_t *toolbox, world_t *world)
{
    sfFloatRect size;

    if (!world->settings.font_num)
        return FAILURE;
    toolbox->raise_t = sfText_create();
    sfText_setFont(toolbox->raise_t, world->settings.font_num);
    sfText_setString(toolbox->raise_t, "Raise terrain");
    sfText_setOutlineThickness(toolbox->raise_t, 2);
    sfText_setCharacterSize(toolbox->raise_t, 12);
    size = sfText_getGlobalBounds(toolbox->raise_t);
    sfText_setOrigin(toolbox->raise_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(toolbox->raise_t,
        (sfVector2f){world->mode.width / 25, world->mode.height / 7});
    sfText_setColor(toolbox->raise_t, sfWhite);
    return SUCCESS;
}

static int decrease(toolbox_t *toolbox, world_t *world)
{
    sfFloatRect size;

    toolbox->decrease_t = sfText_create();
    sfText_setFont(toolbox->decrease_t, world->settings.font_num);
    sfText_setString(toolbox->decrease_t, "Lower terrain");
    sfText_setOutlineThickness(toolbox->decrease_t, 2);
    sfText_setCharacterSize(toolbox->decrease_t, 12);
    size = sfText_getGlobalBounds(toolbox->decrease_t);
    sfText_setOrigin(toolbox->decrease_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(toolbox->decrease_t,
        (sfVector2f){world->mode.width / 25, world->mode.height * 0.230});
    sfText_setColor(toolbox->decrease_t, sfWhite);
    return SUCCESS;
}

static int point(toolbox_t *toolbox, world_t *world)
{
    sfFloatRect size;

    toolbox->point_t = sfText_create();
    sfText_setFont(toolbox->point_t, world->settings.font_num);
    sfText_setString(toolbox->point_t, "Edit single point");
    sfText_setOutlineThickness(toolbox->point_t, 2);
    sfText_setCharacterSize(toolbox->point_t, 12);
    size = sfText_getGlobalBounds(toolbox->point_t);
    sfText_setOrigin(toolbox->point_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(toolbox->point_t,
        (sfVector2f){world->mode.width / 25, world->mode.height * 0.310});
    sfText_setColor(toolbox->point_t, sfWhite);
    return SUCCESS;
}

static int area(toolbox_t *toolbox, world_t *world)
{
    sfFloatRect size;

    toolbox->area_t = sfText_create();
    sfText_setFont(toolbox->area_t, world->settings.font_num);
    sfText_setString(toolbox->area_t, "Edit area");
    sfText_setOutlineThickness(toolbox->area_t, 2);
    sfText_setCharacterSize(toolbox->area_t, 12);
    size = sfText_getGlobalBounds(toolbox->area_t);
    sfText_setOrigin(toolbox->area_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(toolbox->area_t,
        (sfVector2f){world->mode.width / 25, world->mode.height * 0.387});
    sfText_setColor(toolbox->area_t, sfWhite);
    return SUCCESS;
}

int text_toolbox(toolbox_t *toolbox, world_t *world)
{
    if (raise(toolbox, world) == FAILURE)
        return FAILURE;
    decrease(toolbox, world);
    point(toolbox, world);
    area(toolbox, world);
    return SUCCESS;
}
