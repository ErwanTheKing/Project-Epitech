/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** it's a function that displays the characters
*/

#include "../../Headers/my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    if (str == NULL)
        return FAILURE;
    write(1, str, my_strlen(str));
    return SUCCESS;
}
