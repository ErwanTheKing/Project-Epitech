/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** BSP tree structure: allocation, splitting
*/

#include "../include/wolf3d.h"

bsp_t *bsp_new(int x, int y, int w, int h)
{
    bsp_t *n = calloc(1, sizeof(bsp_t));

    if (!n)
        return NULL;
    n->x = x;
    n->y = y;
    n->w = w;
    n->h = h;
    n->rw = -1;
    n->rh = -1;
    return n;
}

void bsp_free(bsp_t *node)
{
    if (!node)
        return;
    bsp_free(node->left);
    bsp_free(node->right);
    free(node);
}

static int get_split_dir(bsp_t *node)
{
    if (node->h > node->w)
        return 1;
    if (node->w > node->h)
        return 0;
    return rand() % 2;
}

static void do_split(bsp_t *node, int split_h, int pos)
{
    if (split_h) {
        node->left = bsp_new(node->x, node->y, node->w, pos);
        node->right = bsp_new(node->x, node->y + pos, node->w, node->h - pos);
    } else {
        node->left = bsp_new(node->x, node->y, pos, node->h);
        node->right = bsp_new(node->x + pos, node->y, node->w - pos, node->h);
    }
}

void bsp_split(bsp_t *node, int depth)
{
    int split_h;
    int pos;

    if (depth <= 0)
        return;
    split_h = get_split_dir(node);
    if (split_h && node->h < BSP_MIN_SIZE * 2)
        split_h = 0;
    if (!split_h && node->w < BSP_MIN_SIZE * 2)
        split_h = 1;
    if (node->h < BSP_MIN_SIZE * 2 && node->w < BSP_MIN_SIZE * 2)
        return;
    if (split_h)
        pos = BSP_MIN_SIZE + rand() % (node->h - BSP_MIN_SIZE * 2 + 1);
    else
        pos = BSP_MIN_SIZE + rand() % (node->w - BSP_MIN_SIZE * 2 + 1);
    do_split(node, split_h, pos);
    bsp_split(node->left, depth - 1);
    bsp_split(node->right, depth - 1);
}
