/*
** EPITECH PROJECT, 2026
** My_Top
** File description:
** print_res
*/

#include <ncurses.h>
#include "../../../include/my_top.h"
#include "../../../include/my.h"

static void free_needed(char *temp_path, char *path,
    char *str_stat, char **tab_stat)
{
    free_many(3, temp_path, path, str_stat);
    free_array(tab_stat);
}

static char *find_line(char **tab_stat)
{
    char *line = NULL;

    for (int j = 0; tab_stat[j]; j++) {
        line = my_strstr(tab_stat[j], "VmRSS:");
        if (line != NULL)
            return line;
    }
    return NULL;
}

static void display(char *line)
{
    for (int j = len_nb(my_getnbr(line + 7)); j < 7; j++)
        printw(" ");
    printw("%d", my_getnbr(line + 7));
}

int print_res(char **PIDS, int i)
{
    char *temp_path = my_strconcat(PROC_PATH, PIDS[i]);
    char *path = temp_path ? my_strconcat(temp_path, "/status") : NULL;
    char *str_stat = path ? openator(path) : NULL;
    char **tab_stat = path ? my_str_to_word_array(str_stat, "\n") : NULL;
    char *line = NULL;

    if (!tab_stat) {
        free_many(2, temp_path, path);
        return FAILURE;
    }
    line = find_line(tab_stat);
    if (line == NULL) {
        printw("      0");
        free_needed(temp_path, path, str_stat, tab_stat);
        return SUCCESS;
    }
    display(line);
    free_needed(temp_path, path, str_stat, tab_stat);
    return SUCCESS;
}
