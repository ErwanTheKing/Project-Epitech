/*
** EPITECH PROJECT, 2025
** strdup
** File description:
** strdup
*/

#include <stdlib.h>
#include "../headers/my.h"

char *my_strdup(char const *src, int add)
{
    int i = my_strlen(src);
    char *dest;

    dest = malloc(sizeof(char) * (i + 1) + add);
    my_strcpy(dest, src);
    return (dest);
}
