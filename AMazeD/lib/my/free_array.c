/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** free_array
*/

#include "my.h"

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != 0; i++) {
        free(array[i]);
    }
    free(array);
}

void free_array_void(void *data)
{
    char **array = data;

    if (array == NULL)
        return;
    for (int i = 0; array[i] != 0; i++) {
        free(array[i]);
    }
    free(array);
}
