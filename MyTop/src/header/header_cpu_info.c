/*
** EPITECH PROJECT, 2026
** mytop
** File description:
** The header_cpu_info.c
*/
/**
 * @file header_l3.c
 * @brief The header_l3.c
 * @author Erwan Lo Presti
 */

#include "../../include/my_top.h"
#include "../../include/my.h"
#include <ncurses.h>
#include <time.h>

static void print_stat(cpu_t *info_diff, unsigned long long total)
{
    double pus = (double)info_diff->us / (double)total * 100;
    double psy = (double)info_diff->sy / (double)total * 100;
    double pni = (double)info_diff->ni / (double)total * 100;
    double pid = (double)info_diff->id / (double)total * 100;
    double pwa = (double)info_diff->wa / (double)total * 100;
    double phi = (double)info_diff->hi / (double)total * 100;
    double psi = (double)info_diff->si / (double)total * 100;
    double pst = (double)info_diff->st / (double)total * 100;

    print_us(pus, psy, pni, pid);
    print_wa(pwa, phi, psi, pst);
}

static int diff_stat(cpu_t *info, cpu_t *info_2_time)
{
    cpu_t info_diff = {0, 0, 0, 0, 0, 0, 0, 0};
    unsigned long long total = 0;

    info_diff.us = info_2_time->us - info->us;
    info_diff.sy = info_2_time->sy - info->sy;
    info_diff.ni = info_2_time->ni - info->ni;
    info_diff.id = info_2_time->id - info->id;
    info_diff.wa = info_2_time->wa - info->wa;
    info_diff.hi = info_2_time->hi - info->hi;
    info_diff.si = info_2_time->si - info->si;
    info_diff.st = info_2_time->st - info->st;
    total = info_diff.us + info_diff.sy + info_diff.ni + info_diff.id;
    total += info_diff.wa + info_diff.hi + info_diff.si + info_diff.st;
    if (total == 0)
        return FAILURE;
    print_stat(&info_diff, total);
    return SUCCESS;
}

static int open_stat(void)
{
    FILE *stat = fopen(STAT_PATH, "r");
    cpu_t info = {0, 0, 0, 0, 0, 0, 0, 0};
    cpu_t info_2_time = {0, 0, 0, 0, 0, 0, 0, 0};

    if (stat == NULL)
        return FAILURE;
    fscanf(stat, "cpu %llu %llu %llu %llu %llu %llu %llu %llu", &info.us,
        &info.ni, &info.sy, &info.id, &info.wa, &info.hi, &info.si, &info.st);
    fclose(stat);
    nanosleep(&(struct timespec){0, 200000000}, NULL);
    stat = fopen(STAT_PATH, "r");
    if (stat == NULL)
        return FAILURE;
    fscanf(stat, "cpu %llu %llu %llu %llu %llu %llu %llu %llu", &info_2_time.us,
        &info_2_time.ni, &info_2_time.sy, &info_2_time.id, &info_2_time.wa,
        &info_2_time.hi, &info_2_time.si, &info_2_time.st);
    fclose(stat);
    return diff_stat(&info, &info_2_time);
}

int header_cpu_info(void)
{
    printw("%%Cpu(s): ");
    if (open_stat() == FAILURE)
        return FAILURE;
    printw("\n");
    return SUCCESS;
}
