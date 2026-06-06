/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** The algo.c
*/

#include <stdio.h>

#include "include/includes.h"

static int get_smallest(short int **array, int i, int j)
{
    int a = array[i - 1][j];
    int b = array[i - 1][j - 1];
    int c = array[i][j - 1];

    if (a <= b) {
        if (c <= a)
            return c;
        return a;
    }
    return b;
}

void free_array_int(short int **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

static void fill_struct(infos_bs_t *infos, short int **array, int i, int j)
{
    if (array[i][j] > infos->value) {
        infos->x = i;
        infos->y = j;
        infos->value = array[i][j];
    }
}

static void biggest_square(short int **array, infos_bs_t *infos)
{
    for (int i = 1; array[i] != NULL; i++) {
        for (int j = 1; array[i][j] != -1; j++) {
            array[i][j] = array[i][j] == 0
                ? 0 : get_smallest(array, i, j) + array[i][j];
            fill_struct(infos, array, i, j);
        }
    }
    free_array_int(array);
}

void fill_x(char **array, short int **array_tmp)
{
    infos_bs_t *infos = malloc(sizeof(infos_bs_t));

    if (!infos)
        return;
    biggest_square(array_tmp, infos);
    for (int i = infos->x; i > infos->x - infos->value; i--) {
        for (int j = infos->y; j > infos->y - infos->value; j--){
            array[i][j - 1] = 'x';
        }
    }
    show_array(array);
    free_array(array);
    free(infos);
}
