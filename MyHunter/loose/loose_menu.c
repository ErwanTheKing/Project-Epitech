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

#include "../include/includes.h"

static void manage_event(sfRenderWindow *window, button_loose_t *manage_sprite,
    bool_t *bool, music_t *music)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            click_retry(manage_sprite->retry.sprite, window, music, bool);
            click_mainmenu_loose(manage_sprite->mainmenu.sprite, window, music,
                bool);
        }
    }
}

static void destroy_loose(button_loose_t *manage_sprite)
{
    sfSprite_destroy(manage_sprite->background.sprite);
    sfTexture_destroy(manage_sprite->background.texture);
    sfSprite_destroy(manage_sprite->retry.sprite);
    sfTexture_destroy(manage_sprite->retry.texture);
    sfSprite_destroy(manage_sprite->mainmenu.sprite);
    sfTexture_destroy(manage_sprite->mainmenu.texture);
    free(manage_sprite);
}

int loose_menu(sfRenderWindow *window, bool_t *bool, music_t *music)
{
    button_loose_t *manage_sprite = malloc(sizeof(struct button_loose_s));

    if (!manage_sprite)
        return EXIT_F;
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    create_sprite_loose(manage_sprite);
    while (sfRenderWindow_isOpen(window)) {
        manage_event(window, manage_sprite, bool, music);
        sfRenderWindow_drawSprite(window,
            manage_sprite->background.sprite, NULL);
        sfRenderWindow_drawSprite(window, manage_sprite->retry.sprite, NULL);
        sfRenderWindow_drawSprite(window, manage_sprite->mainmenu.sprite, NULL);
        sfRenderWindow_display(window);
    }
    destroy_loose(manage_sprite);
    return EXIT_S;
}
