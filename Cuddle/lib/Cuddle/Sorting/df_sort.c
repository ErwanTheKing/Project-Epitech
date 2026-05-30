/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** df_sort
*/

#include "../../Headers/dataframe.h"

static int get_column_index(void ***data, const char *column)
{
    const infos_data_t *info = NULL;
    int i = 0;

    if (!data[0])
        return FAILURE;
    while (data[0][i]) {
        info = (infos_data_t *)data[0][i];
        if (info && info->data &&
            my_strcmp(info->data, (char *)column) == 0)
            return i;
        i++;
    }
    return FAILURE;
}

static void ***alloc_sort_buffers(const dataframe_t *df, void ****tmp)
{
    void ***rows = malloc(sizeof(void **) * (df->nb_rows + 1));

    *tmp = malloc(sizeof(void **) * df->nb_rows);
    if (!rows || !*tmp) {
        free(rows);
        free(*tmp);
        return NULL;
    }
    return rows;
}

static int init_ctx(struct sort_ctx_s *ctx, const dataframe_t *df,
    const char *column, bool (*sort_func)(void *, void *))
{
    ctx->col = get_column_index(df->data, column);
    if (ctx->col == FAILURE)
        return FAILURE;
    ctx->cols = df->nb_columns;
    ctx->type = ((infos_data_t *)df->data[0][ctx->col])->type;
    ctx->sort_func = sort_func;
    return SUCCESS;
}

static int invalid_sort_args(dataframe_t *df, const char *column,
    bool (*sort_func)(void *, void *))
{
    if (!df || !df->data || !df->data[0])
        return SUCCESS;
    if (!column || !sort_func)
        return SUCCESS;
    return FAILURE;
}

dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool (*sort_func)(void *value1, void *value2))
{
    struct sort_ctx_s ctx;
    void ***rows = NULL;
    void ***tmp = NULL;

    if (invalid_sort_args(dataframe, column, sort_func) == SUCCESS)
        return NULL;
    if (init_ctx(&ctx, dataframe, column, sort_func) == FAILURE)
        return NULL;
    rows = alloc_sort_buffers(dataframe, &tmp);
    if (!rows)
        return NULL;
    if (fill_sorted_rows(rows, dataframe, ctx.cols) == FAILURE) {
        free(tmp);
        return NULL;
    }
    if (sort_row_buffer(rows, tmp, dataframe, &ctx) == FAILURE)
        return NULL;
    return build_sorted_result(dataframe, rows, &ctx);
}
