/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Groups rows by a column and aggregates values using a custom function
*/
/**
 * @file df_groupby.c
 * @brief Groups rows by a column and aggregates values using a custom function
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <string.h>
#include "../../Headers/dataframe.h"

static infos_data_t *dup_info(dataframe_t *df, const char *col)
{
    int idx = get_collumn_index(df, (char *)col);
    infos_data_t *info = malloc(sizeof(infos_data_t));

    if (!info)
        return NULL;
    if (idx == -1) {
        free(info);
        return NULL;
    }
    info->data = strdup(((infos_data_t *)df->data[0][idx])->data);
    info->type = ((infos_data_t *)df->data[0][idx])->type;
    return info;
}

static int fill_header_row(groupby_t *group, void ***data)
{
    data[0][0] = dup_info(group->dataframe, group->aggregate_by);
    if (!data[0][0])
        return FAILURE;
    for (int i = 0; group->to_aggregate[i]; i++) {
        data[0][i + 1] = dup_info(group->dataframe, group->to_aggregate[i]);
        if (!data[0][i + 1])
            return FAILURE;
    }
    return SUCCESS;
}

static int init_header(groupby_t *group, void ***data, size_t nb_rows)
{
    size_t nb_cols = my_array_len((char **)group->to_aggregate) + 1;
    size_t total = nb_rows + 1;

    for (size_t i = 0; i < total; i++) {
        data[i] = calloc(nb_cols + 1, i == 0 ? sizeof(infos_data_t *)
            : sizeof(char *));
        if (!data[i]) {
            free_data(data);
            return FAILURE;
        }
    }
    data[nb_rows + 1] = NULL;
    if (fill_header_row(group, data) == FAILURE) {
        for (size_t i = 0; i < total; i++)
            free(data[i]);
        return FAILURE;
    }
    return SUCCESS;
}

static void fill_agg_column(groupby_t *group, void ***data,
    void **array, size_t nb_rows)
{
    int index = get_collumn_index(group->dataframe,
        (char *)group->aggregate_by);
    int type = ((infos_data_t *)group->dataframe->data[0][index])->type;
    char *(*fcall[])(void *) = {bool_to_str, int_to_str, uint_to_str,
        float_to_str, string_to_str};

    for (size_t j = 0; j < nb_rows; j++) {
        if (type == STRING)
            data[j + 1][0] = string_to_str(&array[j]);
        else
            data[j + 1][0] = fcall[type](array[j]);
    }
}

static void fill_cell(cell_t *cell, void **tmp)
{
    int index = get_collumn_index(cell->group->dataframe,
        (char *)cell->group->to_aggregate[cell->i]);
    int type = ((infos_data_t *)cell->group->dataframe->data[0][index])->type;
    char *(*fcall[])(void *) = {bool_to_str, int_to_str, uint_to_str,
        float_to_str, string_to_str};
    void *func = cell->group->agg_func(tmp, my_array_len((char **)tmp));

    if (type == STRING)
        cell->data[cell->j + 1][cell->i + 1] = string_to_str(&func);
    else {
        cell->data[cell->j + 1][cell->i + 1] = fcall[type](func);
        free(func);
    }
}

static void fill_row(groupby_t *group, void ***data, void **array, int i)
{
    void **tmp = NULL;
    cell_t cell = {group, data, i, 0};

    for (size_t j = 0; array[j]; j++) {
        tmp = get_values_rows(group->dataframe, group->to_aggregate[i],
            array[j], (char *)group->aggregate_by);
        if (!tmp)
            continue;
        cell.j = j;
        fill_cell(&cell, tmp);
        free_many_arrays(1, tmp);
    }
}

static void ***get_array(groupby_t *group, void **array, size_t nb_rows)
{
    void ***data = malloc(sizeof(void **) * (nb_rows + 2));

    if (!data)
        return NULL;
    if (init_header(group, data, nb_rows) == FAILURE) {
        free(data);
        return NULL;
    }
    fill_agg_column(group, data, array, nb_rows);
    for (int i = 0; group->to_aggregate[i]; i++)
        fill_row(group, data, array, i);
    return data;
}

static int init_df(groupby_t *group, void **array, dataframe_t *new_df)
{
    size_t nb_column = my_array_len((char **)group->to_aggregate) + 1;
    size_t nb_rows = my_array_len((char **)array);

    new_df->nb_rows = nb_rows;
    new_df->nb_columns = nb_column;
    new_df->separator = strdup(group->dataframe->separator);
    if (!new_df->separator)
        return FAILURE;
    return SUCCESS;
}

static dataframe_t *build_df(groupby_t *group, void **array)
{
    dataframe_t *new_df = malloc(sizeof(dataframe_t));
    size_t nb_rows = my_array_len((char **)array);

    if (!new_df)
        return NULL;
    if (init_df(group, array, new_df) == FAILURE) {
        free(new_df);
        return NULL;
    }
    new_df->data = get_array(group, array, nb_rows);
    if (!new_df->data) {
        free(new_df->separator);
        free(new_df);
        return NULL;
    }
    return new_df;
}

dataframe_t *df_groupby(dataframe_t *dataframe, const char *aggregate_by,
    const char **to_aggregate, void *(*agg_func)(void **values, int nb_values))
{
    groupby_t group = {dataframe, aggregate_by, to_aggregate, agg_func};
    void **array = NULL;
    dataframe_t *new_df = NULL;

    if (!dataframe || !aggregate_by || !to_aggregate)
        return NULL;
    array = df_get_unique_values(dataframe, aggregate_by);
    if (!array)
        return NULL;
    new_df = build_df(&group, array);
    free_many_arrays(1, array);
    return new_df;
}
