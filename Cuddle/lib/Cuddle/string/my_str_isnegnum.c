/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** my_str_isnegnum
*/

#include "../../Headers/my.h"

int my_str_isnegnum(char const *str)
{
    int i = 0;

    if (str[0] != '-')
        return FAILURE;
    i++;
    if (str[i] == '\0')
        return FAILURE;
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return FAILURE;
    }
    return SUCCESS;
}
