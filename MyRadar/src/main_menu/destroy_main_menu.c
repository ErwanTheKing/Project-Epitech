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
    sfSprite_destroy(radar->main.background.sprite);
    sfSprite_destroy(radar->main.logo.sprite);
}

static void destroy_texture(main_radar_t *radar)
{
    sfTexture_destroy(radar->main.background.texture);
    sfTexture_destroy(radar->main.logo.texture);
}

static void destroy_text(main_radar_t *radar)
{
    sfFont_destroy(radar->main.font);
    sfText_destroy(radar->main.exit);
    sfText_destroy(radar->main.play);
}

void destroy_main_menu(main_radar_t *radar)
{
    destroy_sprite(radar);
    destroy_texture(radar);
    destroy_text(radar);
}
