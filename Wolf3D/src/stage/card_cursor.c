/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Card cursor helpers
*/

#include "../include/wolf3d.h"

int card_under_cursor(wolf_t *wolf, intermission_t *inter)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(
        wolf->window_data->window);
    sfFloatRect bounds;

    for (int i = 0; i < 3; i++) {
        bounds = sfRectangleShape_getGlobalBounds(inter->card[i].rect);
        if (sfFloatRect_contains(&bounds, pos.x, pos.y))
            return i;
    }
    return -1;
}

int hovered_card(intermission_t *inter)
{
    for (int i = 0; i < 3; i++)
        if (inter->card[i].hoover)
            return i;
    return -1;
}

void move_card_cursor(wolf_t *wolf)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(
        wolf->window_data->window);
    float x = joystick_axis(sfJoystickX);
    float y = joystick_axis(sfJoystickY);
    float speed = 18.0f;

    pos.x += x * speed;
    pos.y += y * speed;
    if (pos.x < 0)
        pos.x = 0;
    if (pos.y < 0)
        pos.y = 0;
    if (pos.x > wolf->window_data->width)
        pos.x = wolf->window_data->width;
    if (pos.y > wolf->window_data->height)
        pos.y = wolf->window_data->height;
    sfMouse_setPositionRenderWindow(pos, wolf->window_data->window);
}
