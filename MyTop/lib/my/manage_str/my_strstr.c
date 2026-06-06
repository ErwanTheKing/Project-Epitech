/*
** EPITECH PROJECT, 2025
** my_strstr
** File description:
** strstr
*/

#include <stddef.h>

#include "../headers/my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    if (to_find[0] == '\0')
        return str;
    for (; str[i] != '\0'; i++) {
        j = 0;
        for (; to_find[j] != '\0' && str[i + j] == to_find[j]; j++);
        if (to_find[j] == '\0')
            return &str[i];
    }
    return NULL;
}
