/*
** EPITECH PROJECT, 2026
** My_Top
** File description:
** print_shr
*/

#include <ncurses.h>
#include "../../../include/my_top.h"
#include "../../../include/my.h"


int print_shr(char **PIDS, int i)
{
    char *temp_path = my_strconcat(PROC_PATH, PIDS[i]);
    char *path = temp_path ? my_strconcat(temp_path, "/statm") : NULL;
    char *str_stat = path ? openator(path) : NULL;
    char **tab_stat = path ? my_str_to_word_array(str_stat, " ") : NULL;
    int shared_mem = 0;

    if (!tab_stat) {
        free_many(2, temp_path, path);
        return FAILURE;
    }
    if (tab_stat[2])
        shared_mem = my_getnbr(tab_stat[2]) * 4096 / KB;
    for (int j = len_nb(shared_mem); j < 7; j++)
        printw(" ");
    printw("%d", shared_mem);
    free_many(3, temp_path, path, str_stat);
    free_array(tab_stat);
    return SUCCESS;
}
