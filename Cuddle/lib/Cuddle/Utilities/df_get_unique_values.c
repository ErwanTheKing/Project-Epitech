/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Retrieves all unique (deduplicated) values from a specified column
*/
/**
 * @file df_get_unique_values.c
 * @brief Retrieves all unique (deduplicated) values from a specified column
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <string.h>
#include <unistd.h>
#include "../../Headers/dataframe.h"

static int in_array(void *data, void **array, int count, column_type_t type)
{
    size_t size_of_type[] = { sizeof(bool), sizeof(int), sizeof(unsigned int),
        sizeof(float), sizeof(char *)};

    for (int i = 0; i < count; i++) {
        if (type == STRING && strcmp((char *)data, (char *)array[i]) == 0)
            return FAILURE;
        if (type != STRING && memcmp(data, array[i], size_of_type[type]) == 0)
            return FAILURE;
    }
    return SUCCESS;
}

static void fill_array(dataframe_t *dataframe, int i, void **array)
{
    void *(*fcall[])(char *) = {str_to_bool, str_to_int, str_to_unsigned_int,
        str_to_float, str_to_str};
    void *data = NULL;
    int k = 0;

    for (int j = 1; j < dataframe->nb_rows + 1; j++) {
        if (!dataframe->data[j][i])
            continue;
        data = fcall[((infos_data_t *)dataframe->data[0][i])->type]
            (dataframe->data[j][i]);
        if (in_array(data, array, k,
                ((infos_data_t *)dataframe->data[0][i])->type) == SUCCESS) {
            array[k] = data;
            k++;
        } else {
            free(data);
        }
    }
    array[k] = NULL;
}

void **df_get_unique_values(dataframe_t *dataframe, const char *column)
{
    void **array = NULL;

    if (!dataframe)
        return NULL;
    array = calloc(dataframe->nb_rows + 1, sizeof(void *));
    if (!array)
        return NULL;
    for (int i = 0; (infos_data_t *)dataframe->data[0][i]; i++) {
        if (strcmp(((infos_data_t *)dataframe->data[0][i])->data, column)
            == 0) {
            fill_array(dataframe, i, array);
            return array;
        }
    }
    write(2, column, strlen(column));
    write(2, " is not in csv\n", 15);
    return NULL;
}
