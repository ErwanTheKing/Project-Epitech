/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** my_triple_array_n_dup
*/

#include "../../Headers/dataframe.h"

void ***my_triple_array_n_dup(void ***array, int n)
{
    int i = 0;
    int j = 0;
    void ***dup = NULL;

    if (!array)
        return NULL;
    dup = malloc(sizeof(void **) * (n + 1));
    if (!dup)
        return NULL;
    for (i = 0; i < n && array[i]; i++) {
        for (j = 0; array[i][j]; j++);
        dup[i] = malloc(sizeof(void *) * (j + 1));
        if (!dup[i])
            return NULL;
        for (j = 0; array[i][j]; j++)
            dup[i][j] = array[i][j];
        dup[i][j] = NULL;
    }
    dup[i] = NULL;
    return dup;
}
