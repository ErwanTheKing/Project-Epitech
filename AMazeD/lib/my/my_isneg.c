/*
** EPITECH PROJECT, 2025
** my_isneg
** File description:
** positif or negatif
*/

#include "my.h"

int my_isneg(int nb)
{
    if (nb < 0){
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    my_putchar('\n');
    return (0);
}
