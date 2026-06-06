/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The display.c
*/
/**
 * @file display.c
 * @brief The display.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <stdlib.h>

#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/myworld.h"

static void display_sprite(world_t *world)
{
    sfRenderWindow_drawSprite(world->window, world->map->background.sprite,
        NULL);
}

static void text_help_t(world_t *world)
{
    sfRenderWindow_drawText(world->window, world->map->help.help_t, NULL);
    sfRenderWindow_drawText(world->window, world->map->help.toolbox, NULL);
    sfRenderWindow_drawText(world->window, world->map->help.zoom, NULL);
    sfRenderWindow_drawText(world->window, world->map->help.move, NULL);
    sfRenderWindow_drawText(world->window, world->map->help.rotate, NULL);
    sfRenderWindow_drawText(world->window, world->map->help.direction, NULL);
    sfRenderWindow_drawText(world->window, world->map->help.size, NULL);
    sfRenderWindow_drawText(world->window, world->map->help.fullscreen, NULL);
    sfRenderWindow_drawText(world->window, world->map->help.modify_area, NULL);
}

static void update_size_area(world_t *world)
{
    sfFloatRect size;
    char *str = my_nbr_to_str(world->map->size);

    if (!str)
        return;
    sfText_setString(world->map->toolbox.size_area, str);
    size = sfText_getLocalBounds(world->map->toolbox.size_area);
    sfText_setOrigin(world->map->toolbox.size_area,
        (sfVector2f){
            size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(world->map->toolbox.size_area,
        (sfVector2f){world->mode.width / 10,
            world->mode.height / 17});
    sfRenderWindow_drawText(world->window, world->map->toolbox.size_area, NULL);
    free(str);
}

static void display_help(world_t *world)
{
    if (world->map->help_b == sfTrue) {
        sfRenderWindow_drawRectangleShape(world->window,
            world->map->help.rectangle, NULL);
        text_help_t(world);
        sfText_setString(world->map->help.help, "Press H to close help");
    } else {
        sfText_setString(world->map->help.help, "Press H for help");
    }
    sfRenderWindow_drawText(world->window, world->map->help.help, NULL);
}

void display_game(world_t *world)
{
    sfRenderWindow_clear(world->window, sfBlack);
    display_sprite(world);
    draw_map(world->window, world->map);
    display_toolbox(world);
    display_help(world);
    update_size_area(world);
    sfRenderWindow_drawSprite(world->window, world->map->save.sprite,
        NULL);
    display_cursor(world);
}
