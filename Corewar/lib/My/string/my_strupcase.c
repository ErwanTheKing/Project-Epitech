/*
** EPITECH PROJECT, 2025
** my_strupcase
** File description:
** upcase
*/

#include "../../Headers/my.h"

char *my_strupcase(char *str)
{
    int i;

    if (str == NULL)
        return NULL;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return (str);
}
