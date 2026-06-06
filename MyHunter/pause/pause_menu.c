/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The pause_menu.c
*/
/**
 * @file pause_menu.c
 * @brief The pause_menu.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

static void destroy_pause(button_pause_t *manage_button)
{
    sfSprite_destroy(manage_button->pause.sprite);
    sfTexture_destroy(manage_button->pause.texture);
    sfSprite_destroy(manage_button->resume.sprite);
    sfTexture_destroy(manage_button->resume.texture);
    sfSprite_destroy(manage_button->restart.sprite);
    sfTexture_destroy(manage_button->restart.texture);
    sfSprite_destroy(manage_button->settings.sprite);
    sfTexture_destroy(manage_button->settings.texture);
    sfSprite_destroy(manage_button->mainmenu.sprite);
    sfTexture_destroy(manage_button->mainmenu.texture);
    sfSprite_destroy(manage_button->exit.sprite);
    sfTexture_destroy(manage_button->exit.texture);
    free(manage_button);
}

static int manage_event2(sfRenderWindow *window, music_t *music,
    button_pause_t *manage_button, bool_t *bool)
{
    if (bool->event.type == sfEvtMouseButtonPressed
        && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (click_resume(manage_button->resume.sprite, window) == -1)
            return -1;
        click_exit(manage_button->exit.sprite, window);
        click_mainmenu(manage_button->mainmenu.sprite, window, music, bool);
        click_settings(manage_button->settings.sprite, window, music, bool);
        if (bool->mode == 0)
            click_renaud(manage_button->restart.sprite, window, music, bool);
        else
            click_eric(manage_button->restart.sprite, window, music, bool);
    }
    return 0;
}

static int manage_event(sfRenderWindow *window, music_t *music,
    button_pause_t *manage_button, bool_t *bool)
{
    while (sfRenderWindow_pollEvent(window, &bool->event)) {
        if (bool->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (bool->event.type == sfEvtKeyPressed
            && sfKeyboard_isKeyPressed(sfKeyEscape))
            return -1;
        if (manage_event2(window, music, manage_button, bool) == -1)
            return -1;
    }
    return 0;
}

static void execute(sfRenderWindow *window, button_pause_t *manage_button)
{
    sfRenderWindow_drawSprite(window, manage_button->pause.sprite, NULL);
    sfRenderWindow_drawSprite(window, manage_button->resume.sprite, NULL),
    sfRenderWindow_drawSprite(window, manage_button->restart.sprite, NULL),
    sfRenderWindow_drawSprite(window, manage_button->settings.sprite, NULL),
    sfRenderWindow_drawSprite(window, manage_button->mainmenu.sprite, NULL),
    sfRenderWindow_drawSprite(window, manage_button->exit.sprite, NULL),
    sfRenderWindow_display(window);
}

int pause_menu(sfRenderWindow *window, music_t *music, bool_t *bool)
{
    button_pause_t *manage_button = malloc(sizeof(button_pause_t));

    if (!manage_button)
        return EXIT_F;
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    create_button_pause(manage_button);
    bool->settings_on = 0;
    bool->pause_on = 1;
    bool->game_on = 0;
    while (sfRenderWindow_isOpen(window)) {
        if (manage_event(window, music, manage_button, bool) == -1
            || bool->settings_on == 1)
            break;
        execute(window, manage_button);
    }
    destroy_pause(manage_button);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return EXIT_SUCCESS;
}
