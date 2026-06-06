/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** The my_char_isnum.c
*/

#include "../headers/my.h"

int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return SUCCESS;
}
