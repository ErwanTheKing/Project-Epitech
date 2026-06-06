/*
** EPITECH PROJECT, 2026
** settings
** File description:
** settings loop
*/

#include "wolf3d.h"

static float clamp_volume(float volume)
{
    if (volume < 0.0f)
        return 0.0f;
    if (volume > 100.0f)
        return 100.0f;
    return volume;
}

static void preview_audio_settings(wolf_t *wolf)
{
    float master;
    float music;
    float sfx;

    if (!wolf || !wolf->tmp_settings)
        return;
    master = clamp_volume((float)wolf->tmp_settings->master_volume);
    music = clamp_volume(master *
        ((float)wolf->tmp_settings->music_volume / 100.0f));
    sfx = clamp_volume(master *
        ((float)wolf->tmp_settings->sfx_volume / 100.0f));
    for (int i = 0; i < 2; i++) {
        if (wolf->music.music[i])
            sfMusic_setVolume(wolf->music.music[i], music);
    }
    for (int i = 0; i < 3; i++) {
        if (wolf->music.sound[i])
            sfSound_setVolume(wolf->music.sound[i], sfx);
    }
}

void settings(wolf_t *wolf)
{
    if (!wolf)
        return;
    if (wolf->settings_state == AUDIO)
        preview_audio_settings(wolf);
}
