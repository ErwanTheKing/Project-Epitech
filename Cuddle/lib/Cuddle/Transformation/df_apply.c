/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Applies a transformation function to every value of a given column
*/
/**
 * @file df_apply.c
 * @brief Applies a transformation function to every value of a given column
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include "../../Headers/dataframe.h"

dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value))
{
    int index = get_collumn_index(dataframe, (char *)column);
    dataframe_t *copy;

    if (index == -1)
        return NULL;
    copy = df_head(dataframe, dataframe->nb_rows);
    if (!copy)
        return NULL;
    copy = convert_collumn(copy, column);
    if (!copy)
        return NULL;
    for (int i = 1; copy->data[i]; i++) {
        copy->data[i][index] = apply_func(copy->data[i][index]);
    }
    copy = reset_collumn_type(copy, index);
    return copy;
}
