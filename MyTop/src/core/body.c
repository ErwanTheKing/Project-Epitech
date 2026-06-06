/*
** EPITECH PROJECT, 2026
** My_Top
** File description:
** body
*/
#include <dirent.h>
#include <stdlib.h>
#include "../../include/my_top.h"
#include <ncurses.h>
#include "../../lib/my/headers/my.h"
#include "../../include/my_top.h"
#include <unistd.h>

static char *get_names(DIR *proc, struct dirent *entry, char *temp, char *new)
{
    for (entry = readdir(proc); entry != NULL; entry = readdir(proc))
        if (my_getnbr(entry->d_name) > 0) {
            new = my_strconcat(temp, entry->d_name);
            free(temp);
            temp = new;
            new = my_strconcat(temp, " ");
            free(temp);
            temp = new;
        }
    return temp;
}

static char **get_pid(void)
{
    DIR *proc = opendir(PROC_PATH);
    struct dirent *entry = NULL;
    char **PIDs = NULL;
    char *temp = NULL;
    char *new = NULL;

    if (!proc)
        return NULL;
    temp = my_strdup("", 1);
    temp = get_names(proc, entry, temp, new);
    closedir(proc);
    PIDs = my_str_to_word_array(temp, " ");
    if (temp)
        free(temp);
    return PIDs;
}

static int print_pid(char **PIDs, int i)
{
    for (int j = my_strlen(PIDs[i]); j < 7; j++)
        printw(" ");
    printw("%s ", PIDs[i]);
    return SUCCESS;
}

int body(top_t *top_struct)
{
    char **PIDs = get_pid();

    if (!PIDs)
        return FAILURE;
    for (int i = 0 + top_struct->down; PIDs[i + 1]; i++) {
        if (i - top_struct->down >= getmaxy(stdscr) - 8)
            break;
        print_pid(PIDs, i);
        if (print_username(PIDs, i) == FAILURE || print_pr(PIDs, i) == FAILURE
            || print_ni(PIDs, i) == FAILURE || print_virt(PIDs, i) == FAILURE
            || print_res(PIDs, i) == FAILURE || print_shr(PIDs, i) == FAILURE
            || print_state(PIDs, i) == FAILURE
            || print_cpu_percentage(PIDs, i) == FAILURE
            || print_mem_percentage(PIDs, i) == FAILURE)
            return FAILURE;
        printw("\n");
    }
    free_array(PIDs);
    return SUCCESS;
}
