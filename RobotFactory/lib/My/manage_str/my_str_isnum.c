/*
** EPITECH PROJECT, 2025
** is,um
** File description:
** isnum
*/

#include "../headers/my.h"

int my_str_isnum(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return SUCCESS;
    }
    return 1;
}
