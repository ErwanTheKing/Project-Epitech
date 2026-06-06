/*
** EPITECH PROJECT, 2025
** my_strncomp
** File description:
** n comp
*/

#include <stdio.h>
#include "../../Headers/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL) {
        if (s1 == s2)
            return 0;
        return (s1 == NULL) ? -1 : 1;
    }
    if (n == 0)
        return SUCCESS;
    while (i < n && s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    if (i == n)
        return 0;
    return (s1[i] - s2[i]);
}
