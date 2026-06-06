/*
** EPITECH PROJECT, 2025
** copy str
** File description:
** copy string to string
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    for (int ind = 0; ind <= my_strlen(src); ind++){
        dest[ind] = src[ind];
    }
    return (dest);
}
