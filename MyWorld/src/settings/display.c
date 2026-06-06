/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The display.c
*/
/**
 * @file display.c
 * @brief The display.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "../../lib/my/headers/myworld.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "../../lib/my/headers/my.h"

static void chose_sprite(world_t *world)
{
    if (world->settings.fullscreen == sfTrue)
        sfRenderWindow_drawSprite(world->window,
            world->settings.full_check.sprite, NULL);
    if (world->settings.vsync == sfTrue)
        sfRenderWindow_drawSprite(world->window,
            world->settings.vsync_check.sprite, NULL);
}

static void display_sprite(world_t *world)
{
    sfRenderWindow_drawSprite(world->window, world->main_menu.background.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->main_menu.logo.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->settings.settings.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->settings.back.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->settings.full_case.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->settings.vsync_case.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->settings.res_case.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->settings.frame_case.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->settings.more.sprite,
        NULL);
    sfRenderWindow_drawSprite(world->window, world->settings.less.sprite,
        NULL);
}

static void update_volume(world_t *world)
{
    float volume = roundf(sfMusic_getVolume(world->main_menu.music));
    char *str = my_nbr_to_str((int)volume);

    if (!str)
        return;
    sfText_setString(world->settings.volume, str);
    sfRenderWindow_drawText(world->window, world->settings.volume, NULL);
    free(str);
}

static void display_text(world_t *world)
{
    sfRenderWindow_drawText(world->window, world->settings.back_t, NULL);
    sfRenderWindow_drawText(world->window, world->settings.full_t, NULL);
    sfRenderWindow_drawText(world->window, world->settings.vsync_t, NULL);
    sfRenderWindow_drawText(world->window, world->settings.res_t, NULL);
    sfRenderWindow_drawText(world->window, world->settings.frame_t, NULL);
    sfRenderWindow_drawText(world->window, world->settings.musics, NULL);
    sfRenderWindow_drawText(world->window, world->settings.more_t, NULL);
    sfRenderWindow_drawText(world->window, world->settings.less_t, NULL);
    update_volume(world);
}

void display_settings(world_t *world)
{
    sfRenderWindow_clear(world->window, sfBlack);
    display_sprite(world);
    chose_sprite(world);
    display_text(world);
    display_cursor(world);
}
