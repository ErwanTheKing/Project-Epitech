/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Converts a string value to a heap-allocated float
*/
/**
 * @file str_to_float.c
 * @brief Converts a string value to a heap-allocated float
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <stdlib.h>

void *str_to_float(char *data)
{
    float *nbr = NULL;

    if (!data)
        return NULL;
    nbr = calloc(1, sizeof(float));
    if (!nbr)
        return NULL;
    *nbr = atof(data);
    return nbr;
}
