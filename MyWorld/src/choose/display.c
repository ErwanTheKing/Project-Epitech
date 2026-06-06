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

#include "../../lib/my/headers/myworld.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

static void display_sprite(world_t *world)
{
    sfRenderWindow_drawSprite(world->window, world->main_menu.background.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->main_menu.logo.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->choose.background.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->choose.back.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->choose.create.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->choose.load.sprite,
        NULL);
}

static void display_text(world_t *world)
{
    sfRenderWindow_drawText(world->window, world->choose.back_t, NULL);
    sfRenderWindow_drawText(world->window, world->choose.create_t, NULL);
    sfRenderWindow_drawText(world->window, world->choose.load_t, NULL);
    sfRenderWindow_drawText(world->window, world->choose.small_t, NULL);
    sfRenderWindow_drawText(world->window, world->choose.medium_t, NULL);
    sfRenderWindow_drawText(world->window, world->choose.large_t, NULL);
    sfRenderWindow_drawText(world->window, world->choose.custom_t, NULL);
    sfRenderWindow_drawText(world->window, world->choose.x_t, NULL);
}

static void display_circle(world_t *world)
{
    sfRenderWindow_drawCircleShape(world->window, world->choose.small, NULL);
    sfRenderWindow_drawCircleShape(world->window, world->choose.medium, NULL);
    sfRenderWindow_drawCircleShape(world->window, world->choose.large, NULL);
    sfRenderWindow_drawCircleShape(world->window, world->choose.custom, NULL);
    sfRenderWindow_drawCircleShape(world->window, world->choose.selected, NULL);
}

static void display_textbox(textbox_t *box, world_t *world)
{
    sfRenderWindow_drawRectangleShape(world->window, box->rectangle, NULL);
    sfRenderWindow_drawText(world->window, box->text, NULL);
}

static void reset_color(world_t *world, map_entry_t *maps)
{
    sfFloatRect bounds;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(world->window);
    int start = world->choose.up_down;
    int end = world->choose.up_down + world->choose.count_map;

    if (end > world->choose.len)
        end = world->choose.len;
    for (int i = start; i < end; i++) {
        bounds = sfRectangleShape_getGlobalBounds(maps[i].rectangle);
        if (world->event.type == sfEvtMouseButtonPressed &&
            world->event.mouseButton.button == sfMouseLeft &&
            sfFloatRect_contains(&bounds, mouse.x, mouse.y))
            world->choose.index_selected = i;
        sfRectangleShape_setFillColor(maps[i].rectangle,
            i == world->choose.index_selected
            ? sfColor_fromRGBA(165, 253, 254, 125)
            : sfTransparent);
    }
}

static void display_maps_entry(world_t *world, map_entry_t *maps)
{
    int j = 0;

    for (int i = 0 + world->choose.up_down;
        i < world->choose.count_map + world->choose.up_down; i++) {
        sfText_setPosition(maps[i].text,
            (sfVector2f){world->mode.width / 1.57,
                world->mode.height / 3 + j * 70});
        sfRectangleShape_setPosition(maps[i].rectangle,
            (sfVector2f){world->mode.width / 1.57,
                world->mode.height / 3 + j * 70});
        sfRenderWindow_drawRectangleShape(world->window, maps[i].rectangle,
            NULL);
        sfRenderWindow_drawText(world->window, maps[i].text, NULL);
        j++;
    }
    reset_color(world, maps);
}

void display_choose(world_t *world)
{
    sfRenderWindow_clear(world->window, sfBlack);
    display_sprite(world);
    display_text(world);
    display_circle(world);
    display_textbox(world->choose.size_x, world);
    display_textbox(world->choose.size_y, world);
    display_textbox(world->choose.name, world);
    display_maps_entry(world, world->choose.maps);
    display_cursor(world);
}
