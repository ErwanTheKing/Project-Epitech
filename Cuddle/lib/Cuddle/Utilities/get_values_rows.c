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

static int get_size(dataframe_t *dataframe, int i, const char *rows, int index)
{
    int size = 0;

    for (int j = 1; j < dataframe->nb_rows + 1; j++) {
        if (!dataframe->data[j][index])
            continue;
        if (strcmp(rows, dataframe->data[j][index]) == 0) {
            size++;
        }
    }
    return size;
}

static void **fill_array(dataframe_t *dataframe, int i, const char *rows,
    int index)
{
    int j;
    int size = get_size(dataframe, i, rows, index);
    int k = 0;
    void **array = malloc(sizeof(void *) * (size + 1));
    void *(*fcall[])(char *) = {str_to_bool, str_to_int, str_to_unsigned_int,
        str_to_float, str_to_str};

    for (j = 0; j < dataframe->nb_rows + 1; j++) {
        if (!dataframe->data[j][i])
            continue;
        if (j == 0)
            continue;
        if (strcmp(rows, dataframe->data[j][index]) == 0) {
            array[k] = fcall[((infos_data_t *)dataframe->data[0][i])->type]
                (dataframe->data[j][i]);
            k++;
        }
    }
    array[k] = NULL;
    return array;
}

void **get_values_rows(dataframe_t *dataframe, const char *column, char *rows,
    char *agg)
{
    int index = get_collumn_index(dataframe, agg);

    if (!dataframe)
        return NULL;
    for (int i = 0; (infos_data_t *)dataframe->data[0][i]; i++) {
        if (strcmp(((infos_data_t *)dataframe->data[0][i])->data, column)
            == 0) {
            return fill_array(dataframe, i, rows, index);
        }
    }
    write(2, column, strlen(column));
    write(2, " is not in csv\n", 15);
    return NULL;
}
