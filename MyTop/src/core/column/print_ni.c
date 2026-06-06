/*
** EPITECH PROJECT, 2026
** My_Top
** File description:
** print_ni
*/

#include <ncurses.h>
#include "../../../include/my_top.h"
#include "../../../include/my.h"

int print_ni(char **PIDS, int i)
{
    char *temp_path = my_strconcat(PROC_PATH, PIDS[i]);
    char *path = temp_path ? my_strconcat(temp_path, "/stat") : NULL;
    char *str_stat = path ? openator(path) : NULL;
    char **tab_stat = str_stat ? my_str_to_word_array(str_stat, " ") : NULL;

    if (!tab_stat) {
        free_many(3, str_stat, path, temp_path);
        return FAILURE;
    }
    for (int j = my_strlen(tab_stat[18]); j < 4; j++)
        printw(" ");
    printw("%d   ", my_getnbr(tab_stat[18]));
    free_array(tab_stat);
    free_many(3, str_stat, path, temp_path);
    return SUCCESS;
}
