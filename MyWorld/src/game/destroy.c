/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The destroy.c
*/
/**
 * @file destroy.c
 * @brief The destroy.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"

static void texture(map_t *map)
{
    sfTexture_destroy(map->background.texture);
    sfTexture_destroy(map->save.texture);
}

static void sprite(map_t *map)
{
    sfSprite_destroy(map->background.sprite);
    sfSprite_destroy(map->save.sprite);
}

static void rectangle(map_t *map)
{
    sfRectangleShape_destroy(map->help.rectangle);
}

static void text(map_t *map)
{
    sfFont_destroy(map->toolbox.font);
    sfText_destroy(map->help.help);
    sfText_destroy(map->help.help_t);
    sfText_destroy(map->help.toolbox);
    sfText_destroy(map->help.zoom);
    sfText_destroy(map->help.move);
    sfText_destroy(map->help.rotate);
    sfText_destroy(map->help.direction);
    sfText_destroy(map->help.size);
    sfText_destroy(map->help.fullscreen);
    sfText_destroy(map->toolbox.size_area);
    sfText_destroy(map->help.modify_area);
}

static void sound(map_t *map)
{
    sfSound_destroy(map->raise);
    sfSound_destroy(map->decrease);
    sfSoundBuffer_destroy(map->up);
    sfSoundBuffer_destroy(map->down);
}

void destroy_game(map_t *map)
{
    texture(map);
    sprite(map);
    rectangle(map);
    text(map);
    sound(map);
}
