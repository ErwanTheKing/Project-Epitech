/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Retrieves a single typed value from the dataframe at a given row and column
*/
/**
 * @file df_get_value.c
 * @brief Retrieves a typed value at a given row and column name
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <string.h>
#include <unistd.h>
#include "../../Headers/dataframe.h"

void *df_get_value(dataframe_t *dataframe, int row, const char *column)
{
    void *(*fcall[])(char *) = {str_to_bool, str_to_int, str_to_unsigned_int,
        str_to_float, str_to_str};

    if (!dataframe)
        return NULL;
    if (row >= dataframe->nb_rows) {
        write(2, "Index out of range\n", 19);
        return NULL;
    }
    for (int i = 0; (infos_data_t *)dataframe->data[0][i]; i++) {
        if (strcmp(((infos_data_t *)dataframe->data[0][i])->data, column) == 0)
            return fcall[((infos_data_t *)dataframe->data[0][i])->type]
                (dataframe->data[row + 1][i]);
    }
    write(2, column, strlen(column));
    write(2, " is not in csv\n", 15);
    return NULL;
}
