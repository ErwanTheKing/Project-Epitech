/*
** EPITECH PROJECT, 2026
** is
** File description:
** dump
*/

#include "../lib/Headers/corewar.h"

int is_address(char **av, int i, int ac)
{
    if (my_strcmp(av[i], FLAG_ADDRESS) != 0)
        return FALSE;
    if (i == ac - 1)
        return FALSE;
    if (is_integer(av[i + 1]) == TRUE)
        return TRUE;
    puterr(ADDRESS_ERR);
    return ERR;
}
