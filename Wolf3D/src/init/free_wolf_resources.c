/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** wolf resource cleanup helpers
*/

#include "../../include/wolf3d.h"

static void free_window_data(window_t *window_data)
{
    if (window_data) {
        if (window_data->window)
            sfRenderWindow_destroy(window_data->window);
        free(window_data);
    }
}

static void free_music(music_t *music)
{
    if (!music)
        return;
    for (int i = 0; i < 3; i++) {
        if (music->sound[i])
            sfSound_destroy(music->sound[i]);
        if (music->buffer[i])
            sfSoundBuffer_destroy(music->buffer[i]);
    }
    for (int i = 0; i < 2; i++) {
        if (music->music[i])
            sfMusic_destroy(music->music[i]);
    }
}

void free_wolf_resources(wolf_t *wolf)
{
    if (!wolf)
        return;
    if (wolf->brightness_shader)
        sfShader_destroy(wolf->brightness_shader);
    free_window_data(wolf->window_data);
    if (wolf->fps_text)
        sfText_destroy(wolf->fps_text);
    if (wolf->fps_clock)
        sfClock_destroy(wolf->fps_clock);
    free_music(&wolf->music);
    if (wolf->data && wolf->data->font)
        sfFont_destroy(wolf->data->font);
}
