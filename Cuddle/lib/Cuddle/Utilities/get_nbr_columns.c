/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Counts the number of columns in a delimiter-separated string
*/
/**
 * @file get_nbr_columns.c
 * @brief Counts the number of columns in a delimiter-separated string
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include "../../Headers/my.h"

int get_nbr_columns(char *str, const char *separator)
{
    int len = 0;
    char **array
    = my_str_to_word_array(str, !separator ? "," : separator);

    if (!array)
        return -1;
    len = my_array_len(array);
    free_array(array);
    return len;
}
