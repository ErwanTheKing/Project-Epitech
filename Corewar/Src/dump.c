/*
** EPITECH PROJECT, 2026
** ~/Epitech/Project/Corewar/Src
** File description:
** dump
*/

#include "../lib/Headers/corewar.h"

static void disp_reg(champ_t *champ)
{
    for (int i = 0; i < REG_NUMBER; i++) {
        my_putchar('r');
        my_put_nbr(i + 1);
        if (i + 1 < 10)
            my_putstr(" : ");
        else
            my_putstr(": ");
        write_address(champ->process.reg[i]);
        if ((i + 1) % 6 == 0)
            my_putchar('\n');
    }
    my_putchar('\n');
    my_putstr("PC : ");
    write_address(champ->process.pc);
    my_putstr("carry: ");
    my_put_nbr(champ->process.carry);
    my_putchar('\n');
}

static void disp_exemple(void)
{
    for (int i = 0; i < 32; i++) {
        write_hex(i);
        if (i == 31)
            my_putchar('\n');
        else
            my_putchar(' ');
    }
    for (int i = 0; i < 32; i++) {
        my_putstr("--");
        if (i == 31)
            my_putchar('\n');
        else
            my_putchar(' ');
    }
    my_putchar('\n');
}

static void dump_process(prog_t *prog)
{
    champ_t *champ = NULL;

    for (node_t *tmp = prog->list; tmp != NULL; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        my_putstr(champ->process.name);
        my_putchar('(');
        my_put_nbr(champ->process.id);
        my_putstr("): ");
        if (champ->process.is_dead)
            my_putstr("dead\n");
        else
            my_putstr("alive\n");
        disp_reg(champ);
    }
}

void dump(prog_t *prog)
{
    my_putstr("Cycle: ");
    my_put_nbr(prog->total_cycles);
    my_putchar('\n');
    my_putstr("Registers:\n");
    dump_process(prog);
    my_putstr("Memory:");
    disp_exemple();
    write_memory(prog->memory);
}
