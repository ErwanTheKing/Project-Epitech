/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** print_winner
*/

#include "../lib/Headers/corewar.h"

void print_winner(prog_t *prog)
{
    if (prog->last_live == NULL)
        return;
    my_putstr("The player ");
    my_put_nbr(prog->last_live->process.id);
    my_putchar('(');
    my_putstr(prog->last_live->process.name);
    my_putstr(") has won.\n");
}
