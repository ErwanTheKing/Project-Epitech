/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** The destroy_game.c
*/
/**
 * @file destroy_game.c
 * @brief The destroy_game.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static void destroy_sprite(main_radar_t *radar)
{
    sfSprite_destroy(radar->game.background.sprite);
}

static void destroy_texture(main_radar_t *radar)
{
    sfTexture_destroy(radar->game.background.texture);
}

static void destroy_text(main_radar_t *radar)
{
    sfFont_destroy(radar->game.font);
    sfText_destroy(radar->game.hitbox);
    sfText_destroy(radar->game.sprite);
    sfText_destroy(radar->game.hit_status);
    sfText_destroy(radar->game.spr_status);
    sfText_destroy(radar->game.time_l);
    sfText_destroy(radar->game.time_r);
    sfText_destroy(radar->game.separator);
    sfText_destroy(radar->game.fps);
    sfText_destroy(radar->game.fps_status);
}

void destroy_game(main_radar_t *radar)
{
    destroy_sprite(radar);
    destroy_texture(radar);
    destroy_text(radar);
}
