/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The load_map.c
*/
/**
 * @file load_map.c
 * @brief The load_map.c
 * @author Erwan Lo Presti
 */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "../../lib/my/headers/myworld.h"
#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/macros.h"

int len_array(char **array)
{
    int len = 0;

    if (!array)
        return -1;
    for (; array[len]; len++);
    return len;
}

static int has_extension(char *name)
{
    int len = strlen(name);

    if (len < 7 || strcmp(name, ".legend") == 0)
        return -1;
    return strcmp(name + len - 7, ".legend");
}

static char **fill_array(DIR *dir, int *count)
{
    char **tmp = NULL;
    char **array = NULL;

    for (struct dirent *entry = readdir(dir); entry; entry = readdir(dir)) {
        if (has_extension(entry->d_name) != 0)
            continue;
        tmp = realloc(array, sizeof(char *) * (*count + 2));
        if (!tmp) {
            free_array(array);
            return NULL;
        }
        array = tmp;
        array[*count] = strdup(entry->d_name);
        if (!array[*count]) {
            free_array(array);
            return NULL;
        }
        (*count)++;
    }
    return array;
}

static char **open_dir(void)
{
    char **array = NULL;
    int count = 0;
    DIR *dir = opendir("maps");

    if (!dir) {
        if (mkdir("maps", 0755) == -1)
            return NULL;
        dir = opendir("maps");
        if (!dir)
            return NULL;
    }
    array = fill_array(dir, &count);
    closedir(dir);
    if (!array)
        return NULL;
    array[count] = NULL;
    return array;
}

static int fill_text(int i, map_entry_t *maps)
{
    sfFloatRect size;

    maps[i].font = sfFont_createFromFile(FONT_SPECIAL);
    if (!maps[i].font)
        return FAILURE;
    maps[i].text = sfText_create();
    sfText_setFont(maps[i].text, maps[i].font);
    sfText_setCharacterSize(maps[i].text, 35);
    sfText_setString(maps[i].text, maps[i].name);
    sfText_setColor(maps[i].text, sfWhite);
    size = sfText_getGlobalBounds(maps[i].text);
    sfText_setOrigin(maps[i].text,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(maps[i].text,
        (sfVector2f){1920 / 1.57, 1080 / 3 + i * 70});
    return SUCCESS;
}

static void fill_rectangle(int i, map_entry_t *maps)
{
    maps[i].rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(maps[i].rectangle, (sfVector2f){450, 60});
    sfRectangleShape_setOutlineThickness(maps[i].rectangle, 2);
    sfRectangleShape_setOutlineColor(maps[i].rectangle,
        sfColor_fromRGB(165, 253, 254));
    sfRectangleShape_setFillColor(maps[i].rectangle, sfTransparent);
    sfRectangleShape_setOrigin(maps[i].rectangle,
        (sfVector2f){450 / 2, 60 / 2});
    sfRectangleShape_setPosition(maps[i].rectangle,
        (sfVector2f){1920 / 1.57, 1080 / 3 + i * 70});
}

static int fill_maps_infos(map_entry_t *maps, int i, char **array)
{
    maps[i].fullname = strdup(array[i]);
    if (!maps[i].fullname)
        return FAILURE;
    maps[i].name = strndup(array[i], strlen(array[i]) - 7);
    if (!maps[i].name) {
        free(maps[i].fullname);
        return FAILURE;
    }
    if (fill_text(i, maps) == FAILURE) {
        free(maps[i].name);
        free(maps[i].fullname);
        return FAILURE;
    }
    fill_rectangle(i, maps);
    return SUCCESS;
}

void click_load_map(map_entry_t *maps, world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds;
    int start = world->choose.up_down < 0 ? 0 : world->choose.up_down;
    int end = world->choose.count_map + world->choose.up_down;

    if (end > world->choose.len)
        end = world->choose.len;
    for (int i = start; i < end; i++) {
        bounds = sfRectangleShape_getGlobalBounds(maps[i].rectangle);
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
            sfRectangleShape_setFillColor(maps[i].rectangle,
                sfColor_fromRGBA(165, 253, 254, 125));
            world->choose.index_selected = i;
            strcpy(world->choose.name->input,
                world->choose.maps[world->choose.index_selected].name);
        } else
            sfRectangleShape_setFillColor(maps[i].rectangle, sfTransparent);
    }
}

int create_disp_maps(choose_t *choose)
{
    char **array = open_dir();

    choose->index_selected = -1;
    if (!array)
        return FAILURE;
    choose->len = len_array(array);
    choose->count_map = choose->len < 5 ? choose->len : 5;
    choose->maps = malloc(sizeof(map_entry_t) * choose->len);
    if (!choose->maps) {
        free_array(array);
        return FAILURE;
    }
    for (int i = 0; i < choose->len; i++) {
        if (fill_maps_infos(choose->maps, i, array) == FAILURE) {
            free_array(array);
            return FAILURE;
        }
    }
    free_array(array);
    return SUCCESS;
}
