/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The destroy.c
*/
/**
 * @file destroy.c
 * @brief The destroy.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"

static void texture(settings_t *settings)
{
    sfTexture_destroy(settings->settings.texture);
    sfTexture_destroy(settings->back.texture);
    sfTexture_destroy(settings->full_case.texture);
    sfTexture_destroy(settings->full_check.texture);
    sfTexture_destroy(settings->vsync_case.texture);
    sfTexture_destroy(settings->vsync_check.texture);
    sfTexture_destroy(settings->res_case.texture);
    sfTexture_destroy(settings->frame_case.texture);
    sfTexture_destroy(settings->more.texture);
    sfTexture_destroy(settings->less.texture);
}

static void sprite(settings_t *settings)
{
    sfSprite_destroy(settings->settings.sprite);
    sfSprite_destroy(settings->back.sprite);
    sfSprite_destroy(settings->full_case.sprite);
    sfSprite_destroy(settings->full_check.sprite);
    sfSprite_destroy(settings->vsync_case.sprite);
    sfSprite_destroy(settings->vsync_check.sprite);
    sfSprite_destroy(settings->res_case.sprite);
    sfSprite_destroy(settings->frame_case.sprite);
    sfSprite_destroy(settings->more.sprite);
    sfSprite_destroy(settings->less.sprite);
}

static void text(settings_t *settings)
{
    sfFont_destroy(settings->font);
    sfFont_destroy(settings->font_num);
    sfText_destroy(settings->back_t);
    sfText_destroy(settings->full_t);
    sfText_destroy(settings->vsync_t);
    sfText_destroy(settings->res_t);
    sfText_destroy(settings->frame_t);
    sfText_destroy(settings->musics);
    sfText_destroy(settings->more_t);
    sfText_destroy(settings->less_t);
    sfText_destroy(settings->volume);
}

void destroy_settings(settings_t *settings)
{
    texture(settings);
    sprite(settings);
    text(settings);
}
