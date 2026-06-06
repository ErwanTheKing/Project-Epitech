/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** visual initialization
*/

#include <ncurses.h>
#undef ERR
#include "../../lib/Headers/corewar.h"

void visual_handle_key(prog_t *prog, int key)
{
    if (key == 'q')
        prog->visual_stop = true;
    if (key == '+' && prog->visual_delay > 1000)
        prog->visual_delay -= 1000;
    if (key == '-')
        prog->visual_delay += 1000;
}

static void init_colors(void)
{
    start_color();
    use_default_colors();
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_YELLOW, -1);
    init_pair(4, COLOR_BLUE, -1);
    init_pair(5, COLOR_MAGENTA, -1);
    init_pair(6, COLOR_CYAN, -1);
    init_pair(7, COLOR_WHITE, -1);
}

void visual_init(void)
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    init_colors();
}
