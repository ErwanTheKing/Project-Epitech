/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-CPE-110-NCE-1-1-secured-2/src
** File description:
** dlong_to_str
*/

#include <stdlib.h>

int getdlong_lenght_nbr(long long nb)
{
    int len = 0;

    if (nb <= 0)
        len = 1;
    while (nb != 0) {
        nb /= 10;
        len++;
    }
    return len;
}

char *dlong_to_str(long long nb)
{
    int len = 0;
    long long n = nb;
    char *str = NULL;
    int i = 0;

    len = getdlong_lenght_nbr(nb);
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;
    if (nb < 0) {
        str[0] = '-';
        i++;
        n = -n;
    }
    for (; i < len; i++) {
        str[len - i - 1] = (n % 10) + '0';
        n /= 10;
    }
    str[len] = '\0';
    return str;
}
