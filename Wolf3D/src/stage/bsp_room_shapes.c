/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** BSP room shape carving helpers
*/

#include "../include/wolf3d.h"

static void carve_room_rect(bsp_t *node, int map[MAP_HEIGHT][MAP_WIDTH])
{
    int y;

    for (y = node->ry; y < node->ry + node->rh; y++)
        carve_h(map, node->rx, node->rx + node->rw - 1, y);
}

static void carve_room_diamond(bsp_t *node, int map[MAP_HEIGHT][MAP_WIDTH])
{
    int cx;
    int cy;
    int rx;
    int ry;
    int limit;
    int x;
    int y;

    cx = node->rx + node->rw / 2;
    cy = node->ry + node->rh / 2;
    rx = node->rw / 2;
    ry = node->rh / 2;
    limit = rx * ry;
    for (y = node->ry; y < node->ry + node->rh; y++)
        for (x = node->rx; x < node->rx + node->rw; x++)
            map[y][x] = abs(x - cx) * ry + abs(y - cy) * rx <= limit ? 0 :
                map[y][x];
}

static void carve_room_cross(bsp_t *node, int map[MAP_HEIGHT][MAP_WIDTH])
{
    int cx;
    int cy;

    cx = node->rx + node->rw / 2;
    cy = node->ry + node->rh / 2;
    carve_h(map, node->rx, node->rx + node->rw - 1, cy);
    carve_v(map, node->ry, node->ry + node->rh - 1, cx);
    if (node->rw > 4)
        carve_h(map, node->rx, node->rx + node->rw - 1, cy - 1);
    if (node->rh > 4)
        carve_v(map, node->ry, node->ry + node->rh - 1, cx - 1);
}

int bsp_room_shape_from_roll(int roll)
{
    if (roll < BSP_ROOM_RECT_RATE)
        return 0;
    if (roll < BSP_ROOM_RECT_RATE + BSP_ROOM_DIAMOND_RATE)
        return 1;
    if (roll < BSP_ROOM_RECT_RATE + BSP_ROOM_DIAMOND_RATE +
        BSP_ROOM_CROSS_RATE)
        return 2;
    return 3;
}

static void carve_blob_row(bsp_t *node, int map[MAP_HEIGHT][MAP_WIDTH],
    int y)
{
    int cx = node->rx + node->rw / 2;
    int cy = node->ry + node->rh / 2;
    int span = node->rw / 2;
    int start;
    int end;

    span = span - (abs(y - cy) * span) / (node->rh / 2 + 1);
    span += (rand() % 3) - 1;
    if (span < 1)
        span = 1;
    start = cx - span < node->rx + 1 ? node->rx + 1 : cx - span;
    end = cx + span > node->rx + node->rw - 2 ? node->rx + node->rw - 2 :
        cx + span;
    for (int x = start; x <= end; x++)
        map[y][x] = 0;
}

static void carve_room_blob(bsp_t *node, int map[MAP_HEIGHT][MAP_WIDTH])
{
    int y;

    for (y = node->ry; y < node->ry + node->rh; y++) {
        carve_blob_row(node, map, y);
    }
}

void bsp_carve_room_shape(bsp_t *node, int map[MAP_HEIGHT][MAP_WIDTH],
    int shape)
{
    if (shape == 0) {
        carve_room_rect(node, map);
        return;
    }
    if (shape == 1) {
        carve_room_diamond(node, map);
        return;
    }
    if (shape == 2) {
        carve_room_cross(node, map);
        return;
    }
    carve_room_blob(node, map);
}
