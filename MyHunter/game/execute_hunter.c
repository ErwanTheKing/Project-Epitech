/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The manage_sprite.c
*/
/**
 * @file manage_sprite.c
 * @brief The manage_sprite.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../include/includes.h"

void count_point(bool_t *bool, bird_t *tmp)
{
    if (tmp->touch == sfFalse)
        bool->count_point++;
}

void loose_ammo(bool_t *bool)
{
    if (bool->mode == 0)
        bool->ammo -= 1;
    if (bool->mode == 1 && bool->ammo > 1)
        bool->ammo -= 1;
}

void click_sprite(sfRenderWindow *window, bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);
    sfFloatRect bounds;

    for (bird_t *tmp = bool->bird_right; tmp != NULL; tmp = tmp->next) {
        bounds = sfSprite_getGlobalBounds(tmp->sprite);
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
            sfSprite_setRotation(tmp->sprite, -90);
            count_point(bool, tmp);
            tmp->touch = sfTrue;
            bool->touch = sfTrue;
            return;
        }
    }
    bool->touch = sfFalse;
    loose_ammo(bool);
}
