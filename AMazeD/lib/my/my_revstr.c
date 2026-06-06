/*
** EPITECH PROJECT, 2025
** restr
** File description:
** reverse str
*/

#include "my.h"


static void swap2(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int a = 0;
    int b = my_strlen(str) - 1;

    while (!(a == (my_strlen(str) / 2))){
        swap2(&str[a], &str[b]);
        a = a + 1;
        b = b - 1;
    }
    return (str);
}
