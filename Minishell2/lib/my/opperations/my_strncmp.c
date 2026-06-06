/*
** EPITECH PROJECT, 2025
** my_strncomp
** File description:
** n comp
*/

#include <stdio.h>
#include "../headers/my.h"

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;

    if (!s1 || !s2)
        return 1;
    if (n <= 0)
        return 0;
    while (i < n && s1[i] != '\0' && s1[i] == s2[i])
        i++;
    if (i == n)
        return 0;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
