/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** my_hunter
*/

#include <stdio.h>

#include "../include/includes.h"

static void verif_time(bool_t *bool, sfRenderWindow *window, music_t *music)
{
    if (bool->touch == sfFalse && bool->currentTime - bool->lastTime >= 0.25f) {
        sfMusic_play(music->snowball);
        click_sprite(window, bool);
        bool->lastTime = bool->currentTime;
    }
    if (bool->touch == sfTrue) {
        sfMusic_play(music->snowball);
        click_sprite(window, bool);
        bool->lastTime = bool->currentTime;
    }
}

static void manage_event(sfRenderWindow *window, music_t *music, bool_t *bool,
    manage_sprite_t *manage_sprite)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed
            && sfKeyboard_isKeyPressed(sfKeyEscape))
            pause_menu(window, music, bool);
        if (bool->settings_on == 1)
            settings_menu(window, music, bool);
        bool->currentTime
        = sfTime_asSeconds(sfClock_getElapsedTime(manage_sprite->clock));
        if (event.type == sfEvtMouseButtonPressed
            && event.mouseButton.button == sfMouseLeft) {
            verif_time(bool, window, music);
        }
    }
}

static void params_hunter(manage_sprite_t *manage_sprite,
    sfRenderWindow *window, bool_t *bool)
{
    manage_sprite->clock = sfClock_create();
    manage_sprite->Time = sfClock_getElapsedTime(manage_sprite->clock);
    manage_sprite->last_Time = sfClock_getElapsedTime(manage_sprite->clock);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    bool->settings_on = 0;
    bool->pause_on = 0;
    bool->game_on = 1;
    bool->count_point = 0;
    bool->life = 5;
    bool->speed = 5;
    bool->ammo = 10;
    bool->lastTime = -2.0f;
    bool->lastTime_bird = 0;
    bool->lastTime_speed = 0;
    bool->lastTime_mov = 0;
    bool->touch = sfTrue;
}

int my_hunter(sfRenderWindow *window, music_t *music, bool_t *bool)
{
    manage_sprite_t *manage_sprite = malloc(sizeof(manage_sprite_t));

    if (!manage_sprite)
        return EXIT_F;
    bool->bird_right = NULL;
    bool->mun = NULL;
    params_hunter(manage_sprite, window, bool);
    create_text_game(manage_sprite);
    create_sprite_game(manage_sprite, window);
    bool->bird_right = create_bird(bool->bird_right);
    bool->mun = add_ammo(bool->mun);
    while (sfRenderWindow_isOpen(window)) {
        manage_event(window, music, bool, manage_sprite);
        dead(bool, window, music);
        execute_hunter(window, manage_sprite, bool);
        sfRenderWindow_display(window);
    }
    destroy_hunter(manage_sprite, bool);
    return EXIT_SUCCESS;
}
