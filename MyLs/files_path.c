/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** The files_path.c
*/

#include <stdlib.h>

#include "lib/my/my.h"

int len_array(int argc, char **argv)
{
    int len = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-')
            len++;
    }
    return len;
}

static int len_word_argv(int argc, char **argv)
{
    int len = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            len += my_strlen(argv[i]) + 1;
        }
    }
    return len;
}

static char *str_array(int argc, char **argv)
{
    char *str = malloc(sizeof(char) * len_word_argv(argc, argv) + 2);

    str[0] = '\0';
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            my_strcat(str, argv[i]);
            my_strcat(str, " ");
        }
    }
    return str;
}

char **file_path_array(int argc, char **argv)
{
    int len = len_array(argc, argv);
    char **array = NULL;
    char *str = NULL;

    if (len == 0) {
        str = malloc(sizeof(char) * 2);
        str[0] = '.';
        str[1] = '\0';
    } else {
        str = str_array(argc, argv);
    }
    array = my_str_to_word_array(str);
    free(str);
    return array;
}
