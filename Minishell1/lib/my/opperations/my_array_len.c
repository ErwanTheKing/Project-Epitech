/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** my_array_len
*/

#include <stddef.h>

int my_array_len(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}
