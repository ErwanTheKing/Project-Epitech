/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** df_to_type
*/
/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Casts the values of a dataframe column to a specified data type
*/
/**
 * @file df_to_type.c
 * @brief Casts the values of a dataframe column to a specified data type
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <string.h>
#include <unistd.h>
#include "../../Headers/dataframe.h"


static void float_to_int(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.')
            str[i] = '\0';
    }
}

static void trunc_value(char ***new_data, dataframe_t *new_df, int i)
{
    for (int j = 1; j < new_df->nb_rows + 1; j++)
        float_to_int(new_data[j][i]);
}

static void to_bool(char ***new_data, dataframe_t *new_df, int i)
{
    for (int j = 1; j < new_df->nb_rows + 1; j++)
        if (atof(new_data[j][i]) == 0) {
            free(new_data[j][i]);
            new_data[j][i] = strdup("false");
        } else {
            free(new_data[j][i]);
            new_data[j][i] = strdup("true");
        }
}

static void to_float(dataframe_t *new_df, int i)
{
    float values = 0;

    for (int j = 1; j < new_df->nb_rows + 1; j++) {
        if (!new_df->data[j][i])
            continue;
        values = atof(new_df->data[j][i]);
        snprintf(new_df->data[j][i], sizeof(new_df->data[j][i]),
            "%.2f", values);
    }
}

static int change_type(dataframe_t *new_df,
    column_type_t downcast, int i)
{
    column_type_t new_type = UNDEFINED;

    for (int j = 1; j < new_df->nb_rows + 1; j++) {
        new_type = find_type(new_df->data[j][i], new_type);
    }
    if (new_type == STRING && downcast != STRING)
        return FAILURE;
    if (new_type == INT && downcast == UINT)
        return FAILURE;
    if (new_type == FLOAT && downcast == INT)
        trunc_value((char ***)new_df->data, new_df, i);
    if (new_type != BOOL && downcast == BOOL)
        to_bool((char ***)new_df->data, new_df, i);
    if (downcast == FLOAT)
        to_float(new_df, i);
    ((infos_data_t *)new_df->data[0][i])->type = downcast;
    return SUCCESS;
}

static int init_new_datafram(dataframe_t *dataframe, dataframe_t *new_df)
{
    new_df->nb_columns = dataframe->nb_columns;
    new_df->nb_rows = dataframe->nb_rows;
    new_df->separator = strdup(dataframe->separator);
    if (!new_df->separator) {
        return FAILURE;
    }
    new_df->data = my_triple_array_dup(dataframe->data);
    if (!new_df->data) {
        free(new_df->separator);
        return FAILURE;
    }
    return SUCCESS;
}

dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast)
{
    dataframe_t *new_df = NULL;

    if (!dataframe)
        return NULL;
    new_df = malloc(sizeof(dataframe_t));
    if (!new_df)
        return NULL;
    if (init_new_datafram(dataframe, new_df) == FAILURE) {
        free(new_df);
        return NULL;
    }
    for (int i = 0; i < new_df->nb_columns; i++) {
        if (strcmp(((infos_data_t *)new_df->data[0][i])->data, column) == 0
            && change_type(new_df, downcast, i) == SUCCESS)
            return new_df;
    }
    df_free(new_df);
    return NULL;
}
