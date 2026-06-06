/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** The my_ls.c
*/

#include "include/includes.h"

static int print_file(char **array, int i)
{
    my_printf("%s  ", array[i]);
    return 0;
}

char get_type(struct stat *stats)
{
    const int mode[] = {S_IFBLK, S_IFCHR, S_IFDIR, S_IFIFO, S_IFLNK,
        S_IFREG, S_IFSOCK, 0};
    char *str = "bcdpl-s";

    for (int i = 0; mode[i] != 0; i++) {
        if ((stats->st_mode & S_IFMT) == mode[i]) {
            return str[i];
        }
    }
    return 'u';
}

int exec_next(int argc, char **argv, char **array_file_path, options_t *options)
{
    if (options->option1 == 'l' || options->option2 == 'l'
        || options->option3 == 'l' || options->option4 == 'l'
        || options->option5 == 'l')
        option_l(array_file_path, argc, argv);
    return 0;
}

int exec(int argc, char **argv, int a, char **array_file_path)
{
    int return_value = 0;
    options_t *options = pre_fill_struct();
    int many_options = 0;

    fill_struct(options, argc, argv, many_options);
    if (options->option1 == '0')
        return_value = without_option(array_file_path, a, argc, argv);
    if (options->option1 == 'd' || options->option2 == 'd'
        || options->option3 == 'd' || options->option4 == 'd'
        || options->option5 == 'd')
        return_value = option_d(array_file_path);
    if (options->option1 == 'a' || options->option2 == 'a'
        || options->option3 == 'a' || options->option4 == 'a'
        || options->option5 == 'a')
        return_value = option_a(array_file_path, a, argc, argv);
    exec_next(argc, argv, array_file_path, options);
    free(options);
    return return_value;
}

static int no_such_file(char *str)
{
    my_printf("%m", "ls: cannot access '");
    my_printf("%m", str);
    my_printf("%m\n", "': No such file or directory");
    return 84;
}

static void verif_tmp(int tmp, struct stat *stats)
{
    if (tmp != 84)
        my_putchar('\n');
    free(stats);
}

int verif_type(char **array, int argc, char **argv)
{
    char c;
    struct stat *stats = malloc(sizeof(struct stat));
    int tmp = 0;
    int a = 0;

    for (int i = 0; array[i] != NULL; i++) {
        stat(array[i], stats);
        c = get_type(stats);
        if (c == 'd')
            tmp = exec(argc, argv, i, array);
        if (c == 'f')
            print_file(array, i);
        if (c != 'd' && c != '-' && c == 'u') {
            tmp = no_such_file(array[i]);
        }
        if (tmp == 84)
            a = tmp;
    }
    verif_tmp(tmp, stats);
    return a;
}

int my_ls(int argc, char **argv)
{
    char **array_file_path = sort_array(file_path_array(argc, argv));
    int return_value = 0;

    return_value = verif_type(array_file_path, argc, argv);
    free_array(array_file_path);
    return return_value;
}
