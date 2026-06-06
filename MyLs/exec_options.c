/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** The exec_options.c
*/

#include "include/includes.h"

int option_a(char **array, int a, int argc,
    char **argv)
{
    int i = len_array(argc, argv);
    struct dirent *struct_dir = NULL;

    if (i == 1 || i == 0)
        sort_path_case_a(struct_dir, array);
    else
        sort_path_case_multi_a(struct_dir, array, a);
    return 0;
}

int option_d(char **array)
{
    int j = 0;

    for (int i = 0; array[i] != NULL; i++) {
        if (j != 0)
            my_printf("%s", "  ");
        my_printf("%s", array[i]);
        j++;
    }
    return 0;
}

int without_option(char **array, int a, int argc,
    char **argv)
{
    struct dirent *struct_dir = NULL;
    int i = len_array(argc, argv);
    int return_v = 0;

    if (i == 1 || i == 0)
        return_v = sort_path_case(struct_dir, array);
    else
        return_v = sort_path_case_multi(struct_dir, array, a);
    return return_v;
}

int option_l(char **array, int argc,
    char **argv)
{
    struct dirent *struct_dir = NULL;
    int i = len_array(argc, argv);

    if (i == 1 || i == 0)
        sort_path_case_l(struct_dir, array);
    return 0;
}
