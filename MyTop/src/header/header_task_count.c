/*
** EPITECH PROJECT, 2026
** mytop
** File description:
** The header_task_count.c
*/
/**
 * @file header_l2.c
 * @brief The header_l2.c
 * @author Erwan Lo Presti
 */

#include "../../include/my_top.h"
#include <ncurses.h>
#include <dirent.h>
#include <stdlib.h>

#include "../../lib/my/headers/my.h"
#include <string.h>

static void tasks_running(int running)
{
    char *text = my_nbr_to_str(running, 0);
    int len = strlen(text);

    if (running != 0)
        len--;
    for (int i = len; i < 4; i++)
        printw(" ");
    attron(A_BOLD);
    printw("%d", running);
    attroff(A_BOLD);
    printw(" running,");
    free(text);
}

static void tasks_sleeping(int sleeping)
{
    char *text = my_nbr_to_str(sleeping, 0);
    int len = strlen(text);

    if (sleeping != 0)
        len--;
    for (int i = len; i < 4; i++)
        printw(" ");
    attron(A_BOLD);
    printw("%d", sleeping);
    attroff(A_BOLD);
    printw(" sleeping,");
    free(text);
}

static void tasks_stopped(int stopped)
{
    char *text = my_nbr_to_str(stopped, 0);
    int len = strlen(text);

    if (stopped != 0)
        len--;
    for (int i = len; i < 4; i++)
        printw(" ");
    attron(A_BOLD);
    printw("%d", stopped);
    attroff(A_BOLD);
    printw(" stopped,");
    free(text);
}

static void tasks_zombie(int zombie)
{
    char *text = my_nbr_to_str(zombie, 0);
    int len = strlen(text);

    if (zombie != 0)
        len--;
    for (int i = len; i < 4; i++)
        printw(" ");
    attron(A_BOLD);
    printw("%d", zombie);
    attroff(A_BOLD);
    printw(" zombie");
    free(text);
}

static void total_tasks(tasks_t *infos_tasks)
{
    char *text = my_nbr_to_str(infos_tasks->total, 0);
    int len = strlen(text);

    if (infos_tasks->total != 0)
        len--;
    for (int i = len; i < 4; i++)
        printw(" ");
    attron(A_BOLD);
    printw("%d", infos_tasks->total);
    attroff(A_BOLD);
    printw(" total,");
    tasks_running(infos_tasks->running);
    tasks_sleeping(infos_tasks->sleeping);
    tasks_stopped(infos_tasks->stopped);
    free(text);
}

char *long_path(char *name)
{
    char *path = malloc(sizeof(char) * (14 + strlen(name)));

    if (!path)
        return NULL;
    path[0] = '\0';
    strcat(path, "/proc/");
    strcat(path, name);
    strcat(path, "/status");
    return path;
}

char get_stat(char *name)
{
    char *path = NULL;
    char *open = NULL;
    char **array = NULL;
    char stat = '\0';

    path = long_path(name);
    if (!path)
        return '\0';
    open = openator(path);
    if (!open) {
        free(path);
        return '\0';
    }
    array = my_str_to_word_array(open, "\n");
    for (int i = 0; array[i]; i++)
        stat = strstr(array[i], "State:") ? array[i][7] : stat;
    free(path);
    free(open);
    free_array(array);
    return stat;
}

void count_task(struct dirent *entry, tasks_t *infos_tasks)
{
    if (my_getnbr(entry->d_name) > 0) {
        infos_tasks->total++;
        switch (get_stat(entry->d_name)) {
            case 'R':
                infos_tasks->running++;
                break;
            case 'S':
            case 'I':
            case 'D':
                infos_tasks->sleeping++;
                break;
            case 'T':
                infos_tasks->stopped++;
                break;
            case 'Z':
                infos_tasks->zombie++;
                break;
        }
    }
}

int open_proc(void)
{
    DIR *proc = opendir(PROC_PATH);
    struct dirent *entry = NULL;
    tasks_t *infos_tasks = malloc(sizeof(tasks_t));

    if (!proc || !infos_tasks) {
        free(infos_tasks);
        return FAILURE;
    }
    infos_tasks->total = 0;
    infos_tasks->running = 0;
    infos_tasks->sleeping = 0;
    infos_tasks->stopped = 0;
    infos_tasks->zombie = 0;
    for (entry = readdir(proc); entry != NULL; entry = readdir(proc))
        count_task(entry, infos_tasks);
    closedir(proc);
    total_tasks(infos_tasks);
    tasks_zombie(infos_tasks->zombie);
    free(infos_tasks);
    return SUCCESS;
}

int header_task_info(void)
{
    printw("Tasks:");
    if (open_proc() == FAILURE)
        return FAILURE;
    printw("\n");
    return SUCCESS;
}
