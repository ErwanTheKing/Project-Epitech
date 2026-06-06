/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** The destroy_main_menu.c
*/
/**
 * @file destroy_main_menu.c
 * @brief The destroy_main_menu.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static void destroy_sprite(main_radar_t *radar)
{
    sfSprite_destroy(radar->pause.background.sprite);
    sfSprite_destroy(radar->pause.logo.sprite);
    sfSprite_destroy(radar->pause.over_pause.sprite);
}

static void destroy_texture(main_radar_t *radar)
{
    sfTexture_destroy(radar->pause.background.texture);
    sfTexture_destroy(radar->pause.logo.texture);
    sfTexture_destroy(radar->pause.over_pause.texture);
}

static void destroy_text(main_radar_t *radar)
{
    sfFont_destroy(radar->pause.font);
    sfText_destroy(radar->pause.pause);
    sfText_destroy(radar->pause.resume);
    sfText_destroy(radar->pause.exit);
}

void destroy_pause(main_radar_t *radar)
{
    destroy_sprite(radar);
    destroy_texture(radar);
    destroy_text(radar);
}
