/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The verif_load_file.c
*/
/**
 * @file verif_load_file.c
 * @brief The verif_load_file.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../lib/my/headers/myworld.h"
#include "../../lib/my/headers/my.h"

static char *get_info_maps(world_t *world)
{
    char *str = NULL;
    char *tmp = NULL;
    char *filepath = strdup("maps/");

    if (!filepath)
        return NULL;
    tmp = realloc(filepath, 5 +
        strlen(world->choose.maps[world->choose.index_selected].fullname) + 1);
    if (!tmp) {
        free(filepath);
        return NULL;
    }
    filepath = tmp;
    filepath = strcat(filepath,
        world->choose.maps[world->choose.index_selected].fullname);
    str = openator(filepath);
    free(tmp);
    return str;
}

static char **get_array(world_t *world)
{
    char **array = NULL;
    char *str = get_info_maps(world);

    if (!str)
        return NULL;
    array = my_str_to_word_array(str, "\n");
    if (!array) {
        free(str);
        return NULL;
    }
    free(str);
    return array;
}

static int get_width(char **array, int i)
{
    char **arr = my_str_to_word_array(array[i], " \t");
    int len = 0;

    if (!arr)
        return -1;
    for (; arr[len]; len++);
    free_array(arr);
    return len;
}

static int init_map_points(char **array, map_t *map, int height, int width)
{
    char **arr = NULL;

    for (int y = 0; y != height; y++) {
        map->points[y] = malloc(sizeof(vector3f_t) * width);
        if (map->points[y] == NULL)
            return FAILURE;
        arr = my_str_to_word_array(array[y], " \t");
        if (!arr || width != get_width(array, y)) {
            free_array(array);
            return FAILURE;
        }
        for (int x = 0; x != width; x++) {
            map->points[y][x].x = x;
            map->points[y][x].y = y;
            map->points[y][x].z = atof(arr[x]);
        }
    }
    return SUCCESS;
}

static int fill_info_maps(map_t *new_map, int height, int width)
{
    new_map->zoom = 32.0;
    new_map->angle_x = 0.52;
    new_map->angle_y = 0.52;
    new_map->offset.x = 0;
    new_map->offset.y = 0;
    new_map->height = height;
    new_map->width = width;
    new_map->points = malloc(sizeof(vector3f_t *) * new_map->height);
    if (new_map->points == NULL)
        return FAILURE;
    return SUCCESS;
}

map_t *load_map(world_t *world)
{
    char **array = NULL;
    int height = 0;
    int width = 0;
    map_t *new_map;

    new_map = malloc(sizeof(map_t));
    if (new_map == NULL)
        return NULL;
    array = get_array(world);
    if (!array){
        free(new_map);
        return NULL;
    }
    height = len_array(array);
    width = get_width(array, 0);
    if (fill_info_maps(new_map, height, width) == FAILURE)
        return NULL;
    if (init_map_points(array, new_map, height, width) == FAILURE)
        return NULL;
    return new_map;
}
