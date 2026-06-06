/*
** EPITECH PROJECT, 2025
** strcat
** File description:
** cat
*/

#include <stdlib.h>

#include "../headers/my.h"

char *concat(char *new, char *src, int i)
{
    if (src) {
        for (int j = 0; src[j] != '\0'; j++) {
            new[i] = src[j];
            i++;
        }
    }
    new[i] = '\0';
    return new;
}

char *my_strconcat(char *dest, char *src)
{
    int i = 0;
    char *new = NULL;
    int len_dest = 0;
    int len_src = 0;

    if (dest)
        len_dest = my_strlen(dest);
    if (src)
        len_src = my_strlen(src);
    new = malloc(sizeof(char) * (len_dest + len_src + 1));
    if (!new)
        return NULL;
    if (dest) {
        for (i = 0; dest[i] != '\0'; i++)
            new[i] = dest[i];
    }
    new = concat(new, src, i);
    return new;
}
