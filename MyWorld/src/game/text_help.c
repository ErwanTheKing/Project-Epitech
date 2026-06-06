/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The text_help.c
*/
/**
 * @file text_help.c
 * @brief The text_help.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"
#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/macros.h"

static int help_short(help_t *help, world_t *world)
{
    sfFloatRect size;

    world->map->toolbox.font = sfFont_createFromFile(FONT_SPECIAL);
    if (!world->map->toolbox.font)
        return FAILURE;
    help->help_t = sfText_create();
    sfText_setFont(help->help_t, world->map->toolbox.font);
    sfText_setString(help->help_t, "H - Open / close help");
    sfText_setOutlineThickness(help->help_t, 2);
    sfText_setCharacterSize(help->help_t, 15);
    size = sfText_getGlobalBounds(help->help_t);
    sfText_setOrigin(help->help_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(help->help_t,
        (sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 - 120});
    sfText_setColor(help->help_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int toolbox(help_t *help, world_t *world)
{
    sfFloatRect size;

    help->toolbox = sfText_create();
    sfText_setFont(help->toolbox, world->map->toolbox.font);
    sfText_setString(help->toolbox, "T - Open / close toolbox");
    sfText_setOutlineThickness(help->toolbox, 2);
    sfText_setCharacterSize(help->toolbox, 15);
    size = sfText_getGlobalBounds(help->toolbox);
    sfText_setOrigin(help->toolbox,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(help->toolbox,
        (sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 - 90});
    sfText_setColor(help->toolbox, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int zoom(help_t *help, world_t *world)
{
    sfFloatRect size;

    help->zoom = sfText_create();
    sfText_setFont(help->zoom, world->map->toolbox.font);
    sfText_setString(help->zoom,
        "Mouse wheel / Touchpad - Zoom in / out");
    sfText_setOutlineThickness(help->zoom, 2);
    sfText_setCharacterSize(help->zoom, 15);
    size = sfText_getGlobalBounds(help->zoom);
    sfText_setOrigin(help->zoom,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(help->zoom,
        (sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 - 60});
    sfText_setColor(help->zoom, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int arrows(help_t *help, world_t *world)
{
    sfFloatRect size;

    help->move = sfText_create();
    sfText_setFont(help->move, world->map->toolbox.font);
    sfText_setString(help->move,
        "Arrow keys - Move camera");
    sfText_setOutlineThickness(help->move, 2);
    sfText_setCharacterSize(help->move, 15);
    size = sfText_getGlobalBounds(help->move);
    sfText_setOrigin(help->move,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(help->move,
        (sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 - 30});
    sfText_setColor(help->move, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int rotate(help_t *help, world_t *world)
{
    sfFloatRect size;

    help->rotate = sfText_create();
    sfText_setFont(help->rotate, world->map->toolbox.font);
    sfText_setString(help->rotate, "ZQSD - Rotate camera");
    sfText_setOutlineThickness(help->rotate, 2);
    sfText_setCharacterSize(help->rotate, 15);
    size = sfText_getGlobalBounds(help->rotate);
    sfText_setOrigin(help->rotate,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(help->rotate,
        (sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2});
    sfText_setColor(help->rotate, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int direction(help_t *help, world_t *world)
{
    sfFloatRect size;

    help->direction = sfText_create();
    sfText_setFont(help->direction, world->map->toolbox.font);
    sfText_setString(help->direction, "J - Change tool direction");
    sfText_setOutlineThickness(help->direction, 2);
    sfText_setCharacterSize(help->direction, 15);
    size = sfText_getGlobalBounds(help->direction);
    sfText_setOrigin(help->direction,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(help->direction,
        (sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 + 30});
    sfText_setColor(help->direction, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int size_tool(help_t *help, world_t *world)
{
    sfFloatRect size;

    help->size = sfText_create();
    sfText_setFont(help->size, world->map->toolbox.font);
    sfText_setString(help->size, "K - Change tool size");
    sfText_setOutlineThickness(help->size, 2);
    sfText_setCharacterSize(help->size, 15);
    size = sfText_getGlobalBounds(help->size);
    sfText_setOrigin(help->size,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(help->size,
        (sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 + 60});
    sfText_setColor(help->size, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int fullcreen(help_t *help, world_t *world)
{
    sfFloatRect size;

    help->fullscreen = sfText_create();
    sfText_setFont(help->fullscreen, world->map->toolbox.font);
    sfText_setString(help->fullscreen, "F11 - Fullscreen");
    sfText_setOutlineThickness(help->fullscreen, 2);
    sfText_setCharacterSize(help->fullscreen, 15);
    size = sfText_getGlobalBounds(help->fullscreen);
    sfText_setOrigin(help->fullscreen,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(help->fullscreen,
        (sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 + 90});
    sfText_setColor(help->fullscreen, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int size_area(help_t *help, world_t *world)
{
    sfFloatRect size;

    help->modify_area = sfText_create();
    sfText_setFont(help->modify_area, world->map->toolbox.font);
    sfText_setString(help->modify_area, "- / + - modify size");
    sfText_setOutlineThickness(help->modify_area, 2);
    sfText_setCharacterSize(help->modify_area, 15);
    size = sfText_getGlobalBounds(help->modify_area);
    sfText_setOrigin(help->modify_area,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(help->modify_area,
        (sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 + 120});
    sfText_setColor(help->modify_area, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

int text_help(help_t *help, world_t *world)
{
    if (help_short(help, world) == FAILURE)
        return FAILURE;
    toolbox(help, world);
    zoom(help, world);
    arrows(help, world);
    rotate(help, world);
    direction(help, world);
    size_tool(help, world);
    fullcreen(help, world);
    size_area(help, world);
    return SUCCESS;
}
