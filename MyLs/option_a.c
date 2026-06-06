/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** The option_case.c
*/

#include "include/includes.h"

void show_word_array_a(char **array)
{
    int j = 0;

    for (int i = 0; array[i] != NULL; i++) {
        if (j != 0)
            my_printf("%s", "  ");
        my_printf("%s", array[i]);
        j++;
    }
}

void show_word_array_multi_a(char **tab, int a, char **array)
{
    int j = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (j != 0)
            my_printf("%s", "  ");
        my_printf("%s", tab[i]);
        j++;
    }
    if (array[a + 1] != NULL)
        my_putstr("\n\n");
}

int sort_path_case_a(struct dirent *struct_dir, char **array)
{
    char **tab = path_case(struct_dir, array);

    for (int i = 0; tab[i] != NULL; i++) {
        sort(tab);
    }
    show_word_array_a(tab);
    free_array(tab);
    return 0;
}

int sort_path_case_multi_a(struct dirent *struct_dir, char **array, int a)
{
    char **tab = path_case_multi(struct_dir, array, a);

    for (int i = 0; tab[i] != NULL; i++) {
        sort(tab);
    }
    show_word_array_multi_a(tab, a, array);
    free_array(tab);
    return 0;
}

char **sort_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        sort(array);
    }
    return array;
}
