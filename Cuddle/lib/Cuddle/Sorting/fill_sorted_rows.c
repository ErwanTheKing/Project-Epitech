/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** fill_sorted_rows
*/

#include "../../Headers/dataframe.h"

int fill_sorted_rows(void ***rows, const dataframe_t *df, const int cols)
{
    int i = 0;

    while (i < df->nb_rows) {
        rows[i] = dup_row(df->data[i + 1], cols, false);
        if (!rows[i]) {
            free_rows(rows, i, cols, false);
            return FAILURE;
        }
        i++;
    }
    rows[df->nb_rows] = NULL;
    return SUCCESS;
}
