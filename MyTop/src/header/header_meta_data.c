/*
** EPITECH PROJECT, 2026
** mytop
** File description:
** The header_meta_data.c
*/
/**
 * @file header_l1.c
 * @brief The header_l1.c
 * @author Erwan Lo Presti
 */

#include <ncurses.h>
#include "../../include/my_top.h"
#include "../../include/my.h"
#include <stdlib.h>
#include <string.h>

static char *get_time(void)
{
    char *time = openator(TIME_PATH);

    if (!time)
        return NULL;
    time[1] = time[1] + 1;
    if (time[0] == 2 && time[1] == 4) {
        time[0] = 0;
        time[1] = 0;
    }
    time[my_strlen(time) - 1] = '\0';
    return time;
}

static int print_uptime(int day, int hour, int min)
{
    if (day > 0)
        printw("%d days, ", day);
    else
        printw(" ");
    if (hour > 0 && min < 10)
        printw("%d:0%d,", hour, min);
    else if (hour > 0)
        printw("%d:%d,", hour, min);
    else
        printw("%d min,", min);
    return SUCCESS;
}

static int get_uptime(void)
{
    char *uptime = openator(UPTIME_PATH);
    float time;
    int hour;
    int min;
    int day = 0;

    if (!uptime)
        return FAILURE;
    uptime = strtok(uptime, " ");
    if (!uptime)
        return FAILURE;
    time = my_getnbr(uptime) * 100 / 3600;
    hour = time / 100;
    min = (time - hour * 100) * 15 / 25;
    if (hour >= 24) {
        day = hour / 24;
        hour = hour % 24;
    }
    free(uptime);
    return print_uptime(day, hour, min);
}

static int get_loadavg(void)
{
    char *avg = openator(AVG_PATH);
    char *infos_avg = NULL;

    if (!avg)
        return FAILURE;
    infos_avg = strtok(avg, " ");
    if (!infos_avg)
        return FAILURE;
    printw("  load average: %s, ", infos_avg);
    infos_avg = strtok(NULL, " ");
    if (!infos_avg)
        return FAILURE;
    printw("%s, ", infos_avg);
    infos_avg = strtok(NULL, " ");
    if (!infos_avg)
        return FAILURE;
    printw("%s", infos_avg);
    free(avg);
    return SUCCESS;
}

static int get_nbr_user(void)
{
    printw("  0 user,");
    return SUCCESS;
}

int header_meta_data(void)
{
    char *time = get_time();

    if (!time)
        return FAILURE;
    printw("top - %s up ", time);
    if (get_uptime() == FAILURE)
        return FAILURE;
    get_nbr_user();
    if (get_loadavg() == FAILURE)
        return FAILURE;
    printw("\n");
    free(time);
    return SUCCESS;
}
