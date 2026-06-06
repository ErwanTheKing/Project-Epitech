/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** BSP room carving and center computation
*/

#include "../include/wolf3d.h"

void carve_h(int map[MAP_HEIGHT][MAP_WIDTH], int x1, int x2, int y)
{
    int start = x1 < x2 ? x1 : x2;
    int end = x1 < x2 ? x2 : x1;

    for (int x = start; x <= end; x++)
        if (y > 0 && y < MAP_HEIGHT - 1 && x > 0 && x < MAP_WIDTH - 1)
            map[y][x] = 0;
}

void carve_v(int map[MAP_HEIGHT][MAP_WIDTH], int y1, int y2, int x)
{
    int start = y1 < y2 ? y1 : y2;
    int end = y1 < y2 ? y2 : y1;

    for (int y = start; y <= end; y++)
        if (y > 0 && y < MAP_HEIGHT - 1 && x > 0 && x < MAP_WIDTH - 1)
            map[y][x] = 0;
}

static void bsp_place_room(bsp_t *node, int map[MAP_HEIGHT][MAP_WIDTH])
{
    int max_w;
    int max_h;
    int min_w;
    int min_h;
    int roll;
    int shape;

    max_w = node->w - BSP_ROOM_MARGIN * 2;
    max_h = node->h - BSP_ROOM_MARGIN * 2;
    if (max_w < 3 || max_h < 3)
        return;
    min_w = BSP_ROOM_MIN_SIZE > max_w ? max_w : BSP_ROOM_MIN_SIZE;
    min_h = BSP_ROOM_MIN_SIZE > max_h ? max_h : BSP_ROOM_MIN_SIZE;
    node->rw = min_w + rand() % (max_w - min_w + 1);
    node->rh = min_h + rand() % (max_h - min_h + 1);
    node->rx = node->x + BSP_ROOM_MARGIN + rand() % (max_w - node->rw + 1);
    node->ry = node->y + BSP_ROOM_MARGIN + rand() % (max_h - node->rh + 1);
    roll = rand() % 100;
    shape = bsp_room_shape_from_roll(roll);
    bsp_carve_room_shape(node, map, shape);
}

void bsp_place_rooms(bsp_t *node, int map[MAP_HEIGHT][MAP_WIDTH])
{
    if (node->left || node->right) {
        if (node->left)
            bsp_place_rooms(node->left, map);
        if (node->right)
            bsp_place_rooms(node->right, map);
        return;
    }
    bsp_place_room(node, map);
}

sfVector2i bsp_center(bsp_t *node)
{
    sfVector2i center;

    if (!node->left && !node->right) {
        center.x = node->rx + node->rw / 2;
        center.y = node->ry + node->rh / 2;
        if (node->rw > 0)
            return center;
        center.x = node->x + node->w / 2;
        center.y = node->y + node->h / 2;
        return center;
    }
    if (node->left)
        return bsp_center(node->left);
    return bsp_center(node->right);
}
