/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Converts a string value to a heap-allocated unsigned integer
*/
/**
 * @file str_to_unsigned_int.c
 * @brief Converts a string value to a heap-allocated unsigned integer
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <stdlib.h>

void *str_to_unsigned_int(char *data)
{
    unsigned int *nbr = NULL;

    if (!data)
        return NULL;
    nbr = calloc(1, sizeof(unsigned int));
    if (!nbr)
        return NULL;
    *nbr = (unsigned int)strtoul(data, NULL, 10);
    return nbr;
}
