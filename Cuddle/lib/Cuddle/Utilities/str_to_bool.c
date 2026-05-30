/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Converts a string value to a heap-allocated boolean (true/false)
*/
/**
 * @file str_to_bool.c
 * @brief Converts a string value to a heap-allocated boolean (true/false)
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <stdlib.h>
#include "../../Headers/my.h"
#include <stdbool.h>

void *str_to_bool(char *data)
{
    char *tmp = NULL;
    bool *b = NULL;

    if (!data)
        return NULL;
    b = calloc(1, sizeof(bool));
    if (!b)
        return NULL;
    tmp = my_strlowcase(my_strdup(data, 0));
    if (!tmp) {
        free(b);
        return NULL;
    }
    *b = my_strcmp(tmp, "true") == 0 ? 1 : 0;
    free(tmp);
    return b;
}
