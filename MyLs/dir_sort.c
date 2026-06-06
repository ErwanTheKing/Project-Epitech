/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** The dir_sort.c
*/

#include "include/includes.h"

int len_word_dir(char **array, struct dirent *struct_dir, int a)
{
    int len = 0;
    DIR *dir = opendir(array[a]);

    if (verif_opendir(dir) == 84) {
        my_printf("%m", "ls: cannot open directory '");
        my_printf("%m", array[a]);
        my_printf("%m", "': Permission denied\n");
        return -1;
    }
    struct_dir = readdir(dir);
    verif_readdir(struct_dir);
    for (; struct_dir != NULL; struct_dir = readdir(dir))
        len += my_strlen(struct_dir->d_name) + 1;
    closedir(dir);
    return len;
}

static int my_len_array(char **array)
{
    int len = 0;

    for (; array[len] != NULL; len++);
    return len;
}

void show_word_array(char **array)
{
    int j = 0;

    for (int i = 0; array[i] != NULL; i++) {
        if (j != 0 && array[i][0] != '.')
            my_printf("%s", "  ");
        if (array[i][0] != '.') {
            my_printf("%s", array[i]);
            j++;
        }
    }
}

void show_word_array_multi(char **tab, int a, char **array)
{
    int j = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (j != 0 && tab[i][0] != '.')
            my_printf("%s", "  ");
        if (tab[i][0] != '.') {
            my_printf("%s", tab[i]);
            j++;
        }
    }
    if (array[a + 1] != NULL)
        my_putstr("\n\n");
}

static void array_lower(char **array, char **array_tmp)
{
    int i = 0;

    for (; array[i] != NULL; i++) {
        array_tmp[i] = my_strlowcase(array[i]);
    }
    array_tmp[i] = NULL;
}

char **sort(char **tab)
{
    int i = 0;
    char *str_tmp;
    char **array_low = malloc(sizeof(char *) * (my_len_array(tab) + 1));

    array_lower(tab, array_low);
    for (; array_low[i + 1] != NULL; i++) {
        if (my_strcmp(array_low[i], array_low[i + 1]) > 0) {
            str_tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = str_tmp;
        }
    }
    free_array(array_low);
    return tab;
}
