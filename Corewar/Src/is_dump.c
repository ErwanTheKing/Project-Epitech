/*
** EPITECH PROJECT, 2026
** is
** File description:
** dump
*/

#include "../lib/Headers/corewar.h"

int is_dump(char **av, int i, int ac)
{
    if (my_strcmp(av[i], FLAG_DUMP) != 0)
        return FALSE;
    if (i == ac - 1)
        return FALSE;
    if (is_integer(av[i + 1]) == TRUE)
        return TRUE;
    puterr(NB_CYCLE_ERR);
    return ERR;
}
