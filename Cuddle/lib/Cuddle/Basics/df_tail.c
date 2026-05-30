/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Returns a new dataframe containing the last N rows of the given dataframe
*/
/**
 * @file df_tail.c
 * @brief Returns a new dataframe with the last N rows
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <string.h>
#include <unistd.h>
#include "../../Headers/dataframe.h"

static int fill_infos(dataframe_t *df, dataframe_t *dataframe, int i, int j)
{
    if (i != 0) {
        if (!dataframe->data[i - (dataframe->nb_rows - df->nb_rows)][j])
            df->data[i - (dataframe->nb_rows - df->nb_rows)][j] = NULL;
        else {
            df->data[i - (dataframe->nb_rows - df->nb_rows)][j]
            = strdup(dataframe->data[i][j]);
        }
    }
    return SUCCESS;
}

static int fill_header(dataframe_t *df, dataframe_t *dataframe, int i, int j)
{
    if (i == 0) {
        df->data[i][j] = malloc(sizeof(infos_data_t));
        if (!df->data[i][j])
            return FAILURE;
        ((infos_data_t *)df->data[0][j])->data
        = strdup(((infos_data_t *)dataframe->data[0][j])->data);
        ((infos_data_t *)df->data[0][j])->type
        = ((infos_data_t *)dataframe->data[0][j])->type;
        if (!((infos_data_t *)df->data[i][j])->data) {
            free(df->data[i][j]);
            return FAILURE;
        }
    }
    return SUCCESS;
}

static int fill_new_df(dataframe_t *df, dataframe_t *dataframe, int i)
{
    if (i == 0)
        df->data[i] = calloc(df->nb_columns + 1, sizeof(infos_data_t *));
    else
        df->data[i - (dataframe->nb_rows - df->nb_rows)]
    = calloc(df->nb_columns + 1, sizeof(char *));
    if (!df->data[i == 0 ? i : i - (dataframe->nb_rows - df->nb_rows)])
        return FAILURE;
    for (int j = 0; j < df->nb_columns; j++) {
        if (fill_header(df, dataframe, i, j) == FAILURE) {
            free(df->data[i - (dataframe->nb_rows - df->nb_rows)]);
            return FAILURE;
        }
        fill_infos(df, dataframe, i, j);
    }
    return SUCCESS;
}

static void ***get_new_csv(dataframe_t *df, dataframe_t *dataframe)
{
    df->data = calloc(df->nb_rows + 2, sizeof(void **));
    if (!df->data)
        return NULL;
    for (int i = 0; i < dataframe->nb_rows + 1; i++) {
        if (fill_new_df(df, dataframe, i) == FAILURE) {
            free(df->data);
            return NULL;
        }
        if (i == 0)
            i = dataframe->nb_rows - df->nb_rows;
    }
    return df->data;
}

static int init_df(dataframe_t *df, dataframe_t *dataframe, int nb_rows)
{
    df->nb_columns = dataframe->nb_columns;
    df->nb_rows = nb_rows < dataframe->nb_rows ? nb_rows : dataframe->nb_rows;
    df->separator = strdup(dataframe->separator);
    if (!df->separator)
        return FAILURE;
    return SUCCESS;
}

static int verif_error(dataframe_t *dataframe, int nb_rows)
{
    if (!dataframe)
        return FAILURE;
    if (nb_rows < 0)
        return FAILURE;
    return SUCCESS;
}

dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *df = NULL;

    if (verif_error(dataframe, nb_rows) == FAILURE)
        return NULL;
    df = malloc(sizeof(dataframe_t));
    if (!df)
        return NULL;
    if (init_df(df, dataframe, nb_rows) == FAILURE)
        return NULL;
    df->data = get_new_csv(df, dataframe);
    if (!df->data) {
        free(df->separator);
        free(df);
        return NULL;
    }
    return df;
}
