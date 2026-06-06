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

#include <stdio.h>
#include <stdlib.h>
#include "../../lib/my/headers/myworld.h"
#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/my.h"

static int help_text(help_t *help, world_t *world)
{
    sfFloatRect size;

    if (!world->settings.font_num)
        return FAILURE;
    help->help = sfText_create();
    sfText_setFont(help->help, world->settings.font_num);
    sfText_setString(help->help, "Press H for help");
    sfText_setOutlineThickness(help->help, 2);
    sfText_setCharacterSize(help->help, 20);
    size = sfText_getGlobalBounds(help->help);
    sfText_setOrigin(help->help,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(help->help,
        (sfVector2f){world->mode.width / 1.1, world->mode.height / 1.03});
    sfText_setColor(help->help, sfColor_fromRGBA(245, 255, 250, 125));
    return SUCCESS;
}

static int size_area(toolbox_t *toolbox, world_t *world)
{
    sfFloatRect size;
    char *str = my_nbr_to_str(world->map->size);

    if (!str)
        return FAILURE;
    toolbox->size_area = sfText_create();
    sfText_setFont(toolbox->size_area, world->map->toolbox.font);
    sfText_setString(toolbox->size_area, str);
    sfText_setOutlineThickness(toolbox->size_area, 2);
    sfText_setCharacterSize(toolbox->size_area, 60);
    size = sfText_getGlobalBounds(toolbox->size_area);
    sfText_setOrigin(toolbox->size_area,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(toolbox->size_area,
        (sfVector2f){world->mode.width / 23, world->mode.height / 17});
    sfText_setColor(toolbox->size_area, sfColor_fromRGB(165, 253, 254));
    free(str);
    return SUCCESS;
}

int text_game(help_t *help, world_t *world)
{
    if (help_text(help, world) == FAILURE)
        return FAILURE;
    if (text_help(help, world) == FAILURE)
        return FAILURE;
    if (size_area(&world->map->toolbox, world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
