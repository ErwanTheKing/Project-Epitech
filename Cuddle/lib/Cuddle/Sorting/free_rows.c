/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** free_rows
*/

#include "../../Headers/dataframe.h"

void free_rows(void ***rows, int count, int cols, bool header)
{
    int i = 0;

    while (i < count) {
        free_row(rows[i], cols, header);
        i++;
    }
    free(rows);
}
