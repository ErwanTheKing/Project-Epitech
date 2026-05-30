/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** free_rows
*/

#include "../../Headers/dataframe.h"

static void free_header_cell(void *cell)
{
    infos_data_t *info = cell;

    if (!info)
        return;
    free(info->data);
    free(info);
}

void free_row(void **row, int cols, bool header)
{
    int i = 0;

    if (!row)
        return;
    while (i < cols) {
        if (header == false)
            free(row[i]);
        if (header == true)
            free_header_cell(row[i]);
        i++;
    }
    free(row);
}
