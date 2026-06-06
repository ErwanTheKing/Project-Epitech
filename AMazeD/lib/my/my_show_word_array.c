/*
** EPITECH PROJECT, 2025
** str array
** File description:
** display array
*/

#include "my.h"

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != 0; i++)
        my_putstr(tab[i]);
    return 0;
}
