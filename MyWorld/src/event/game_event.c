/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The game_event.c
*/
/**
 * @file game_event.c
 * @brief The game_event.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <math.h>

#include "../../lib/my/headers/myworld.h"

sfVector2f get_mouse_3d_pos(sfVector2i *mouse, map_t *map)
{
    sfVector2f pos;
    float x_pur = ((float)mouse->x - map->offset.x) / map->zoom;
    float y_pur = ((float)mouse->y - map->offset.y) / map->zoom;

    pos.x = (y_pur / sin(map->angle_y) + x_pur / cos(map->angle_x)) / 2.0;
    pos.y = (y_pur / sin(map->angle_y) - x_pur / cos(map->angle_x)) / 2.0;
    return pos;
}

static void modify_point(world_t *world, int x, int y, int sens)
{
    float speed = 2.5 * world->dt;

    if (y < 0 || y >= world->map->height || x < 0 || x >= world->map->width)
        return;
    if (sens == RAISE_T) {
        sfSound_play(world->map->raise);
        world->map->points[y][x].z += speed;
        if (world->map->points[y][x].z > 12.5)
            world->map->points[y][x].z = 12.5;
    } else {
        sfSound_play(world->map->decrease);
        world->map->points[y][x].z -= speed;
        if (world->map->points[y][x].z < -1.0)
            world->map->points[y][x].z = -1.0;
    }
}

static void modify_area(world_t *world, int x, int y, int sens)
{
    int radius = world->map->size / 2;

    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            modify_point(world, x + j, y + i, sens);
        }
    }
}

static void update_tool(world_t *world, int x, int y)
{
    int sens = world->map->toolbox.sens;

    if (world->map->toolbox.size == AREA_T)
        modify_area(world, x, y, sens);
    else
        modify_point(world, x, y, sens);
}

void update_terrain(world_t *world)
{
    sfVector2i mouse;
    sfVector2f pos;
    int x;
    int y;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        mouse = sfMouse_getPositionRenderWindow(world->window);
        pos = get_mouse_3d_pos(&mouse, world->map);
        x = (int)pos.x;
        y = (int)pos.y;
        if (x >= 0 && x < world->map->width &&
            y >= 0 && y < world->map->height) {
            update_tool(world, x, y);
        }
    }
}

static void shortcut_toolbox(world_t *world)
{
    if (world->event.type == sfEvtKeyPressed &&
        world->event.key.code == sfKeyJ) {
        if (world->map->toolbox.sens == RAISE_T)
            world->map->toolbox.sens = DECREASE_T;
        else
            world->map->toolbox.sens = RAISE_T;
    }
    if (world->event.type == sfEvtKeyPressed &&
        world->event.key.code == sfKeyK) {
        if (world->map->toolbox.size == POINT_T)
            world->map->toolbox.size = AREA_T;
        else
            world->map->toolbox.size = POINT_T;
    }
}

static void exec_shortcut(world_t *world)
{
    shortcut_toolbox(world);
    if (world->event.type == sfEvtKeyPressed &&
        world->event.key.code == sfKeyH) {
        if (world->map->help_b == sfTrue)
            world->map->help_b = sfFalse;
        else
            world->map->help_b = sfTrue;
    }
    if (world->event.type == sfEvtKeyPressed &&
        world->event.key.code == sfKeyT) {
        if (world->map->tool == sfTrue)
            world->map->tool = sfFalse;
        else
            world->map->tool = sfTrue;
    }
}

static void exec_button(world_t *world)
{
    if (world->event.type == sfEvtMouseButtonPressed &&
        world->event.mouseButton.button == sfMouseLeft) {
        if (world->map->tool == sfFalse)
            click_tool(world);
        else
            click_close(world);
        click_toolbox(world);
        click_save(world);
    }
}

static void handle_size_area(map_t *map, world_t *world)
{
    unsigned int size_max
    = world->coords.x > world->coords.y ? world->coords.y : world->coords.x - 2;

    if (size_max % 2 == 0)
        size_max--;
    if (world->event.type == sfEvtKeyPressed &&
        world->event.key.code == sfKeyAdd) {
        map->size += 2;
        if (map->size > size_max)
            map->size = size_max;
    }
    if (world->event.type == sfEvtKeyPressed &&
        world->event.key.code == sfKeySubtract) {
        map->size -= 2;
        if (map->size < 3)
            map->size = 3;
    }
}

void event_game(world_t *world)
{
    hover(world);
    selected_tool(world);
    exec_button(world);
    exec_shortcut(world);
    handle_size_area(world->map, world);
}
