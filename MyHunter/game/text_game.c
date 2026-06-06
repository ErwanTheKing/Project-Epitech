/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The text_game.c
*/
/**
 * @file text_game.c
 * @brief The text_game.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../include/includes.h"

long long int my_compute_power_rec(long long int nb, long long int p)
{
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    return (nb * my_compute_power_rec(nb, p - 1));
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    return (s1[i] - s2[i]);
}

static int len_nb(int nb)
{
    int count = 0;

    for (; nb > 0; count++)
        nb = nb / 10;
    return count;
}

char *my_nbr_to_str(int nb)
{
    int nw_nb = 0;
    int nw_nb2 = nb;
    int count = len_nb(nw_nb2);
    char *str;
    int i = 0;

    if (count == 0)
        count++;
    str = malloc(sizeof(char) * (count + 1));
    if (!str)
        return NULL;
    str[count] = '\0';
    for (i = 0; count > 0; i++) {
        nw_nb = (nb / my_compute_power_rec(10, count - 1)) - (nw_nb * 10);
        str[i] = nw_nb + 48;
        nw_nb = nb / my_compute_power_rec(10, count - 1);
        count--;
    }
    return str;
}

static int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int my_getnbr(char const *str)
{
    long long int j = 0;
    int signe = 1;
    int a;

    for (a = 0; is_num(str[a]) == 0 && str[a] != '\0'; a++) {
        if (str[a] == '-')
            signe *= -1;
    }
    for (int i = a; is_num(str[i]) == 1 && str[i] != '\0'; i++) {
        if (str[i + 1] != '+' || str[i + 1] != '-') {
            j = (j * 10) + (str[i] - 48);
        }
        if ((j > 2147483647 || j < -2147483648)
            && (j * signe < -2147483648 || j * signe > 2147483647))
            return 0;
    }
    j = j * signe;
    return j;
}

static void create_score(manage_sprite_t *manage_sprite)
{
    manage_sprite->font = sfFont_createFromFile("asset/font/font.ttf");
    if (!manage_sprite->font)
        return;
    manage_sprite->score = sfText_create();
    sfText_setFont(manage_sprite->score, manage_sprite->font);
    sfText_setString(manage_sprite->score, "SCORE :");
    sfText_setColor(manage_sprite->score, sfCyan);
    sfText_setCharacterSize(manage_sprite->score, 10);
    sfText_setPosition(manage_sprite->score, (sfVector2f){65, 530});
}

static void create_score_nb(manage_sprite_t *manage_sprite)
{
    if (!manage_sprite->font) {
        return;
    }
    manage_sprite->score_nb = sfText_create();
    sfText_setFont(manage_sprite->score_nb, manage_sprite->font);
    sfText_setString(manage_sprite->score_nb, NULL);
    sfText_setColor(manage_sprite->score_nb, sfCyan);
    sfText_setCharacterSize(manage_sprite->score_nb, 10);
    sfText_setPosition(manage_sprite->score_nb, (sfVector2f){160, 530});
}

void create_text_game(manage_sprite_t *manage_sprite)
{
    create_score(manage_sprite);
    create_score_nb(manage_sprite);
}
