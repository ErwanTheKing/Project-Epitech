/*
** EPITECH PROJECT, 2026
** help
** File description:
** help
*/

#include "../lib/Headers/corewar.h"

int my_help(int ac, char **av)
{
    if ((ac < 2))
        return FALSE;
    if ((my_strcmp(av[1], FLAG_HELP) == 0)) {
        my_putstr("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number] [");
        my_putstr("-a load_address] prog_name] ...\n");
        my_putstr("DESCRIPTION\n-dump nbr_cycle dumps the state of ");
        my_putstr("the virtual machine after the nbr_cycle execution\n");
        my_putstr("-n prog_number sets the next program’s number.");
        my_putstr(" By default, the first free number in the parameter\n");
        my_putstr("-a load_address sets the next program’s loading address.");
        my_putstr(" When no address is specified, optimize the\naddresses so ");
        my_putstr("that the processes are as far away from each other as ");
        my_putstr("possible. The addresses are\nMEM_SIZE modulo.\n");
        return TRUE;
    }
    if (2 < ac)
        return TRUE;
    return FALSE;
}
