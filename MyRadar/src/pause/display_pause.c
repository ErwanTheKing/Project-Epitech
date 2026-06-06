/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** The main_menu.c
*/
/**
 * @file main_menu.c
 * @brief The main_menu.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static void display_sprite(main_radar_t *radar)
{
    sfTransform transform = sfTransform_Identity;
    sfRenderStates states = sfRenderStates_default();

    sfTransform_scale(&transform, 1.3f, 1.1f);
    states.transform = transform;
    sfRenderWindow_drawSprite(radar->window, radar->pause.background.sprite,
        &states);
    sfTransform_scale(&transform, 0.3f, 0.3f);
    states.transform = transform;
    sfRenderWindow_drawSprite(radar->window, radar->pause.logo.sprite, &states);
    sfRenderWindow_drawSprite(radar->window, radar->pause.over_pause.sprite,
        NULL);
}

static void display_text(main_radar_t *radar)
{
    sfRenderWindow_drawText(radar->window, radar->pause.pause, NULL);
    sfRenderWindow_drawText(radar->window, radar->pause.resume, NULL);
    sfRenderWindow_drawText(radar->window, radar->pause.exit, NULL);
}

void display_pause(main_radar_t *radar)
{
    sfRenderWindow_clear(radar->window, sfBlack);
    display_sprite(radar);
    display_text(radar);
}
