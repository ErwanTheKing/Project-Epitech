/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** get_sell_values
*/

#include "../../Headers/dataframe.h"

static int get_bool_values(void **left, void **right,
    struct value_pair_s *pair, const int col)
{
    pair->a = str_to_bool(left[col]);
    pair->b = str_to_bool(right[col]);
    if (!pair->a || !pair->b)
        return FAILURE;
    return SUCCESS;
}

static int get_int_values(void **left, void **right,
    struct value_pair_s *pair, const int col)
{
    pair->a = str_to_int(left[col]);
    pair->b = str_to_int(right[col]);
    if (!pair->a || !pair->b)
        return FAILURE;
    return SUCCESS;
}

static int get_uint_values(void **left, void **right,
    struct value_pair_s *pair, const int col)
{
    pair->a = str_to_unsigned_int(left[col]);
    pair->b = str_to_unsigned_int(right[col]);
    if (!pair->a || !pair->b)
        return FAILURE;
    return SUCCESS;
}

static int get_float_values(void **left, void **right,
    struct value_pair_s *pair, const int col)
{
    pair->a = str_to_float(left[col]);
    pair->b = str_to_float(right[col]);
    if (!pair->a || !pair->b)
        return FAILURE;
    return SUCCESS;
}

int get_sell_values(void **left, void **right,
    struct value_pair_s *pair, const struct sort_ctx_s *ctx)
{
    if (ctx->type == BOOL)
        return get_bool_values(left, right, pair, ctx->col);
    if (ctx->type == INT)
        return get_int_values(left, right, pair, ctx->col);
    if (ctx->type == UINT)
        return get_uint_values(left, right, pair, ctx->col);
    if (ctx->type == FLOAT)
        return get_float_values(left, right, pair, ctx->col);
    return FAILURE;
}
