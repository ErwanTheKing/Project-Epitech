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

void click_back_s(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->settings.back.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        if (world->old_st == MAIN_O)
            world->st_game = MAIN;
        else
            world->st_game = PAUSE_M;
    }
}

void resize(world_t *world)
{
    sfVector2u textureSize
    = sfTexture_getSize(world->main_menu.background.texture);
    float scaleX = 0;
    float scaleY = 0;

    scaleX = (float)world->mode.width / textureSize.x;
    scaleY = (float)world->mode.height / textureSize.y;
    sfSprite_setScale(world->main_menu.background.sprite,
        (sfVector2f){scaleX, scaleY});
    resize_main(&world->main_menu, world);
    resize_settings(&world->settings, world);
    if (world->launch == sfTrue) {
        resize_game(world->map, world);
        resize_toolbox(&world->map->toolbox, world);
    }
    resize_pause(&world->pause, world);
    resize_choose(&world->choose, world);
}

void click_full(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->settings.full_case.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        switch_full(world);
    }
}

void click_vsync(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->settings.vsync_case.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        if (world->settings.vsync == sfTrue) {
            sfRenderWindow_setVerticalSyncEnabled(world->window, sfFalse);
            sfRenderWindow_setFramerateLimit(world->window,
                world->settings.vsync_int);
            world->settings.vsync = sfFalse;
        } else {
            sfRenderWindow_setVerticalSyncEnabled(world->window, sfTrue);
            sfRenderWindow_setFramerateLimit(world->window, 0);
            world->settings.vsync = sfTrue;
        }
    }
}

static void apply_change_res(world_t *world)
{
    world->oldMode = world->mode;
    sfRenderWindow_destroy(world->window);
    world->window = sfRenderWindow_create(world->mode, "Transform Mars",
        sfTitlebar | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(world->window, sfFalse);
    if (world->settings.vsync == sfTrue)
        sfRenderWindow_setVerticalSyncEnabled(world->window, sfTrue);
    else
        sfRenderWindow_setVerticalSyncEnabled(world->window, sfFalse);
    sfRenderWindow_setFramerateLimit(world->window,
        world->settings.vsync_int);
    resize(world);
}

void click_res(world_t *world)
{
    sfVideoMode mode800 = {800, 600, 32};
    sfVideoMode mode1920 = {1920, 1080, 32};
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->settings.res_case.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        if (world->st_res == RES1920) {
            world->mode = mode800;
            sfText_setString(world->settings.res_t, "Resolution : 800x600");
            world->st_res = RES800;
        } else {
            world->mode = mode1920;
            sfText_setString(world->settings.res_t, "Resolution : 1920x1080");
            world->st_res = RES1920;
        }
        apply_change_res(world);
    }
}
