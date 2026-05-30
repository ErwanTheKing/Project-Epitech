/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** dup_row
*/

#include "../../Headers/dataframe.h"

static void *dup_plain_cell(void *cell)
{
    return my_strdup(cell, 0);
}

static void *dup_header_cell(void *cell)
{
    infos_data_t *src = cell;
    infos_data_t *dst = malloc(sizeof(infos_data_t));

    if (!dst)
        return NULL;
    dst->type = src->type;
    dst->data = my_strdup(src->data, 0);
    if (dst->data)
        return dst;
    free(dst);
    return NULL;
}

static void *dup_cell(void *cell, bool header)
{
    if (header == false)
        return dup_plain_cell(cell);
    return dup_header_cell(cell);
}

static void **alloc_row_copy(int cols)
{
    return malloc(sizeof(void *) * (cols + 1));
}

static int fill_row_copy(void **out, void **row, int cols, bool header)
{
    int i = 0;

    while (i < cols) {
        out[i] = dup_cell(row[i], header);
        if (!out[i]) {
            free_row(out, i, header);
            return FAILURE;
        }
        i++;
    }
    out[cols] = NULL;
    return SUCCESS;
}

void **dup_row(void **row, int cols, bool header)
{
    void **out = alloc_row_copy(cols);

    if (!out)
        return NULL;
    if (fill_row_copy(out, row, cols, header) == FAILURE)
        return NULL;
    return out;
}
