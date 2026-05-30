/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Frees all memory allocated for a dataframe and its contents
*/
/**
 * @file df_free.c
 * @brief Frees all memory allocated for a dataframe and its contents
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include "../../Headers/dataframe.h"

void df_free(dataframe_t *dataframe)
{
    if (dataframe == NULL)
        return;
    for (size_t i = 0; i < dataframe->nb_columns; i++) {
        free(((infos_data_t *)dataframe->data[0][i])->data);
    }
    free_data(dataframe->data);
    if (dataframe->separator)
        free(dataframe->separator);
    free(dataframe);
}
