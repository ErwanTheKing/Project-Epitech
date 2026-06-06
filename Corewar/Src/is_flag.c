/*
** EPITECH PROJECT, 2026
** is
** File description:
** flag
*/

#include "../lib/Headers/corewar.h"

int is_flag(char **av, int i, int ac)
{
    int dump = is_dump(av, i, ac);
    int number = is_number(av, i, ac);
    int address = is_address(av, i, ac);

    if (dump == TRUE)
        return TRUE;
    if (number == TRUE)
        return TRUE;
    if (address == TRUE)
        return TRUE;
    return ERR;
}
