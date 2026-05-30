/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** sort_row_buffer
*/

#include "../../Headers/dataframe.h"

static bool row_cmp(void **left, void **right, const struct sort_ctx_s *ctx)
{
    struct value_pair_s pair;
    bool result = false;

    pair.a = NULL;
    pair.b = NULL;
    if (ctx->type == STRING)
        return ctx->sort_func(left[ctx->col], right[ctx->col]);
    if (get_sell_values(left, right, &pair, ctx) == FAILURE) {
        free(pair.a);
        free(pair.b);
        return false;
    }
    result = ctx->sort_func(pair.a, pair.b);
    free(pair.a);
    free(pair.b);
    return result;
}

static void push_left(void ***tmp, void ***rows, int *k, int *i)
{
    tmp[*k] = rows[*i];
    *k = *k + 1;
    *i = *i + 1;
}

static void push_right(void ***tmp, void ***rows, int *k, int *j)
{
    tmp[*k] = rows[*j];
    *k = *k + 1;
    *j = *j + 1;
}

static void merge_copy_back(void ***rows, void ***tmp, const int start,
    const int end)
{
    int i = start;

    while (i <= end) {
        rows[i] = tmp[i];
        i++;
    }
}

static void merge_rows(void ***rows, void ***tmp, int lim[2],
    const struct sort_ctx_s *ctx)
{
    const int mid = lim[0] + (lim[1] - lim[0]) / 2;
    int i = lim[0];
    int j = mid + 1;
    int k = lim[0];

    while (i <= mid && j <= lim[1]) {
        if (row_cmp(rows[i], rows[j], ctx))
            push_right(tmp, rows, &k, &j);
        else
            push_left(tmp, rows, &k, &i);
    }
    while (i <= mid)
        push_left(tmp, rows, &k, &i);
    while (j <= lim[1])
        push_right(tmp, rows, &k, &j);
    merge_copy_back(rows, tmp, lim[0], lim[1]);
}

static int merge_sort_rows(void ***rows, void ***tmp, int lim[2],
    struct sort_ctx_s *ctx)
{
    int left[2];
    int right[2];
    const int mid = lim[0] + (lim[1] - lim[0]) / 2;

    if (lim[0] >= lim[1])
        return SUCCESS;
    left[0] = lim[0];
    left[1] = mid;
    right[0] = mid + 1;
    right[1] = lim[1];
    if (merge_sort_rows(rows, tmp, left, ctx) == FAILURE)
        return FAILURE;
    if (merge_sort_rows(rows, tmp, right, ctx) == FAILURE)
        return FAILURE;
    merge_rows(rows, tmp, lim, ctx);
    return SUCCESS;
}

int sort_row_buffer(void ***rows, void ***tmp, const dataframe_t *df,
    struct sort_ctx_s *ctx)
{
    int lim[2];

    lim[0] = 0;
    lim[1] = df->nb_rows - 1;
    if (merge_sort_rows(rows, tmp, lim, ctx) == FAILURE) {
        free(tmp);
        free_rows(rows, df->nb_rows, ctx->cols, false);
        return FAILURE;
    }
    free(tmp);
    return SUCCESS;
}
