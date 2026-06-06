/*
** EPITECH PROJECT, 2026
** My_Top
** File description:
** init
*/

#include <stdlib.h>
#include "../include/my_top.h"
#include <ncurses.h>

top_t *init_screen(void)
{
    top_t *top_struct = malloc(sizeof(top_t));

    if (!top_struct)
        return NULL;
    top_struct->down = 0;
    top_struct->right = 0;
    top_struct->start_time = time(NULL);
    initscr();
    return top_struct;
}
