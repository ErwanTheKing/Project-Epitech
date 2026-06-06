/*
** EPITECH PROJECT, 2026
** is
** File description:
** number
*/

#include "../lib/Headers/corewar.h"

int is_number(char **av, int i, int ac)
{
    if (my_strcmp(av[i], FLAG_NUMBER) != 0)
        return FALSE;
    if (i == ac - 1)
        return FALSE;
    if (is_integer(av[i + 1]) == TRUE)
        return TRUE;
    puterr(NUMBER_ERR);
    return ERR;
}
