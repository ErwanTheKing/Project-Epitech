/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** rev str
*/

#include "../../Headers/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char a;

    if (str == NULL)
        return NULL;
    while (str[i + 1] != '\0')
        i++;
    while (j < i) {
        a = str[j];
        str[j] = str[i];
        str[i] = a;
        j++;
        i--;
    }
    return (str);
}
