/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The exec.c
*/
/**
 * @file exec.c
 * @brief The exec.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include "../../lib/my/headers/myworld.h"

void click_save(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->map->save.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        save_map(world->map, &world->choose);
        world->st_game = MAIN;
        world->old_st = MAIN_O;
        create_disp_maps(&world->choose);
    }
}
