/*
** EPITECH PROJECT, 2026
** amazedd
** File description:
** my_strn
*/

#include "my.h"

char *my_strn(char *str, char flag)
{
    int i = 0;

    if (str[0] == '#' && str[1] == '#')
        i = 2;
    for (; str[i] != '\0'; i++) {
        if (str[i] == flag) {
            str[i] = '\0';
            return str;
        }
    }
    return str;
}
