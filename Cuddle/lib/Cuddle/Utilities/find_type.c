/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Detects and assigns the data type of each column by analysing CSV values
*/
/**
 * @file find_type.c
 * @brief Detects and assigns data types for each column in a CSV
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include "../../Headers/dataframe.h"

static column_type_t check_type_data(char *data)
{
    char *lower_data = NULL;

    lower_data = my_strdup(data, 0);
    if (lower_data != NULL) {
        my_strlowcase(lower_data);
        if (my_strcmp(lower_data, "true") == 0 ||
            my_strcmp(lower_data, "false") == 0) {
            free(lower_data);
            return BOOL;
        }
        free(lower_data);
    }
    if (my_str_isnegnum(data) == SUCCESS)
        return INT;
    if (my_str_isnum(data) == SUCCESS)
        return UINT;
    if (my_str_isfloat(data) == SUCCESS)
        return FLOAT;
    return STRING;
}

column_type_t find_type(char *data, column_type_t type)
{
    column_type_t new_type;

    if (data == NULL)
        return type;
    new_type = check_type_data(data);
    if (type == STRING || new_type == STRING)
        return STRING;
    if (type == UNDEFINED)
        return new_type;
    if (type == new_type)
        return type;
    if (type == BOOL || new_type == BOOL)
        return STRING;
    if (type == FLOAT || new_type == FLOAT)
        return FLOAT;
    if (type == INT || new_type == INT)
        return INT;
    return STRING;
}
