/*
** EPITECH PROJECT, 2025
** showstr
** File description:
** display hex of cracter none printable
*/

#include "my.h"

void hex(char c)
{
    unsigned char val = c;
    unsigned char high = val / 16;
    unsigned char low = val % 16;

    my_putchar('\\');
    if (high < 10)
        my_putchar('0' + high);
    else
        my_putchar('a' + (high - 10));
    if (low < 10)
        my_putchar('0' + low);
    else
        my_putchar('a' + (low - 10));
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] > 126 || str[i] < 32) {
            hex(str[i]);
        } else {
            my_putchar(str[i]);
        }
    }
    return 0;
}
