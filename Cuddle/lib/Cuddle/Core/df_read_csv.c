/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Parses a CSV file and loads its content into a dataframe structure
*/
/**
 * @file df_read_csv.c
 * @brief Parses a CSV file and loads its content into a dataframe structure
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../../Headers/dataframe.h"

static void fill_value(int i, int j, dataframe_t *dataframe, float values)
{
    ((infos_data_t *)dataframe->data[0][j])->type = find_type(dataframe
        ->data[i][j], ((infos_data_t *)dataframe->data[0][j])->type);
    if (((infos_data_t *)dataframe->data[0][j])->type == FLOAT) {
        values = atof(dataframe->data[i][j]);
        snprintf(dataframe->data[i][j], sizeof(dataframe->data[i][j]),
            "%.2f", values);
    }
}

static int fills_infos_in_array(int i, int j, dataframe_t *dataframe,
    char **infos)
{
    float values = 0;

    if (i == 0) {
        dataframe->data[i][j] = malloc(sizeof(infos_data_t));
        if (!dataframe->data[i][j])
            return FAILURE;
        ((infos_data_t *)dataframe->data[0][j])->data = strdup(infos[j]);
        ((infos_data_t *)dataframe->data[0][j])->type = UNDEFINED;
        if (!((infos_data_t *)dataframe->data[i][j])->data) {
            free(dataframe->data[i][j]);
            return FAILURE;
        }
    } else {
        if (!infos[j])
            return -1;
        dataframe->data[i][j] = strdup(infos[j]);
        fill_value(i, j, dataframe, values);
    }
    return SUCCESS;
}

static void fill_null(dataframe_t *dataframe, int i, int j)
{
    for (; j < dataframe->nb_columns; j++)
        dataframe->data[i][j] = NULL;
}

static int fill_array(dataframe_t *dataframe, int i, char **infos)
{
    int j = 0;
    int fill = 0;

    for (j = 0; j < dataframe->nb_columns; j++) {
        fill = fills_infos_in_array(i, j, dataframe, infos);
        if (fill == FAILURE)
            return FAILURE;
        if (fill == -1) {
            fill_null(dataframe, i, j);
            break;
        }
    }
    return SUCCESS;
}

static int fill_data(char **array, int i, const char *sep,
    dataframe_t *dataframe)
{
    char **infos = my_str_to_word_array(array[i], !sep ? "," : sep);

    if (!infos) {
        return FAILURE;
    }
    if (fill_array(dataframe, i, infos) == FAILURE) {
        free_many_arrays(1, infos);
        return FAILURE;
    }
    free_many_arrays(1, infos);
    return SUCCESS;
}

static int handle_data(dataframe_t *dataframe, char **array, const char *sep)
{
    for (int i = 0; i < dataframe->nb_rows + 1; i++) {
        if (get_nbr_columns(array[i], sep) > dataframe->nb_columns) {
            write(2, "In this line, there is"
                "more information than there are columns\n", 63);
            return FAILURE;
        }
        dataframe->data[i] = calloc(dataframe->nb_columns + 1, i == 0 ?
            sizeof(infos_data_t *) :
            sizeof(char *));
        if (!dataframe->data[i]) {
            return FAILURE;
        }
        if (fill_data(array, i, sep, dataframe) == FAILURE) {
            return FAILURE;
        }
    }
    return SUCCESS;
}

static void ***init_data(dataframe_t *dataframe, char **array,
    const char *sep)
{
    dataframe->data = calloc(dataframe->nb_rows + 2, sizeof(void **));
    if (!dataframe->data)
        return NULL;
    if (handle_data(dataframe, array, sep) == FAILURE) {
        free_data(dataframe->data);
        return NULL;
    }
    return dataframe->data;
}

static int get_infos(dataframe_t *dataframe, char **array,
    const char *separator)
{
    dataframe->nb_rows = my_array_len(array) - 1;
    dataframe->nb_columns = get_nbr_columns(array[0], separator);
    if (dataframe->nb_columns == -1)
        return FAILURE;
    dataframe->data = init_data(dataframe, array, separator);
    if (!dataframe->data) {
        return FAILURE;
    }
    return SUCCESS;
}

static int handle_csv(const char *filename, const char *separator,
    dataframe_t *dataframe)
{
    char **array = NULL;
    char *str = openator(filename);

    if (!str)
        return FAILURE;
    array = my_str_to_word_array(str, "\n");
    if (!array) {
        free_many(1, str);
        return FAILURE;
    }
    if (get_infos(dataframe, array, separator) == FAILURE) {
        free_many_arrays(1, array);
        free_many(1, str);
        return FAILURE;
    }
    free_array(array);
    free_many(1, str);
    return SUCCESS;
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    dataframe_t *dataframe = malloc(sizeof(dataframe_t));

    if (!dataframe)
        return NULL;
    dataframe->separator = !separator ? my_strdup(",", 0) :
        my_strdup(separator, 0);
    if (!dataframe->separator)
        return NULL;
    if (handle_csv(filename, separator, dataframe) == FAILURE) {
        free_many(1, dataframe);
        return NULL;
    }
    return dataframe;
}
