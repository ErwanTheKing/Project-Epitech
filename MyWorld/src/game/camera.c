/*
** EPITECH PROJECT, 2026
** camera.c
** File description:
** camera to move around the map
*/
#include "../../lib/my/headers/myworld.h"

void manage_camera(world_t *world)
{
    float pan_speed = 500.0 * world->dt;
    float rot_speed = 1.0 * world->dt;

    if (sfKeyboard_isKeyPressed(sfKeyUp))
        world->map->offset.y += pan_speed;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        world->map->offset.y -= pan_speed;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        world->map->offset.x += pan_speed;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        world->map->offset.x -= pan_speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        world->map->angle_x -= rot_speed;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        world->map->angle_x += rot_speed;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        world->map->angle_y -= rot_speed;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        world->map->angle_y += rot_speed;
}
