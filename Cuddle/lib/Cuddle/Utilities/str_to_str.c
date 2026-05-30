/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Returns a string value as-is (passthrough type conversion)
*/
/**
 * @file str_to_str.c
 * @brief Returns a string value as-is (passthrough type conversion)
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <stdlib.h>
#include <string.h>

void *str_to_str(char *data)
{
    char *str = NULL;

    if (!data)
        return NULL;
    str = strdup(data);
    if (!str)
        return NULL;
    return str;
}
