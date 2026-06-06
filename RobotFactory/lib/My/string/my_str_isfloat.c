/*
** EPITECH PROJECT, 2026
** My
** File description:
** my_str_isfloat
*/

#include "../../Headers/my.h"

static int check_float_char(char c, int *dot_count, int *digit_count)
{
    if (c == '.') {
        *dot_count = *dot_count + 1;
        if (*dot_count > 1)
            return FAILURE;
        return SUCCESS;
    }
    if (c >= '0' && c <= '9') {
        *digit_count = *digit_count + 1;
        return SUCCESS;
    }
    return FAILURE;
}

int my_str_isfloat(char const *str)
{
    int i = 0;
    int dot_count = 0;
    int digit_count = 0;

    if (str == NULL || str[0] == '\0')
        return FAILURE;
    if (str[0] == '-' || str[0] == '+')
        i++;
    for (; str[i] != '\0'; i++)
        if (check_float_char(str[i], &dot_count, &digit_count) == FAILURE)
            return FAILURE;
    if (digit_count == 0)
        return FAILURE;
    return SUCCESS;
}
