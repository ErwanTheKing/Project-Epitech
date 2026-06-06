/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The text_settings.c
*/
/**
 * @file text_settings.c
 * @brief The text_settings.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

static void text_music(button_setting_t *manage_button)
{
    manage_button->music_t.font = sfFont_createFromFile("asset/font/font.ttf");
    if (!manage_button->music_t.font)
        return;
    manage_button->music_t.text = sfText_create();
    sfText_setFont(manage_button->music_t.text, manage_button->music_t.font);
    sfText_setString(manage_button->music_t.text, "MUSIC VOLUME");
    sfText_setCharacterSize(manage_button->music_t.text, 20);
    sfText_setPosition(manage_button->music_t.text, (sfVector2f){180, 200});
}

static void text_resolution(button_setting_t *manage_button)
{
    if (!manage_button->music_t.font)
        return;
    manage_button->resolution = sfText_create();
    sfText_setFont(manage_button->resolution,
        manage_button->music_t.font);
    sfText_setString(manage_button->resolution, "RESOLUTION");
    sfText_setCharacterSize(manage_button->resolution, 20);
    sfText_setPosition(manage_button->resolution, (sfVector2f){180, 260});
}

static void text_vsync(button_setting_t *manage_button)
{
    if (!manage_button->music_t.font)
        return;
    manage_button->vsync = sfText_create();
    sfText_setFont(manage_button->vsync,
        manage_button->music_t.font);
    sfText_setString(manage_button->vsync, "VSYNC");
    sfText_setCharacterSize(manage_button->vsync, 20);
    sfText_setPosition(manage_button->vsync, (sfVector2f){180, 320});
}

static void text_fps(button_setting_t *manage_button)
{
    if (!manage_button->music_t.font)
        return;
    manage_button->fps = sfText_create();
    sfText_setFont(manage_button->fps,
        manage_button->music_t.font);
    sfText_setString(manage_button->fps, "FPS");
    sfText_setCharacterSize(manage_button->fps, 20);
    sfText_setPosition(manage_button->fps, (sfVector2f){180, 380});
}

void create_text_settings(button_setting_t *manage_button)
{
    text_music(manage_button);
    text_resolution(manage_button);
    text_vsync(manage_button);
    text_fps(manage_button);
}
