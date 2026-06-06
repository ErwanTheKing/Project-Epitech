/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The text_main.c
*/
/**
 * @file text_main.c
 * @brief The text_main.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../include/includes.h"

int my_strlen(char *str)
{
    int count = 0;

    for (; str[count] != '\0'; count++);
    return count;
}

static void text_highscore(button_main_t *manage_sprite)
{
    manage_sprite->font = sfFont_createFromFile("asset/font/font.ttf");
    if (!manage_sprite->font)
        return;
    manage_sprite->highscore = sfText_create();
    sfText_setFont(manage_sprite->highscore, manage_sprite->font);
    sfText_setString(manage_sprite->highscore, "HIGHSCORE :");
    sfText_setColor(manage_sprite->highscore, sfCyan);
    sfText_setCharacterSize(manage_sprite->highscore, 10);
    sfText_setPosition(manage_sprite->highscore, (sfVector2f){65, 530});
}

static void text_highscore_nb(button_main_t *manage_sprite)
{
    if (!manage_sprite->font) {
        return;
    }
    manage_sprite->score = sfText_create();
    sfText_setFont(manage_sprite->score, manage_sprite->font);
    sfText_setString(manage_sprite->score, NULL);
    sfText_setColor(manage_sprite->score, sfCyan);
    sfText_setCharacterSize(manage_sprite->score, 10);
    sfText_setPosition(manage_sprite->score, (sfVector2f){225, 530});
}

void create_text_main(button_main_t *manage_sprite)
{
    text_highscore(manage_sprite);
    text_highscore_nb(manage_sprite);
}
