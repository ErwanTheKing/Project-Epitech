/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** loop
*/

#include "../lib/Headers/corewar.h"

static int should_dump(prog_t *prog)
{
    if (prog->dump_cycle < 0)
        return FALSE;
    return prog->total_cycles == prog->dump_cycle;
}

static int run_one_cycle(prog_t *prog)
{
    move_cursors(prog);
    prog->total_cycles++;
    if (should_dump(prog)) {
        dump(prog);
        prog->dump_done = true;
        return SUCCESS;
    }
    return FAILURE;
}

int corewar_loop(prog_t *prog)
{
    int current_period = 0;

    if (prog->dump_cycle == 0) {
        dump(prog);
        prog->dump_done = true;
        return SUCCESS;
    }
    while (prog->cursors != NULL && prog->cycle_to_die > 0) {
        if (run_one_cycle(prog) == SUCCESS)
            return SUCCESS;
        current_period++;
        if (current_period >= prog->cycle_to_die) {
            corewar_check_period(prog);
            current_period = 0;
        }
    }
    return SUCCESS;
}
