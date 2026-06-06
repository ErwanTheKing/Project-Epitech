/*
** EPITECH PROJECT, 2025
** getnbr
** File description:
** string a nbr
*/

#include "my.h"

static int and(char asc)
{
    if (asc < 48 && asc != '+' && asc != '-' || asc > 57){
        return (0);
    }
    if (asc == '-'){
        return (-1);
    }
    if (asc == '+'){
        return (1);
    } else {
        return (2);
    }
}

static int nmb_final(int min, int max, char const *str, int result)
{
    long nb = 0;

    for (int i = min; i < max + 1; i++) {
        nb = nb * 10;
        nb = nb + (str[i] - 48);
        if (nb > 2147483648)
            return 0;
    }
    nb = nb * result;
    if (nb < -2147483648 || nb > 2147483647) {
        return 0;
    }
    return nb;
}

int my_getnbr(char const *str)
{
    int comp = 0;
    int result = 1;

    for (int i = 0; str[i] != '\0'; i++){
        if (and(str[i]) == 0 && comp == 0)
            return (0);
        if (and(str[i]) == 2 && comp == 0)
            comp = i + 1;
        if (and(str[i]) == -1 && comp > 0 || and(str[i]) == 1 && comp > 0)
            return (nmb_final(comp - 1, i - 1, str, result));
        if (and(str[i]) == 0 && comp > 0)
            return (nmb_final(comp - 1, i - 1, str, result));
        if (and(str[i]) == 2 && comp > 0 && str[i + 1] == '\0')
            return (nmb_final(comp - 1, i, str, result));
        if (and(str[i]) == -1)
            result = result * -1;
    }
    return (0);
}
