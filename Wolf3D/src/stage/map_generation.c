/*
** EPITECH PROJECT, 2026
** stage
** File description:
** BSP dungeon map generation
*/

#include "../include/wolf3d.h"
#include <time.h>

static void bsp_connect(bsp_t *node, int map[MAP_HEIGHT][MAP_WIDTH])
{
    sfVector2i a;
    sfVector2i b;

    if (!node->left || !node->right)
        return;
    bsp_connect(node->left, map);
    bsp_connect(node->right, map);
    a = bsp_center(node->left);
    b = bsp_center(node->right);
    if (rand() % 2) {
        carve_h(map, a.x, b.x, a.y);
        carve_v(map, a.y, b.y, b.x);
    } else {
        carve_v(map, a.y, b.y, a.x);
        carve_h(map, a.x, b.x, b.y);
    }
}

static void bsp_spawn(wolf_t *wolf, bsp_t *node)
{
    int random;

    if (!node->left && !node->right) {
        if (node->rw <= 0 || (node->rx <= 3 && node->ry <= 3))
            return;
        random = rand() % 2;
        push_front(&wolf->list[GAME][random ? GARBAGE : MONSTER],
            init_player(wolf->window_data, random ? GARBAGE_T : ENNEMY,
                &(sfVector2f){
                    node->rx + node->rw / 2 + 0.5f,
                    node->ry + node->rh / 2 + 0.5f}));
        return;
    }
    if (node->left)
        bsp_spawn(wolf, node->left);
    if (node->right)
        bsp_spawn(wolf, node->right);
}

static void carve_start_area(int map[MAP_HEIGHT][MAP_WIDTH])
{
    carve_h(map, 1, 3, 1);
    carve_h(map, 1, 3, 2);
    carve_h(map, 1, 3, 3);
}

static void ensure_start_open(bsp_t *root, int map[MAP_HEIGHT][MAP_WIDTH])
{
    sfVector2i nearest;

    carve_start_area(map);
    nearest = bsp_center(root->left ? root->left : root);
    carve_h(map, 2, nearest.x, 2);
    carve_v(map, 2, nearest.y, nearest.x);
}

static void init_wall_map(int map[MAP_HEIGHT][MAP_WIDTH])
{
    int *flat = (int *)map;

    for (int i = 0; i < MAP_AREA; i++)
        flat[i] = 1;
}

static void print_map_row(int *row)
{
    for (int x = 0; x < MAP_WIDTH; x++)
        printf("%d ", row[x]);
    printf("\n");
}

static void print_map(int map[MAP_HEIGHT][MAP_WIDTH])
{
    for (int y = 0; y < MAP_HEIGHT; y++)
        print_map_row(map[y]);
}

static void ensure_fallback_entity(wolf_t *wolf)
{
    if (wolf->list[GAME][MONSTER] || wolf->list[GAME][GARBAGE])
        return;
    push_front(&wolf->list[GAME][GARBAGE],
        init_player(wolf->window_data, GARBAGE_T, &(sfVector2f){2.5f, 2.5f}));
}

void create_map(wolf_t *wolf, wall_t *wall)
{
    bsp_t *root;
    int map_w = 24;
    int map_h = 24;

    if (wolf->map_seed == 0)
        wolf->map_seed = (uint32_t)time(NULL);
    srand(wolf->map_seed);
    init_wall_map(wall->map);
    root = bsp_new(1, 1, map_w - 2, map_h - 2);
    bsp_split(root, BSP_MAX_DEPTH);
    bsp_place_rooms(root, wall->map);
    bsp_connect(root, wall->map);
    ensure_start_open(root, wall->map);
    bsp_spawn(wolf, root);
    ensure_fallback_entity(wolf);
    bsp_free(root);
    print_map(wall->map);
}
