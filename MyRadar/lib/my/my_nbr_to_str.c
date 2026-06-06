/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** test
*/

#include <stdio.h>

#include "../../include/formats.h"
#include <stdlib.h>
#include "my.h"

char *my_nbr_to_str(int nb)
{
    int count = 0;
    char *str;
    int nw_nb = 0;
    int nw_nb2 = nb;
    int i = 0;

    for (; nw_nb2 > 0; count++)
        nw_nb2 = nw_nb2 / 10;
    if (count == 0)
        count++;
    str = malloc(sizeof(char) * (count + 1));
    str[count] = '\0';
    for (i = 0; count > 0; i++) {
        nw_nb = (nb / my_compute_power_rec(10, count - 1)) - (nw_nb * 10);
        str[i] = nw_nb + 48;
        nw_nb = nb / my_compute_power_rec(10, count - 1);
        count--;
    }
    return str;
}
