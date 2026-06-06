/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The main_menu.c
*/
/**
 * @file main_menu.c
 * @brief The main_menu.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"

static void help_resize(help_t *help, world_t *world, float scale)
{
    resize_text(help->move,
        &(sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 - 30},
        (unsigned int)(15 * scale));
    resize_text(help->rotate,
        &(sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2},
        (unsigned int)(15 * scale));
    resize_text(help->direction,
        &(sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 + 30},
        (unsigned int)(15 * scale));
    resize_text(help->size,
        &(sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 + 60},
        (unsigned int)(15 * scale));
    resize_text(help->fullscreen,
        &(sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 + 90},
        (unsigned int)(15 * scale));
    resize_text(help->modify_area,
        &(sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 + 120},
        (unsigned int)(15 * scale));
}

static void text(help_t *help, world_t *world, float scale)
{
    resize_text(help->help,
        &(sfVector2f){world->mode.width / 1.1, world->mode.height / 1.03},
        (unsigned int)(20 * scale));
    resize_text(help->help_t,
        &(sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 - 120},
        (unsigned int)(15 * scale));
    resize_text(help->toolbox,
        &(sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 - 90},
        (unsigned int)(15 * scale));
    resize_text(help->zoom,
        &(sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2 - 60},
        (unsigned int)(15 * scale));
    resize_text(world->map->toolbox.size_area,
        &(sfVector2f){world->mode.width / 10, world->mode.height / 17},
        (unsigned int)(60 * scale));
    help_resize(help, world, scale);
}

static void rectangle(help_t *help, world_t *world, float sclae)
{
    sfRectangleShape_setSize(help->rectangle,
        (sfVector2f){sclae * 350, sclae * 350});
    sfRectangleShape_setOrigin(help->rectangle, (sfVector2f){sclae * 175,
            sclae * 175});
    sfRectangleShape_setPosition(help->rectangle,
        (sfVector2f){world->mode.width / 1.12, world->mode.height / 5.2});
}

void resize_game(map_t *map, world_t *world)
{
    float sx = (float)world->mode.width / 1920.f;
    float sy = (float)world->mode.height / 1080.f;
    float scale = sx < sy ? sx : sy;

    sfSprite_setScale(map->background.sprite,
        (sfVector2f){1.3 * sx, 1.1 * sy});
    text(&map->help, world, scale);
    rectangle(&map->help, world, scale);
    resize_sprite(map->save.sprite,
        &(sfVector2f){world->mode.width / 14, world->mode.height / 1.05},
        &(sfVector2f){0.2 * scale, 0.2 * scale});
}
