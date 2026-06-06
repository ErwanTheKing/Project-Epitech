/*
** EPITECH PROJECT, 2026
** is
** File description:
** integer
*/

#include "../lib/Headers/corewar.h"

int is_integer(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!('0' <= str[i] && str[i] <= '9'))
            return FALSE;
    }
    return TRUE;
}
