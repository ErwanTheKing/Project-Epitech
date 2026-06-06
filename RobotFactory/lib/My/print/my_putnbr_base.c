/*
** EPITECH PROJECT, 2025
** my_putnbr_base
** File description:
** test
*/

#include <stdio.h>
#include "../../Headers/my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int base_len = my_strlen(base);

    if (!base || base_len < 2)
        return FAILURE;
    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * -1;
    }
    if (nbr >= base_len)
        my_putnbr_base(nbr / base_len, base);
    my_putchar(base[nbr % base_len]);
    return (SUCCESS);
}
