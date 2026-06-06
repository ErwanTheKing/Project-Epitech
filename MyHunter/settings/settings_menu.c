/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The menu_settings.c
*/
/**
 * @file menu_settings.c
 * @brief The menu_settings.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../include/includes.h"

static int click(button_setting_t *manage_button, sfRenderWindow *window,
    bool_t *bool, music_t *music)
{
    if (bool->event.type == sfEvtMouseButtonPressed
        && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (click_back(manage_button->back.sprite,
                window, music, bool) == -1)
            return -1;
        click_more(manage_button->more.sprite, window, music);
        click_less(manage_button->less.sprite, window, music);
        click_res(manage_button, window, bool);
        click_vsync(manage_button, window, bool);
        click_fps(manage_button, window, bool);
    }
    return 0;
}

static int key(bool_t *bool)
{
    if (bool->event.type == sfEvtKeyPressed
        && sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (bool->settings_game == 1)
            return -1;
    }
    return 0;
}

static int manage_event(sfRenderWindow *window, music_t *music,
    button_setting_t *manage_button, bool_t *bool)
{
    while (sfRenderWindow_pollEvent(window, &bool->event)) {
        if (bool->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (key(bool) == -1)
            return -1;
        if (click(manage_button, window, bool, music) == -1)
            return -1;
    }
    return 0;
}

static void execute2(sfRenderWindow *window, button_setting_t *manage_button,
    bool_t *bool)
{
    sfRenderWindow_drawSprite(window, manage_button->background.sprite, NULL);
    sfRenderWindow_drawSprite(window, manage_button->settings.sprite, NULL);
    sfRenderWindow_drawSprite(window, manage_button->back.sprite, NULL);
    sfRenderWindow_drawSprite(window, manage_button->more.sprite, NULL);
    sfRenderWindow_drawSprite(window, manage_button->less.sprite, NULL);
    sfRenderWindow_drawText(window, manage_button->music_t.text, NULL);
    sfRenderWindow_drawText(window, manage_button->resolution, NULL);
    if (bool->res_on)
        sfRenderWindow_drawSprite(window, manage_button->res800.sprite, NULL);
    else
        sfRenderWindow_drawSprite(window, manage_button->res1920.sprite, NULL);
    if (bool->vsync_on)
        sfRenderWindow_drawSprite(window, manage_button->enable.sprite, NULL);
    else
        sfRenderWindow_drawSprite(window, manage_button->disable.sprite, NULL);
}

static void execute(sfRenderWindow *window, button_setting_t *manage_button,
    bool_t *bool)
{
    execute2(window, manage_button, bool);
    if (bool->fps_on == 0)
        sfRenderWindow_drawSprite(window, manage_button->fps30.sprite, NULL);
    if (bool->fps_on == 1)
        sfRenderWindow_drawSprite(window, manage_button->fps60.sprite, NULL);
    if (bool->fps_on == 2)
        sfRenderWindow_drawSprite(window, manage_button->fps120.sprite, NULL);
    if (bool->fps_on == 3)
        sfRenderWindow_drawSprite(window, manage_button->unlimited.sprite,
            NULL);
    sfRenderWindow_drawText(window, manage_button->vsync, NULL);
    sfRenderWindow_drawText(window, manage_button->fps, NULL);
    sfRenderWindow_display(window);
}

void destroy_settings2(button_setting_t *manage_button)
{
    sfTexture_destroy(manage_button->fps60.texture);
    sfSprite_destroy(manage_button->fps120.sprite);
    sfTexture_destroy(manage_button->fps120.texture);
    sfSprite_destroy(manage_button->unlimited.sprite);
    sfTexture_destroy(manage_button->unlimited.texture);
    sfText_destroy(manage_button->music_t.text);
    sfFont_destroy(manage_button->music_t.font);
    sfText_destroy(manage_button->resolution);
    sfText_destroy(manage_button->vsync);
    sfText_destroy(manage_button->fps);
    free(manage_button);
}

void destroy_settings(button_setting_t *manage_button)
{
    sfSprite_destroy(manage_button->background.sprite);
    sfTexture_destroy(manage_button->background.texture);
    sfSprite_destroy(manage_button->settings.sprite);
    sfTexture_destroy(manage_button->settings.texture);
    sfSprite_destroy(manage_button->back.sprite);
    sfTexture_destroy(manage_button->back.texture);
    sfSprite_destroy(manage_button->more.sprite);
    sfTexture_destroy(manage_button->more.texture);
    sfSprite_destroy(manage_button->less.sprite);
    sfTexture_destroy(manage_button->less.texture);
    sfSprite_destroy(manage_button->res800.sprite);
    sfTexture_destroy(manage_button->res800.texture);
    sfSprite_destroy(manage_button->enable.sprite);
    sfTexture_destroy(manage_button->enable.texture);
    sfSprite_destroy(manage_button->disable.sprite);
    sfTexture_destroy(manage_button->disable.texture);
    sfSprite_destroy(manage_button->fps30.sprite);
    sfTexture_destroy(manage_button->fps30.texture);
    sfSprite_destroy(manage_button->fps60.sprite);
    destroy_settings2(manage_button);
}

int settings_menu(sfRenderWindow *window, music_t *music, bool_t *bool)
{
    button_setting_t *manage_button = malloc(sizeof(button_setting_t));

    if (!manage_button)
        return EXIT_F;
    create_button_settings(manage_button);
    create_text_settings(manage_button);
    bool->settings_game = 1;
    if (bool->settings_game == 1)
        bool->settings_on = 0;
    bool->pause_on = 0;
    bool->game_on = 0;
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        if (manage_event(window, music, manage_button, bool) == -1)
            break;
        execute(window, manage_button, bool);
    }
    destroy_settings(manage_button);
    return EXIT_SUCCESS;
}
