/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** The generate_map.c
*/

#include "include/includes.h"

char *equal(char **argv, int i, char **map, int *index_p)
{
    int nb_colum = my_getnbr(argv[1]);

    map[i] = malloc(sizeof(char) * (nb_colum + 1));
    for (int j = 0; j < nb_colum; j++) {
        if (*index_p < my_strlen(argv[2])) {
            map[i][j] = argv[2][*index_p];
            *index_p = *index_p + 1;
        } else {
            *index_p = 0;
            map[i][j] = argv[2][*index_p];
            *index_p = *index_p + 1;
        }
    }
    map[i][nb_colum] = '\0';
    return map[i];
}

char **map(char **argv)
{
    int nb_colum = my_getnbr(argv[1]);
    char **map = malloc(sizeof(char *) * (nb_colum + 2));
    int index_p = 0;

    map[0] = my_strdup(argv[1]);
    for (int i = 1; i <= nb_colum; i++) {
        map[i] = equal(argv, i, map, &index_p);
    }
    map[nb_colum + 1] = NULL;
    for (int i = 1; map[i] != NULL; i++) {
        if (verif_file(map, i) == 84)
            return NULL;
    }
    return map;
}
