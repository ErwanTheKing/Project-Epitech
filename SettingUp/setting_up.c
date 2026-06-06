/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** setting_up
*/

#include "include/includes.h"

void show_array(char **array)
{
    for (int i = 1; array[i] != NULL; i++) {
        write(1, array[i], my_strlen(array[i]));
        write(1, "\n", 1);
    }
}

void show_array_int(short int **array)
{
    for (int i = 1; array[i] != NULL; i++) {
        for (int j = 1; array[i][j] != -1; j++)
            my_put_nbr(array[i][j]);
        my_putchar('\n');
    }
}

static void fill_array(char **array, short int **array_tmp, int k)
{
    for (int j = 0; array[k][j] != '\0'; j++) {
        if (array[k][j] == '.')
            array_tmp[k][j + 1] = 1;
    }
}

static void fill(short int **array_tmp, int nb_lign, char **array)
{
    array_tmp[nb_lign + 1] = NULL;
    for (int k = 1; array[k] != NULL; k++) {
        fill_array(array, array_tmp, k);
    }
}

static short int **create_array_cpy(char **array)
{
    short int **array_tmp = NULL;
    int len_str = my_strlen(array[1]);
    int nb_lign = my_getnbr(array[0]);

    if (nb_lign <= 0)
        return NULL;
    array_tmp = malloc(sizeof(short int *) * (nb_lign + 2));
    if (!array_tmp)
        return NULL;
    for (int i = 0; i < nb_lign + 1; i++) {
        array_tmp[i] = malloc(sizeof(short int) * (len_str + 2));
        if (!array_tmp[i])
            return NULL;
        for (int j = 1; j < len_str + 2; j++) {
            array_tmp[i][j] = i == 0 || j != len_str + 1 ? 0 : -1;
        }
    }
    fill(array_tmp, nb_lign, array);
    return array_tmp;
}

int verif_file(char **file, int i)
{
    for (int j = 0; file[i][j] != '\0'; j++) {
        if (file[i][j] != '.' && file[i][j] != 'o' && file[i][j] != '\n')
            return 84;
    }
    return 0;
}

char **file_txt(char **argv, char **array)
{
    struct stat stats;
    int fd = open(argv[1], O_RDONLY);
    int rt_stat = stat(argv[1], &stats);
    char buffer[stats.st_size + 1];

    if (verif_stat(rt_stat) == 84 || verif_open(fd) == 84
        || read(fd, buffer, stats.st_size) == -1)
        return NULL;
    array = my_str_to_word_array(buffer);
    for (int i = 1; array[i] != NULL; i++) {
        if (verif_file(array, i) == 84)
            return NULL;
    }
    close(fd);
    return array;
}

int setting_up(int argc, char **argv)
{
    char **array = NULL;
    short int **array_tmp = NULL;

    if (argc != 2 && argc != 3)
        return 84;
    if (argc == 3)
        array = map(argv);
    if (argc == 2) {
        array = file_txt(argv, array);
    }
    if (!array)
        return 84;
    array_tmp = create_array_cpy(array);
    if (array_tmp == NULL)
        return 84;
    fill_x(array, array_tmp);
    return 0;
}
