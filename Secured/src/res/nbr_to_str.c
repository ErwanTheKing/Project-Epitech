/*
** EPITECH PROJECT, 2026
** secured
** File description:
** nbr_to_str
*/

#include <stdlib.h>

int get_lenght_nbr(int nb)
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

char *my_nbr_to_str(int nb)
{
    int len = 0;
    int n = nb;
    char *str = NULL;
    int i = 0;

    len = get_lenght_nbr(nb);
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
