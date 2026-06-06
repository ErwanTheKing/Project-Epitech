/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** my_free
*/

#include "my.h"

int my_free(void **pointer, int max, int exit)
{
    for (int i = 0; i < max; i++) {
        if (pointer[i]) {
            free(pointer[i]);
            pointer[i] = NULL;
        }
    }
    return exit;
}

void *my_free_void(void **pointer, int max, void *exit)
{
    for (int i = 0; i < max; i++) {
        if (pointer[i]) {
            free(pointer[i]);
            pointer[i] = NULL;
        }
    }
    return exit;
}
