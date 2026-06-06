/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** my_char_array_dup
*/

#include <stdlib.h>
#include "../headers/my.h"

char **my_char_array_dup(char **array)
{
    int len = my_array_len(array);
    char **dup = malloc(sizeof(char *) * (len + 1));

    if (dup == NULL)
        return NULL;
    for (int i = 0; i < len; i++) {
        dup[i] = my_strdup(array[i], 0);
        if (dup[i] == NULL) {
            free_array(dup);
            return NULL;
        }
    }
    dup[len] = NULL;
    return dup;
}
