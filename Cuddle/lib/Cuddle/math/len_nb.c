/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** The len_nbr.c
*/

long long len_nb(long long nb)
{
    long long len = 0;

    if (nb == 0)
        return 1;
    if (nb < 0) {
        len++;
        nb = -nb;
    }
    while (nb != 0) {
        nb = nb / 10;
        len++;
    }
    return len;
}
