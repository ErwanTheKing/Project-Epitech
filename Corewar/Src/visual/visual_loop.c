/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** visual loop
*/

#include <ncurses.h>
#undef ERR
#include <unistd.h>
#include "../../lib/Headers/corewar.h"

static int run_visual_cycle(prog_t *prog, int *period)
{
    move_cursors(prog);
    prog->total_cycles++;
    (*period)++;
    if (*period >= prog->cycle_to_die) {
        corewar_check_period(prog);
        *period = 0;
    }
    if (prog->dump_cycle >= 0 && prog->total_cycles >= prog->dump_cycle)
        return TRUE;
    return FALSE;
}

static int run_visual_frame(prog_t *prog, int *period)
{
    for (int i = 0; i < VISUAL_CYCLES_PER_FRAME; i++) {
        if (prog->cursors == NULL || prog->cycle_to_die <= 0)
            return TRUE;
        if (run_visual_cycle(prog, period) == TRUE)
            return TRUE;
    }
    return FALSE;
}

int corewar_visual_loop(prog_t *prog)
{
    int key = 0;
    int period = 0;

    visual_init();
    visual_draw_memory(prog);
    while (!prog->visual_stop && prog->cycle_to_die > 0
        && prog->cursors != NULL) {
        key = getch();
        if (key != -1)
            visual_handle_key(prog, key);
        if (run_visual_frame(prog, &period) == TRUE)
            break;
        visual_draw_memory(prog);
        usleep(prog->visual_delay);
    }
    visual_draw_memory(prog);
    visual_draw_winner(prog);
    napms(2000);
    endwin();
    return SUCCESS;
}
