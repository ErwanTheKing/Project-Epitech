/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Retrieves all values from a specified column as a void pointer array
*/
/**
 * @file df_get_values.c
 * @brief Retrieves all values from a specified column as a void pointer array
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <string.h>
#include <unistd.h>
#include "../../Headers/dataframe.h"

static void fill_array(dataframe_t *dataframe, int i, void **array, int j)
{
    void *(*fcall[])(char *) = {str_to_bool, str_to_int, str_to_unsigned_int,
        str_to_float, str_to_str};

    for (j = 0; j < dataframe->nb_rows + 1; j++) {
        if (!dataframe->data[j][i])
            continue;
        if (j == 0)
            continue;
        array[j - 1] = fcall[((infos_data_t *)dataframe->data[0][i])->type]
            (dataframe->data[j][i]);
    }
    array[j - 1] = NULL;
}

void **df_get_values(dataframe_t *dataframe, const char *column)
{
    void **array = NULL;
    int j = 0;

    if (!dataframe)
        return NULL;
    array = malloc(sizeof(void *) * (dataframe->nb_rows + 1));
    if (!array)
        return NULL;
    for (int i = 0; (infos_data_t *)dataframe->data[0][i]; i++) {
        if (strcmp(((infos_data_t *)dataframe->data[0][i])->data, column)
            == 0) {
            fill_array(dataframe, i, array, j);
            return array;
        }
    }
    write(2, column, strlen(column));
    write(2, " is not in csv\n", 15);
    return NULL;
}
