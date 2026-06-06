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

#include <stdio.h>

#include "../../lib/my/headers/myworld.h"

static void sprite(choose_t *choose, world_t *world, float sx, float sy)
{
    resize_sprite(choose->background.sprite,
        &(sfVector2f){world->mode.width / 2, world->mode.height / 2},
        &(sfVector2f){sx, sy});
    resize_sprite(choose->back.sprite,
        &(sfVector2f){world->mode.width / 2, world->mode.height / 1.26},
        &(sfVector2f){0.45 * sx, 0.35 * sy});
    resize_sprite(choose->create.sprite,
        &(sfVector2f){world->mode.width / 2.75, world->mode.height / 1.44},
        &(sfVector2f){0.45 * sx, 0.35 * sy});
    resize_sprite(choose->load.sprite,
        &(sfVector2f){world->mode.width / 1.57, world->mode.height / 1.44},
        &(sfVector2f){0.45 * sx, 0.35 * sy});
}

static void text(choose_t *choose, world_t *world, float scale)
{
    resize_text(choose->back_t,
        &(sfVector2f){world->mode.width / 2, world->mode.height / 1.26},
        (unsigned int)(60.f * scale));
    resize_text(choose->create_t,
        &(sfVector2f){world->mode.width / 2.75, world->mode.height / 1.44},
        (unsigned int)(60.f * scale));
    resize_text(choose->load_t,
        &(sfVector2f){world->mode.width / 1.57, world->mode.height / 1.44},
        (unsigned int)(60.f * scale));
    resize_text(choose->x_t,
        &(sfVector2f){world->mode.width / 2.685, world->mode.height / 1.65},
        (unsigned int)(50.f * scale));
}

static void size_text(choose_t *choose, world_t *world, float scale)
{
    resize_text(choose->small_t,
        &(sfVector2f){world->mode.width / 3.3, world->mode.height / 2.25},
        (unsigned int)(18.f * scale));
    resize_text(choose->medium_t,
        &(sfVector2f){world->mode.width / 3.2, world->mode.height / 2.05},
        (unsigned int)(18.f * scale));
    resize_text(choose->large_t,
        &(sfVector2f){world->mode.width / 3.2, world->mode.height / 1.88},
        (unsigned int)(18.f * scale));
    resize_text(choose->custom_t,
        &(sfVector2f){world->mode.width / 3.4, world->mode.height / 1.74},
        (unsigned int)(18.f * scale));
}

static void textbox_resize(choose_t *choose, world_t *world, float scale)
{
    sfVector2f posX = {world->mode.width / 2.9, world->mode.height / 1.65};
    sfVector2f posY = {world->mode.width / 2.5, world->mode.height / 1.65};
    sfVector2f pos = {world->mode.width / 2.8, world->mode.height / 2.75};
    sfVector2f sizeX = {60 * scale, 50 * scale};
    sfVector2f sizeY = {60 * scale, 50 * scale};
    sfVector2f size = {350 * scale, 70 * scale};

    resize_textbox(choose->size_x, &posX, &sizeX, 25 * scale);
    resize_textbox(choose->size_y, &posY, &sizeY, 25 * scale);
    resize_textbox(choose->name, &pos, &size, 25 * scale);
}

static sfVector2f position(choose_t *choose)
{
    sfVector2f pos = {3.85, 0};

    switch (choose->size) {
        case SIZE8:
            pos.y = 2.25;
            break;
        case SIZE16:
            pos.y = 2.05;
            break;
        case SIZE32:
            pos.y = 1.88;
            break;
        case SIZE0:
            pos.y = 1.74;
            break;
    }
    return pos;
}

static void circle(choose_t *choose, world_t *world, float scale)
{
    sfVector2f pos = position(choose);

    resize_circle(choose->small,
        &(sfVector2f){world->mode.width / 3.85, world->mode.height / 2.25},
        10 * scale);
    resize_circle(choose->medium,
        &(sfVector2f){world->mode.width / 3.85, world->mode.height / 2.05},
        10 * scale);
    resize_circle(choose->large,
        &(sfVector2f){world->mode.width / 3.85, world->mode.height / 1.88},
        10 * scale);
    resize_circle(choose->custom,
        &(sfVector2f){world->mode.width / 3.85, world->mode.height / 1.74},
        10 * scale);
    resize_circle(choose->selected,
        &(sfVector2f){world->mode.width / pos.x, world->mode.height / pos.y},
        6 * scale);
}

static void maps(world_t *world, map_entry_t *maps, float scale)
{
    for (int i = 0; i < world->choose.len; i++) {
        resize_text(maps[i].text,
            &(sfVector2f){world->mode.width / 1.57,
                world->mode.height / 3 + i * 70},
            (unsigned int)(35 * scale));
        sfRectangleShape_setSize(maps[i].rectangle,
            (sfVector2f){scale * 450, scale * 50});
        sfRectangleShape_setOrigin(maps[i].rectangle, (sfVector2f){scale * 225,
                scale * 25});
        sfRectangleShape_setPosition(maps[i].rectangle,
            (sfVector2f){world->mode.width / 1.57,
                world->mode.height / 3 + i * 70});
    }
}

void resize_choose(choose_t *choose, world_t *world)
{
    float sx = (float)world->mode.width / 1920.f;
    float sy = (float)world->mode.height / 1080.f;
    float scale = sx < sy ? sx : sy;

    sprite(choose, world, sx, sy);
    text(choose, world, scale);
    circle(choose, world, scale);
    size_text(choose, world, scale);
    textbox_resize(choose, world, scale);
    maps(world, world->choose.maps, scale);
}
