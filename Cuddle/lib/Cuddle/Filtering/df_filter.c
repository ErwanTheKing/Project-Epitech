/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Filters dataframe rows based on a column predicate function
*/
/**
 * @file df_filter.c
 * @brief Filters dataframe rows based on a column predicate function
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <string.h>
#include "../../Headers/dataframe.h"

static size_t get_type_size(column_type_t type)
{
    if (type == BOOL)
        return sizeof(bool);
    if (type == INT)
        return sizeof(int);
    if (type == UINT)
        return sizeof(unsigned int);
    if (type == FLOAT)
        return sizeof(float);
    return 0;
}

static void free_partial_line(void **arr, int n)
{
    for (int k = 0; k < n; k++)
        free(arr[k]);
    free(arr);
}

static void *dup_cell(void *cell, size_t conv_sz)
{
    void *copy;

    if (conv_sz > 0) {
        copy = malloc(conv_sz);
        if (copy)
            memcpy(copy, cell, conv_sz);
        return copy;
    }
    return strdup(cell);
}

static void **dup_data_line(void **line, int nb_cols,
    int conv_index, size_t conv_sz)
{
    void **new_line = malloc(sizeof(void *) * (nb_cols + 1));

    if (!new_line)
        return NULL;
    for (int i = 0; i < nb_cols; i++) {
        new_line[i] = dup_cell(line[i], (i == conv_index) ? conv_sz : 0);
        if (!new_line[i]) {
            free_partial_line(new_line, i);
            return NULL;
        }
    }
    new_line[nb_cols] = NULL;
    return new_line;
}

static void transfer_valid_lines(dataframe_t *dataframe,
    dataframe_t *filtered_df, int index, size_t conv_sz,
    bool (*filter_func)(void *value))
{
    int nb_cols = dataframe->nb_columns;
    int j = 1;

    filtered_df->data[0] = dup_row(dataframe->data[0], nb_cols, true);
    for (int i = 1; dataframe->data[i]; i++) {
        if (filter_func(dataframe->data[i][index])) {
            filtered_df->data[j] = dup_data_line(dataframe->data[i],
                nb_cols, index, conv_sz);
            j++;
        }
    }
}

static int count_valid_lines(dataframe_t *dataframe, int index,
    bool (*filter_func)(void *value))
{
    int nb_valid_lines = 0;

    for (int i = 1; dataframe->data[i]; i++) {
        if (filter_func(dataframe->data[i][index]))
            nb_valid_lines++;
    }
    return nb_valid_lines;
}

static dataframe_t *init_filtered_df(dataframe_t *dataframe, int nb_valid)
{
    dataframe_t *filtered_df = malloc(sizeof(dataframe_t));

    if (!filtered_df)
        return NULL;
    filtered_df->data = malloc(sizeof(void **) * (nb_valid + 2));
    filtered_df->nb_columns = dataframe->nb_columns;
    filtered_df->nb_rows = nb_valid;
    filtered_df->separator = strdup(dataframe->separator);
    if (!filtered_df->data || !filtered_df->separator) {
        free(filtered_df->data);
        free(filtered_df->separator);
        free(filtered_df);
        return NULL;
    }
    filtered_df->data[nb_valid + 1] = NULL;
    return filtered_df;
}

static dataframe_t *build_filtered(dataframe_t *dataframe,
    dataframe_t *filtered_df, int index, size_t conv_sz,
    bool (*filter_func)(void *value))
{
    transfer_valid_lines(dataframe, filtered_df, index, conv_sz, filter_func);
    reset_collumn_type(dataframe, index);
    return reset_collumn_type(filtered_df, index);
}

dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *value))
{
    int index = get_collumn_index(dataframe, (char *)column);
    int nb_valid_lines;
    dataframe_t *filtered_df;
    size_t conv_sz;

    if (index == -1) {
        fprintf(stderr, "Column '%s' not found in dataframe.\n", column);
        return NULL;
    }
    dataframe = convert_collumn(dataframe, column);
    conv_sz = get_type_size(((infos_data_t *)dataframe->data[0][index])->type);
    nb_valid_lines = count_valid_lines(dataframe, index, filter_func);
    filtered_df = init_filtered_df(dataframe, nb_valid_lines);
    if (!filtered_df)
        return NULL;
    return build_filtered(dataframe, filtered_df, index, conv_sz, filter_func);
}
