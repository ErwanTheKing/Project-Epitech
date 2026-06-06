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

static void texture(main_menu_t *main_menu)
{
    sfTexture_destroy(main_menu->background.texture);
    sfTexture_destroy(main_menu->start.texture);
    sfTexture_destroy(main_menu->settings.texture);
    sfTexture_destroy(main_menu->quit.texture);
    sfTexture_destroy(main_menu->logo.texture);
    sfTexture_destroy(main_menu->cursor.texture);
}

static void sprite(main_menu_t *main_menu)
{
    sfSprite_destroy(main_menu->background.sprite);
    sfSprite_destroy(main_menu->start.sprite);
    sfSprite_destroy(main_menu->settings.sprite);
    sfSprite_destroy(main_menu->quit.sprite);
    sfSprite_destroy(main_menu->logo.sprite);
    sfSprite_destroy(main_menu->cursor.sprite);
}

void destroy_main(main_menu_t *main_menu)
{
    texture(main_menu);
    sprite(main_menu);
}
