/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** convert_collumn
*/

#include "../../Headers/dataframe.h"
#include <unistd.h>

dataframe_t *convert_collumn(dataframe_t *dataframe, const char *column)
{
    int index = get_collumn_index(dataframe, (char *)column);
    void *(*fcall[])(char *) = {str_to_bool, str_to_int, str_to_unsigned_int,
        str_to_float, str_to_str};
    column_type_t type = ((infos_data_t *)dataframe->data[0][index])->type;
    void *old;

    if (index == -1) {
        fprintf(stderr, "Column '%s' not found in dataframe\n", column);
        return NULL;
    }
    if (type == STRING || type == UNDEFINED)
        return dataframe;
    for (int i = 1; dataframe->data[i]; i++) {
        old = dataframe->data[i][index];
        dataframe->data[i][index] = fcall[type](old);
        free(old);
        if (!dataframe->data[i][index])
            return NULL;
    }
    return dataframe;
}
