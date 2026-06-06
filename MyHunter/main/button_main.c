/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The button.c
*/
/**
 * @file button.c
 * @brief The button.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

static void button_play(button_main_t *manage_button)
{
    manage_button->play.texture
    = sfTexture_createFromFile("asset/button/play.jpg", NULL);
    manage_button->play.sprite = sfSprite_create();
    if (!manage_button->play.texture)
        return;
    sfSprite_setTexture(manage_button->play.sprite,
        manage_button->play.texture, sfTrue);
    sfSprite_setPosition(manage_button->play.sprite, (sfVector2f){340, 200});
    sfSprite_setScale(manage_button->play.sprite, (sfVector2f){0.3f, 0.3f});
}

static void button_settings(button_main_t *manage_button)
{
    manage_button->settings.texture
    = sfTexture_createFromFile("asset/button/settings.jpg", NULL);
    manage_button->settings.sprite = sfSprite_create();
    if (!manage_button->settings.texture)
        return;
    sfSprite_setTexture(manage_button->settings.sprite,
        manage_button->settings.texture, sfTrue);
    sfSprite_setPosition(manage_button->settings.sprite,
        (sfVector2f){328, 270});
    sfSprite_setScale(manage_button->settings.sprite, (sfVector2f){0.3f, 0.3f});
}

static void button_exit(button_main_t *manage_button)
{
    manage_button->exit.texture
    = sfTexture_createFromFile("asset/button/exit.jpg", NULL);
    manage_button->exit.sprite = sfSprite_create();
    if (!manage_button->exit.texture)
        return;
    sfSprite_setTexture(manage_button->exit.sprite,
        manage_button->exit.texture, sfTrue);
    sfSprite_setPosition(manage_button->exit.sprite, (sfVector2f){340, 340});
    sfSprite_setScale(manage_button->exit.sprite, (sfVector2f){0.3f, 0.3f});
}

static void creat_bg_score(button_main_t *manage_sprite)
{
    manage_sprite->bg_score.texture
    = sfTexture_createFromFile("asset/button/score.jpg", NULL);
    if (!manage_sprite->bg_score.texture)
        return;
    manage_sprite->bg_score.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->bg_score.sprite,
        manage_sprite->bg_score.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->bg_score.sprite,
        (sfVector2f){50, 510});
    sfSprite_setScale(manage_sprite->bg_score.sprite,
        (sfVector2f){0.3f, 0.2f});
}

void create_button_main(button_main_t *manage_button)
{
    button_play(manage_button);
    button_settings(manage_button);
    button_exit(manage_button);
    creat_bg_score(manage_button);
}
