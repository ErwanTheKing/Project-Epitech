/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** test
*/

#include "my.h"

long long int my_put_nbr(long long int nb)
{
    long long int modulo = 10;
    long long int res_modulo = 0;

    if (nb < 0) {
        nb = nb * -1;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    } else if (nb >= 10){
        res_modulo = nb % modulo;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(res_modulo + 48);
    }
    return (0);
}
