/*
** EPITECH PROJECT, 2026
** strcat
** File description:
** strcat
*/

#include "../lib/Headers/factory.h"

char *my_strcat(char *dest, char const *src)
{
    int index = 0;
    int len = my_strlen(dest);

    if (!src)
        return dest;
    for (; src[index] != '\0'; index++) {
        dest[index + len] = src[index];
    }
    dest[index + len] = '\0';
    return dest;
}
