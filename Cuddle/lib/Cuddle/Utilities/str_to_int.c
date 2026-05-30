/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Converts a string value to a heap-allocated integer
*/
/**
 * @file str_to_int.c
 * @brief Converts a string value to a heap-allocated integer
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <stdlib.h>

void *str_to_int(char *data)
{
    int *nbr = NULL;

    if (!data)
        return NULL;
    nbr = calloc(1, sizeof(int));
    if (!nbr)
        return NULL;
    *nbr = atoi(data);
    return nbr;
}
