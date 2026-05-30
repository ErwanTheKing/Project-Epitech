/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** my_triple_array_dup
*/

#include <string.h>

#include "../../Headers/dataframe.h"

static int fill(int i, int j, void ***array, void ***dup)
{
    for (j = 0; array[i][j]; j++) {
        if (i == 0) {
            dup[i][j] = malloc(sizeof(infos_data_t));
            ((infos_data_t *)dup[i][j])->data
            = strdup(((infos_data_t *)array[i][j])->data);
            ((infos_data_t *)dup[i][j])->type
            = ((infos_data_t *)array[i][j])->type;
        } else
            dup[i][j] = strdup(array[i][j]);
    }
    dup[i][j] = NULL;
    return SUCCESS;
}

void ***my_triple_array_dup(void ***array)
{
    int i = 0;
    int j = 0;
    void ***dup = NULL;

    if (array)
        for (; array[i]; i++);
    dup = array ? malloc(sizeof(void **) * (i + 1)) : NULL;
    if (!dup)
        return NULL;
    for (i = 0; array[i]; i++) {
        for (j = 0; array[i][j]; j++);
        dup[i] = malloc(sizeof(void *) * (j + 1));
        if (!dup[i])
            return NULL;
        if (fill(i, j, array, dup) == FAILURE)
            return NULL;
    }
    dup[i] = NULL;
    return dup;
}
