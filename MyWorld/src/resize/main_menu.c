/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The main_menu.c
*/
/**
 * @file main_menu.c
 * @brief The main_menu.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"

void resize_main(main_menu_t *main_menu, world_t *world)
{
    float sx = (float)world->mode.width / 1920.f;
    float sy = (float)world->mode.height / 1080.f;

    resize_sprite(main_menu->start.sprite,
        &(sfVector2f){world->mode.width / 2, world->mode.height / 3},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
    resize_sprite(main_menu->settings.sprite,
        &(sfVector2f){world->mode.width / 2, world->mode.height / 2.2},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
    resize_sprite(main_menu->quit.sprite,
        &(sfVector2f){world->mode.width / 2, world->mode.height / 1.75},
        &(sfVector2f){0.7 * sx, 0.7 * sy});
    resize_sprite(main_menu->logo.sprite,
        &(sfVector2f){world->mode.width / 9, world->mode.height / 5},
        &(sfVector2f){0.4 * sx, 0.4 * sy});
    resize_sprite(main_menu->cursor.sprite,
        &(sfVector2f){world->mode.width / 9, world->mode.height / 5},
        &(sfVector2f){0.1 * sx, 0.1 * sy});
}
