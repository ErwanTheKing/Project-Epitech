/*
** EPITECH PROJECT, 2025
** isprintable
** File description:
** isprintable
*/

#include "../headers/my.h"

int my_str_isprintable(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < '!' || str[i] > '~')
            return SUCCESS;
    }
    return 1;
}
