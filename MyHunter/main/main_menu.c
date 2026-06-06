/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The main_menu.c
*/
/**
 * @file main_menu.c
 * @brief The main_menu.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../include/includes.h"

static void execute(sfRenderWindow *window, sfSprite *sprite,
    button_main_t *manage_button)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, manage_button->play.sprite, NULL);
    sfRenderWindow_drawSprite(window, manage_button->settings.sprite, NULL);
    sfRenderWindow_drawSprite(window, manage_button->exit.sprite, NULL);
    sfRenderWindow_drawSprite(window, manage_button->bg_score.sprite, NULL);
    sfRenderWindow_drawText(window, manage_button->highscore, NULL);
    sfRenderWindow_drawText(window, manage_button->score, NULL);
    sfRenderWindow_display(window);
}

static void manage_event(sfRenderWindow *window,
    button_main_t *manage_button, music_t *music, bool_t *bool)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            click_settings(manage_button->settings.sprite, window, music, bool);
            click_exit(manage_button->exit.sprite, window);
            click_play(manage_button->play.sprite, window, music, bool);
        }
    }
}

static void manage_music(music_t *music)
{
    music->music = sfMusic_createFromFile("asset/sound/mainmenu.mp3");
    if (!music->music)
        return;
    sfMusic_play(music->music);
    sfMusic_setLoop(music->music, sfTrue);
    sfMusic_setVolume(music->music, 50);
}

static sprite_t *manage_background(button_main_t *manage_button)
{
    sprite_t *background = malloc(sizeof(sprite_t));

    background->texture = sfTexture_createFromFile("asset/bg/mainmenu.jpg",
        NULL);
    if (!background->texture)
        return NULL;
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    sfSprite_setPosition(background->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(background->sprite, (sfVector2f){0.6f, 0.6f});
    create_button_main(manage_button);
    return background;
}

static void destroy_button(button_main_t *manage_button, sprite_t *background)
{
    sfSprite_destroy(background->sprite);
    sfTexture_destroy(background->texture);
    sfSprite_destroy(manage_button->play.sprite);
    sfTexture_destroy(manage_button->play.texture);
    sfSprite_destroy(manage_button->settings.sprite);
    sfTexture_destroy(manage_button->settings.texture);
    sfSprite_destroy(manage_button->exit.sprite);
    sfTexture_destroy(manage_button->exit.texture);
    sfSprite_destroy(manage_button->bg_score.sprite);
    sfTexture_destroy(manage_button->bg_score.texture);
    sfFont_destroy(manage_button->font);
    sfText_destroy(manage_button->highscore);
    sfText_destroy(manage_button->score);
    free(background);
    free(manage_button);
}

void manage_highscore(bool_t *bool)
{
    int fd = open("game/highscore.txt", O_RDONLY);
    int nb_bytes = 0;

    if (!fd)
        return;
    nb_bytes = read(fd, bool->highscore, 1000);
    bool->highscore[nb_bytes] = '\0';
    close(fd);
}

int main_menu(sfRenderWindow *window, music_t *music, bool_t *bool)
{
    button_main_t *manage_button = malloc(sizeof(button_main_t));
    sprite_t *background = NULL;

    if (!manage_button)
        return EXIT_F;
    background = manage_background(manage_button);
    create_text_main(manage_button);
    manage_highscore(bool);
    sfText_setString(manage_button->score, bool->highscore);
    bool->game_on = 0;
    bool->pause_on = 0;
    bool->settings_on = 0;
    bool->settings_game = 0;
    while (sfRenderWindow_isOpen(window)) {
        manage_event(window, manage_button, music, bool);
        execute(window, background->sprite, manage_button);
    }
    destroy_button(manage_button, background);
    return EXIT_SUCCESS;
}

void manage_snowball(music_t *music)
{
    music->snowball = sfMusic_createFromFile("asset/sound/snowball.wav");
    if (!music->snowball)
        return;
    sfMusic_setVolume(music->snowball, 50);
    manage_music(music);
}

int create_window(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "my_hunter",
        sfTitlebar | sfClose, NULL);
    bool_t *bool = malloc(sizeof(bool_t));
    music_t *music = malloc(sizeof(music_t));

    manage_snowball(music);
    if (!window || !bool)
        return EXIT_F;
    bool->res_on = sfTrue;
    bool->vsync_on = sfTrue;
    bool->fps_on = 1;
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    main_menu(window, music, bool);
    sfMusic_destroy(music->music);
    sfMusic_destroy(music->snowball);
    free(bool->str_count);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
