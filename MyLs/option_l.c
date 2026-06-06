/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** The option_l.c
*/

#include <unistd.h>

#include "include/includes.h"

static void print_type(struct stat *stats)
{
    my_printf("%c", get_type(stats));
}

static void get_perm(struct stat *stats)
{
    char perm[10];

    perm[0] = stats->st_mode & S_IRUSR ? 'r' : '-';
    perm[1] = stats->st_mode & S_IWUSR ? 'w' : '-';
    perm[2] = stats->st_mode & S_IXUSR ? 'x' : '-';
    perm[3] = stats->st_mode & S_IRGRP ? 'r' : '-';
    perm[4] = stats->st_mode & S_IWGRP ? 'w' : '-';
    perm[5] = stats->st_mode & S_IXGRP ? 'x' : '-';
    perm[6] = stats->st_mode & S_IROTH ? 'r' : '-';
    perm[7] = stats->st_mode & S_IWOTH ? 'w' : '-';
    perm[8] = stats->st_mode & S_IXOTH ? 'x' : '-';
    perm[9] = '\0';
    my_printf("%s ", perm);
}

static int get_name_id(struct stat *stat)
{
    struct passwd *uid = getpwuid(stat->st_uid);
    struct group *gid = getgrgid(stat->st_gid);

    if (uid == NULL || gid == NULL)
        return 84;
    my_printf("%s %s ", uid->pw_name, gid->gr_name);
    return 0;
}

static int month(struct stat *stats)
{
    char *time = ctime(&stats->st_mtim.tv_sec);
    char **array_t = my_str_to_word_array(time);

    my_printf("%s %s %s:%s ", array_t[1], array_t[2],
        array_t[3], array_t[4]);
    free_array(array_t);
    return 0;
}

void show_word_array_l(char **array, char **tab_path)
{
    int j = 0;
    struct stat *stats = malloc(sizeof(struct stat));

    for (int i = 0; array[i] != NULL; i++) {
        stat(array[i], stats);
        if (j != 0 && array[i][0] != '.')
            my_printf("%c", '\n');
        if (array[i][0] != '.') {
            print_type(stats);
            get_perm(stats);
            my_printf("%d ", stats->st_nlink);
            get_name_id(stats);
            my_printf("%ld ", stats->st_size);
            month(stats);
            my_printf("%s", array[i]);
            j++;
        }
    }
    free(stats);
}

int sort_path_case_l(struct dirent *struct_dir, char **array)
{
    char **tab = path_case(struct_dir, array);
    struct stat *stats = malloc(sizeof(struct stat));
    long total = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        sort(tab);
    }
    for (int i = 0; tab[i] != NULL; i++) {
        stat(tab[i], stats);
        if (tab[i][0] != '.' && tab[i][1] != '.')
            total += stats->st_blocks;
    }
    my_printf("total %ld\n", total);
    show_word_array_l(tab, array);
    free_array(tab);
    free(stats);
    return 0;
}
