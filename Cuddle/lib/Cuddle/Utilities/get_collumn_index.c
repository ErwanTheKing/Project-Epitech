/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** get_collumn_index
*/

#include "../../Headers/dataframe.h"

int get_collumn_index(dataframe_t *dataframe, char *column)
{
    for (int i = 0; (infos_data_t *)dataframe->data[0][i]; i++) {
        if (my_strcmp(((infos_data_t *)dataframe->data[0][i])->data, column)
            == 0) {
            return i;
        }
    }
    return -1;
}
