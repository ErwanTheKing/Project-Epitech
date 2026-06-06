/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** The basic_case.c
*/

#include "include/includes.h"
#include <stdio.h>

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

char **path_case(struct dirent *struct_dir, char **array)
{
    DIR *dir = opendir(array[0]);
    int a = 0;
    char *str = malloc(sizeof(char) * len_word_dir(array, struct_dir, a) + 1);
    int i = 0;
    char **tab = NULL;

    if (verif_opendir(dir) == 84)
        return NULL;
    verif_malloc(str);
    struct_dir = readdir(dir);
    str[0] = '\0';
    for (; struct_dir != NULL; struct_dir = readdir(dir)) {
        my_strcat(str, struct_dir->d_name);
        my_strcat(str, " ");
        i += my_strlen(struct_dir->d_name) + 1;
    }
    tab = my_str_to_word_array(str);
    free(str);
    closedir(dir);
    return tab;
}

int sort_path_case(struct dirent *struct_dir, char **array)
{
    char **tab = path_case(struct_dir, array);

    if (tab == NULL)
        return 84;
    for (int i = 0; tab[i] != NULL; i++) {
        sort(tab);
    }
    show_word_array(tab);
    free_array(tab);
    return 0;
}

char **path_case_multi(struct dirent *struct_dir, char **array, int a)
{
    DIR *dir = opendir(array[a]);
    char *str = malloc(sizeof(char) * len_word_dir(array, struct_dir, a) + 1);
    char **tab = NULL;

    if (verif_opendir(dir) == 84)
        return NULL;
    struct_dir = readdir(dir);
    verif_readdir(struct_dir);
    str[0] = '\0';
    my_printf("%s:\n", array[a]);
    for (; struct_dir != NULL; struct_dir = readdir(dir)) {
        my_strcat(str, struct_dir->d_name);
        my_strcat(str, " ");
    }
    tab = my_str_to_word_array(str);
    free(str);
    closedir(dir);
    return tab;
}

int sort_path_case_multi(struct dirent *struct_dir, char **array, int a)
{
    char **tab = path_case_multi(struct_dir, array, a);

    if (tab == NULL)
        return 84;
    for (int i = 0; tab[i] != NULL; i++) {
        sort(tab);
    }
    show_word_array_multi(tab, a, array);
    free_array(tab);
    return 0;
}
