/*
** EPITECH PROJECT, 2026
** My_Top
** File description:
** header
*/

#include <ncurses.h>
#include "../../include/my_top.h"
#include "../../include/my.h"

int header(void)
{
    if (header_meta_data() == FAILURE)
        return FAILURE;
    if (header_task_info() == FAILURE)
        return FAILURE;
    header_cpu_info();
    header_mem_info();
    header_swap_info();
    printw("\n");
    return SUCCESS;
}
