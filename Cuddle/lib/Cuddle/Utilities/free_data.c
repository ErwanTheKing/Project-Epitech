/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Frees the 3D data array stored inside a dataframe structure
*/
/**
 * @file free_data.c
 * @brief Frees the 3D data array stored inside a dataframe structure
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include "../../Headers/dataframe.h"

void free_data(void ***data)
{
    if (!data)
        return;
    for (int i = 0; data[i]; i++)
        free_many_arrays(1, data[i]);
    free(data);
}
