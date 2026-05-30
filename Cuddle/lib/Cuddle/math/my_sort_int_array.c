/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** my_sort_int_array
*/

#include "../../Headers/my.h"

static void bubble_pass(int *tab, int size)
{
    for (int j = 0; j < size; j++) {
        if (tab[j] > tab[j + 1])
            my_swap(&tab[j], &tab[j + 1]);
    }
}

void my_sort_int_array(int *tab, int size)
{
    if (tab == NULL || size <= 0)
        return;
    for (int i = 0; i < size - 1; i++)
        bubble_pass(tab, size - 1 - i);
}
