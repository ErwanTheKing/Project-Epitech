/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The loose_menu.c
*/
/**
 * @file loose_menu.c
 * @brief The loose_menu.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../include/includes.h"

static void manage_event(sfRenderWindow *window,
    button_chose_mode_t *manage_sprite, bool_t *bool, music_t *music)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            click_back_chose(manage_sprite->back.sprite, window, music, bool);
            click_eric(manage_sprite->eric.sprite, window, music, bool);
            click_renaud(manage_sprite->renaud.sprite, window, music, bool);
        }
    }
}

static void destroy_sprite_chose(button_chose_mode_t *manage_sprite)
{
    sfSprite_destroy(manage_sprite->background.sprite);
    sfTexture_destroy(manage_sprite->background.texture);
    sfSprite_destroy(manage_sprite->eric.sprite);
    sfTexture_destroy(manage_sprite->eric.texture);
    sfSprite_destroy(manage_sprite->renaud.sprite);
    sfTexture_destroy(manage_sprite->renaud.texture);
    sfSprite_destroy(manage_sprite->back.sprite);
    sfTexture_destroy(manage_sprite->back.texture);
    free(manage_sprite);
}

int chose_mode(sfRenderWindow *window, bool_t *bool, music_t *music)
{
    button_chose_mode_t *manage_sprite = malloc(sizeof(button_chose_mode_t));

    if (!manage_sprite)
        return EXIT_F;
    create_sprite_chose(manage_sprite);
    while (sfRenderWindow_isOpen(window)) {
        manage_event(window, manage_sprite, bool, music);
        sfRenderWindow_drawSprite(window,
            manage_sprite->background.sprite, NULL);
        sfRenderWindow_drawSprite(window, manage_sprite->eric.sprite, NULL);
        sfRenderWindow_drawSprite(window, manage_sprite->renaud.sprite, NULL);
        sfRenderWindow_drawSprite(window, manage_sprite->back.sprite, NULL);
        sfRenderWindow_display(window);
    }
    destroy_sprite_chose(manage_sprite);
    return EXIT_S;
}
