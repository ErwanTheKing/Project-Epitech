/*
** EPITECH PROJECT, 2025
** my_strlowcase
** File description:
** lowcase
*/

#include <stdlib.h>
#include "my.h"

char *my_strlowcase(char *str)
{
    int i = 0;
    char *str_low = malloc(sizeof(char) * my_strlen(str) + 1);

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str_low[i] = str[i] + 32;
        else
            str_low[i] = str[i];
    }
    str_low[i] = '\0';
    return str_low;
}
