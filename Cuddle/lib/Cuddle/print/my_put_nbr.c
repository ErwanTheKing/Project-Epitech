/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** test
*/

#include "../../Headers/my.h"

long long int my_put_nbr(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    return (0);
}
