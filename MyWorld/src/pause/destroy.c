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

static void texture(pause_t *pause)
{
    sfTexture_destroy(pause->resume.texture);
    sfTexture_destroy(pause->settings.texture);
    sfTexture_destroy(pause->quit.texture);
    sfTexture_destroy(pause->main.texture);
}

static void sprite(pause_t *pause)
{
    sfSprite_destroy(pause->resume.sprite);
    sfSprite_destroy(pause->settings.sprite);
    sfSprite_destroy(pause->quit.sprite);
    sfSprite_destroy(pause->main.sprite);
}

static void text(pause_t *pause)
{
    sfText_destroy(pause->resume_t);
    sfText_destroy(pause->settings_t);
    sfText_destroy(pause->quit_t);
    sfText_destroy(pause->main_t);
}

void destroy_pause(pause_t *pause)
{
    texture(pause);
    sprite(pause);
    text(pause);
}
