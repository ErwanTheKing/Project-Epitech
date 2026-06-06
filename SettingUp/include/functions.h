/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** The functions.h
*/
/**
 * @file functions.h
 * @brief The functions.h
 * @author Erwan Lo Presti
 */

#ifndef SETTING_UP_FUNCTIONS_H
    #define SETTING_UP_FUNCTIONS_H
    #include "infos_biggest_square.h"
int setting_up(int argc, char **argv);
void show_array(char **array);
void fill_x(char **array, short int **array_tmp);
void show_array_int(short int **array);
void free_array_int(short int **array);
char **map(char **argv);
int verif_file(char **file, int i);
#endif /* SETTING_UP_FUNCTIONS_H */
