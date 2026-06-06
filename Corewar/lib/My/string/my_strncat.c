/*
** EPITECH PROJECT, 2025
** strncat
** File description:
** ncat
*/

#include "../../Headers/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int dest_len;
    int i = 0;

    if (dest == NULL || src == NULL)
        return dest;
    dest_len = my_strlen(dest);
    while (src[i] != '\0' && i < nb) {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}
