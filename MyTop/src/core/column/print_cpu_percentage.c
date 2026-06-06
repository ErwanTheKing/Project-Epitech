/*
** EPITECH PROJECT, 2026
** My_Top
** File description:
** print_cpu_percentage
*/

#include <stdlib.h>
#include "../../../include/my.h"
#include "../../../include/my_top.h"
#include <ncurses.h>

static char **get_file_tab(char **PIDs, int i)
{
    char *temp_path = my_strconcat(PROC_PATH, PIDs[i]);
    char *path = temp_path ? my_strconcat(temp_path, "/stat") : NULL;
    char *file_content = path ? openator(path) : NULL;
    char **file_tab = file_content ? my_str_to_word_array(file_content,
        " ") : NULL;

    if (!file_tab) {
        free_many(3, temp_path, path, file_content);
        return NULL;
    }
    free_many(3, temp_path, path, file_content);
    return file_tab;
}

int print_cpu_percentage(char **PIDs, int i)
{
    char **file_tab = get_file_tab(PIDs, i);
    double utime = my_getnbr(file_tab[13]);
    double stime = my_getnbr(file_tab[14]);
    double cutime = my_getnbr(file_tab[15]);
    double cstime = my_getnbr(file_tab[16]);
    double total_time = utime + stime + cutime + cstime;
    double hertz = 100.0;
    double seconds = my_getnbr(openator(UPTIME_PATH));
    double starttime = my_getnbr(file_tab[21]);
    double process_uptime = seconds - (starttime / hertz);
    double cpu_usage = 100.0 * ((total_time / hertz) / process_uptime);

    for (int j = 0; j < 2; j++)
        printw(" ");
    printw("%.1f ", cpu_usage);
    free_many(1, file_tab);
    return SUCCESS;
}
