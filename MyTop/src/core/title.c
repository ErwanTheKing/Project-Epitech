/*
** EPITECH PROJECT, 2026
** My_Top
** File description:
** Title
*/

#include <ncurses.h>
#include "../../include/my_top.h"
#include "../../include/my.h"

int main_title(void)
{
    attron(A_STANDOUT);
    printw("    PID USER      PR  NI    VIRT    RES    SHR S  CPU  MEM     "
        "TIME+ COMMAND");
    attroff(A_STANDOUT);
    printw("\n");
    return SUCCESS;
}
