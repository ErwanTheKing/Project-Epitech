/*
** EPITECH PROJECT, 2026
** init
** File description:
** init sound/music
*/

#include "../../include/wolf3d.h"

sfSound *create_sound(sfSoundBuffer **buffer, char *filepath)
{
    sfSound *sound;

    *buffer = sfSoundBuffer_createFromFile(filepath);
    if (!*buffer)
        return NULL;
    sound = sfSound_create();
    if (!sound) {
        sfSoundBuffer_destroy(*buffer);
        *buffer = NULL;
        return NULL;
    }
    sfSound_setBuffer(sound, *buffer);
    return sound;
}

void play_sound(sfSound *sound)
{
    if (!sound)
        return;
    if (sfSound_getStatus(sound) == sfPlaying)
        sfSound_stop(sound);
    sfSound_play(sound);
}

wolf_t *init_music(wolf_t *wolf, int index, const char *filepath)
{
    wolf->music.music[index] = sfMusic_createFromFile(filepath);
    if (!wolf->music.music[index])
        return NULL;
    sfMusic_setVolume(wolf->music.music[index], 30.f);
    return wolf;
}

void play_music(sfMusic *music)
{
    if (!music)
        return;
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
}

wolf_t *init_sound_effect(wolf_t *wolf)
{
    wolf->music.sound[0] =
        create_sound(&wolf->music.buffer[0], "assets/gunshot.wav");
    if (!wolf->music.sound[0])
        return NULL;
    wolf->music.sound[2] =
        create_sound(&wolf->music.buffer[2], "assets/vacuum.wav");
    if (!wolf->music.sound[2])
        return NULL;
    wolf->music.sound[1] =
        create_sound(&wolf->music.buffer[1], "assets/shotgun.wav");
    if (!wolf->music.sound[1])
        return NULL;
    if (!init_music(wolf, 0, "assets/main_bg.mp3"))
        return NULL;
    play_music(wolf->music.music[0]);
    return wolf;
}
