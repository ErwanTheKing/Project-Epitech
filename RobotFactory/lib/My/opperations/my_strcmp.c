/*
** EPITECH PROJECT, 2025
** my_strcomp
** File description:
** comp
*/

#include "../headers/my.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    if (s1[0] == '.')
        i++;
    if (s2[0] == '.')
        j++;
    while (s1[i] == s2[j] && s1[i] != '\0') {
        i++;
        j++;
    }
    return (s1[i] - s2[j]);
}
