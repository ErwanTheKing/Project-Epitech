/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** The display_game.c
*/
/**
 * @file display_game.c
 * @brief The display_game.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static void display_sprite(main_radar_t *radar)
{
    sfRenderWindow_drawSprite(radar->window, radar->game.background.sprite,
        NULL);
}

static void display_text(main_radar_t *radar)
{
    sfRenderWindow_drawText(radar->window, radar->game.hitbox, NULL);
    sfRenderWindow_drawText(radar->window, radar->game.sprite, NULL);
    sfRenderWindow_drawText(radar->window, radar->game.hit_status, NULL);
    sfRenderWindow_drawText(radar->window, radar->game.spr_status, NULL);
    sfRenderWindow_drawText(radar->window, radar->game.time_l, NULL);
    sfRenderWindow_drawText(radar->window, radar->game.time_r, NULL);
    sfRenderWindow_drawText(radar->window, radar->game.separator, NULL);
    sfRenderWindow_drawText(radar->window, radar->game.fps, NULL);
    sfRenderWindow_drawText(radar->window, radar->game.fps_status, NULL);
}

static void change_status(main_radar_t *radar)
{
    if (radar->disp_hitbox == sfFalse) {
        sfText_setString(radar->game.hit_status, "OFF");
        sfText_setColor(radar->game.hit_status, sfRed);
    } else {
        sfText_setString(radar->game.hit_status, "ON");
        sfText_setColor(radar->game.hit_status, sfGreen);
    }
    if (radar->disp_sprite == sfFalse) {
        sfText_setString(radar->game.spr_status, "OFF");
        sfText_setColor(radar->game.spr_status, sfRed);
    } else {
        sfText_setString(radar->game.spr_status, "ON");
        sfText_setColor(radar->game.spr_status, sfGreen);
    }
}

static void update_time(main_radar_t *radar)
{
    char *seconds = my_nbr_to_str((int)radar->seconds);
    char *minutes = my_nbr_to_str(radar->minutes);

    if ((int)radar->seconds == 60) {
        sfClock_restart(radar->clock_time);
        radar->minutes++;
    }
    sfText_setString(radar->game.time_r, seconds);
    sfText_setString(radar->game.time_l, minutes);
    free(minutes);
    free(seconds);
}

static void print_framerate(main_radar_t *radar)
{
    sfTime elapsed;
    char *fps = my_nbr_to_str(radar->fps);

    sfRenderWindow_setFramerateLimit(radar->window, 120);
    if (radar->first == 1) {
        radar->clock_fps = sfClock_create();
        radar->first = 0;
    }
    elapsed = sfClock_getElapsedTime(radar->clock_fps);
    if (sfTime_asSeconds(elapsed) >= 1) {
        sfText_setString(radar->game.fps_status, fps);
        radar->fps = 0;
        sfClock_restart(radar->clock_fps);
    } else
        radar->fps++;
    free(fps);
}

void display_game(main_radar_t *radar)
{
    sfRenderWindow_clear(radar->window, sfBlack);
    display_sprite(radar);
    change_status(radar);
    display_text(radar);
    update_time(radar);
    print_framerate(radar);
    draw_plane(radar);
    draw_tower(radar);
}
