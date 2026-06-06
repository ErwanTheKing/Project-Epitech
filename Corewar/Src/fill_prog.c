/*
** EPITECH PROJECT, 2026
** fill
** File description:
** prog
*/

#include "../lib/Headers/corewar.h"

static void fill_visual_option(prog_t *prog, int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (is_visual_flag(av[i]) == TRUE)
            prog->visual = true;
    }
}

static void fill_dump_option(prog_t *prog, int ac, char **av)
{
    for (int i = 1; i < ac - 1; i++) {
        if (my_strcmp(av[i], FLAG_DUMP) == 0 && is_integer(av[i + 1])) {
            prog->dump_cycle = my_getnbr(av[i + 1]);
            return;
        }
    }
}

int fill_prog(prog_t *prog, int ac, char **av)
{
    prog->speed = SPEED;
    prog->cycle = CYCLE_TO_DIE;
    prog->nb_cycle = 0;
    prog->dump_cycle = -1;
    prog->total_cycles = 0;
    prog->cycle_to_die = CYCLE_TO_DIE;
    prog->nbr_live = 0;
    prog->checks = 0;
    prog->dump_done = false;
    prog->visual = false;
    prog->visual_stop = false;
    prog->visual_delay = 5000;
    fill_visual_option(prog, ac, av);
    fill_dump_option(prog, ac, av);
    return SUCCESS;
}
