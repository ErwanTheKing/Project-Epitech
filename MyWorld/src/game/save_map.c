/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The save_map.c
*/
/**
 * @file save_map.c
 * @brief The save_map.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../lib/my/headers/myworld.h"
#include <unistd.h>

#include "../../lib/my/headers/defines.h"

static char *get_name(choose_t *choose)
{
    char *str = NULL;
    char *base_name = "NoName";

    if (choose->name)
        base_name = choose->name->input;
    str = malloc(strlen("maps/") + strlen(base_name) + strlen(".legend") + 1);
    if (!str)
        return NULL;
    strcpy(str, "maps/");
    strcat(str, base_name);
    strcat(str, ".legend");
    return str;
}

static int get_fd(choose_t *choose)
{
    int fd;
    char *name = get_name(choose);

    if (!name)
        return -1;
    fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd == -1) {
        free(name);
        return -1;
    }
    free(name);
    return fd;
}

int save_map(map_t *map, choose_t *choose)
{
    int fd = get_fd(choose);

    if (fd == -1)
        return -1;
    for (int i = 0; i < map->height; i++) {
        dprintf(fd, "%.2f", map->points[i][0].z);
        for (int j = 1; j < map->width; j++)
            dprintf(fd, " %.2f", map->points[i][j].z);
        dprintf(fd, "\n");
    }
    close(fd);
    return SUCCESS;
}
