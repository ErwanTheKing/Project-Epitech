/*
** EPITECH PROJECT, 2025
** cat strncat
** File description:
** copy n carater
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int comp = my_strlen(dest);
    int ajout = 0;

    for (int i = 0; i != nb; i++){
        dest[comp + i] = src[i];
        ajout++;
    }
    dest[comp + ajout + 1] = '\0';
    return (dest);
}
