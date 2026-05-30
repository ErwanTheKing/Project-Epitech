/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** reset_collumn_type
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../Headers/dataframe.h"

static char *convert_value(void *data, column_type_t type)
{
    char *str = NULL;

    if (type == BOOL) {
        asprintf(&str, "%s", *(bool *)data ? "true" : "false");
        return str;
    }
    if (type == INT) {
        asprintf(&str, "%d", *(int *)data);
        return str;
    }
    if (type == UINT) {
        asprintf(&str, "%u", *(unsigned int *)data);
        return str;
    }
    if (type == FLOAT) {
        asprintf(&str, "%f", *(float *)data);
        return str;
    }
    free(str);
    return data;
}

dataframe_t *reset_collumn_type(dataframe_t *dataframe, int index)
{
    column_type_t type = ((infos_data_t *)dataframe->data[0][index])->type;
    char *new_data = NULL;

    if (type == STRING || type == UNDEFINED)
        return dataframe;
    for (int i = 1; dataframe->data[i]; i++) {
        new_data = convert_value(dataframe->data[i][index], type);
        if (!new_data)
            return NULL;
        free(dataframe->data[i][index]);
        dataframe->data[i][index] = new_data;
    }
    return dataframe;
}
