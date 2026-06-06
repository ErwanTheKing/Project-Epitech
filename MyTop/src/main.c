/*
** EPITECH PROJECT, 2025
** new_project
** File description:
** The name.c
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/my_top.h"

int verif_time(top_t *top_struct, flags_t *info_flags)
{
    time_t now = time(NULL);
    double elapsed = difftime(now, top_struct->start_time);

    if (info_flags->frame <= elapsed && info_flags->flag_frame == TRUE)
        return FAILURE;
    return SUCCESS;
}

int loop(top_t *top_struct)
{
    int input = 0;

    while (1) {
        timeout(top_struct->info_flags->refresh * 1000);
        clear();
        if (header() == FAILURE || main_title() == FAILURE
            || body(top_struct) == FAILURE)
            return FAILURE;
        input = getch();
        if (input == 'q' || verif_time(top_struct,
                top_struct->info_flags) == FAILURE) {
            free_many(2, top_struct, top_struct->info_flags);
            endwin();
            return SUCCESS;
        }
        if (input == KEY_DOWN && top_struct->down < count_runnings())
            top_struct->down += 1;
        if (input == KEY_UP && top_struct->down > 0)
            top_struct->down -= 1;
    }
}

int main(int argc, char **argv)
{
    top_t *top_struct = init_screen();

    top_struct->info_flags = prefill_info_flags(argc, argv);
    if (!top_struct->info_flags) {
        endwin();
        return FAILURE;
    }
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    return loop(top_struct);
}
