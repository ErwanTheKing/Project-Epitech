/*
** EPITECH PROJECT, 2025
** my_isneg
** File description:
** it's a function to displays N or P
*/

#include "../../Headers/my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    my_putchar('\n');
    return (0);
}
