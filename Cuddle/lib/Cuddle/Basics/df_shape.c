/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Returns the number of rows and columns (shape) of the dataframe
*/
/**
 * @file df_shape.c
 * @brief Returns the number of rows and columns (shape) of the dataframe
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include "../../Headers/dataframe.h"

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    if (!dataframe)
        return (dataframe_shape_t){0, 0};
    return (dataframe_shape_t){dataframe->nb_rows, dataframe->nb_columns};
}
