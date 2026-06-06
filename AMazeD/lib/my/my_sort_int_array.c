/*
** EPITECH PROJECT, 2025
** sort int tab
** File description:
** in ascii order
*/

#include "my.h"

void swap_ascii(int *array, int i, int size)
{
    for (int b = 0; b != size - i - 1; b++) {
        if (array[b + 1] < array[b]) {
            my_swap(&array[b], &array[b + 1]);
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i != size; i++) {
        swap_ascii(array, i, size);
    }
}
