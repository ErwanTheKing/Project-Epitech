/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** build_sorted_results
*/

#include "../../Headers/dataframe.h"

static dataframe_t *create_sorted_df(dataframe_t *df)
{
    dataframe_t *out = malloc(sizeof(dataframe_t));

    if (!out)
        return NULL;
    out->nb_rows = df->nb_rows;
    out->nb_columns = df->nb_columns;
    out->separator = my_strdup(df->separator, 0);
    out->data = malloc(sizeof(void **) * (df->nb_rows + 2));
    if (!out->separator || !out->data) {
        free(out->separator);
        free(out->data);
        free(out);
        return NULL;
    }
    return out;
}

static void destroy_sorted_df(dataframe_t *out)
{
    free(out->separator);
    free(out->data);
    free(out);
}

static int fill_output_df(dataframe_t *out, dataframe_t *df,
    void ***rows, int cols)
{
    int i = 0;

    out->data[0] = dup_row(df->data[0], cols, true);
    if (!out->data[0]) {
        destroy_sorted_df(out);
        free_rows(rows, df->nb_rows, cols, false);
        return FAILURE;
    }
    while (i < df->nb_rows) {
        out->data[i + 1] = rows[i];
        i++;
    }
    out->data[df->nb_rows + 1] = NULL;
    free(rows);
    return SUCCESS;
}

dataframe_t *build_sorted_result(dataframe_t *df, void ***rows,
    struct sort_ctx_s *ctx)
{
    dataframe_t *out = create_sorted_df(df);

    if (!out) {
        free_rows(rows, df->nb_rows, ctx->cols, false);
        return NULL;
    }
    if (fill_output_df(out, df, rows, ctx->cols) == FAILURE)
        return NULL;
    return out;
}
