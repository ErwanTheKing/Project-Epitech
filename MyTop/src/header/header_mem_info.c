/*
** EPITECH PROJECT, 2026
** mytop
** File description:
** The header_mem_info.c
*/
/**
 * @file header_l4.c
 * @brief The header_l4.c
 * @author Erwan Lo Presti
 */

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my_top.h"
#include "../../include/my.h"

static char **open_meminfo(void)
{
    char *mem_info = openator(MEMINFO_PATH);
    char **array = NULL;

    if (mem_info == NULL)
        return NULL;
    array = my_str_to_word_array(mem_info, "\n");
    free(mem_info);
    return array;
}

static void print_total(double total)
{
    char *text = my_nbr_to_str((int)total, 0);
    int len = strlen(text);

    if (text != 0)
        len--;
    for (int i = len; i < 7; i++)
        printw(" ");
    attron(A_BOLD);
    printw("%.1f", total);
    attroff(A_BOLD);
    printw(" total,");
    free(text);
}

static void print_free(double free_s)
{
    char *text = my_nbr_to_str((int)free_s, 0);
    int len = strlen(text);

    if (free_s != 0)
        len--;
    for (int i = len; i < 7; i++)
        printw(" ");
    attron(A_BOLD);
    printw("%.1f", free_s);
    attroff(A_BOLD);
    printw(" free,");
    free(text);
}

static void print_used(double used)
{
    char *text = my_nbr_to_str((int)used, 0);
    int len = strlen(text);

    if (used != 0)
        len--;
    for (int i = len; i < 7; i++)
        printw(" ");
    attron(A_BOLD);
    printw("%.1f", used);
    attroff(A_BOLD);
    printw(" used,");
    free(text);
}

static void print_buff(double buff)
{
    char *text = my_nbr_to_str((int)buff, 0);
    int len = strlen(text);

    if (buff != 0)
        len--;
    for (int i = len; i < 7; i++)
        printw(" ");
    attron(A_BOLD);
    printw("%.1f", buff);
    attroff(A_BOLD);
    printw(" buff/cache");
    free(text);
}

static int get_value(void)
{
    char **array = open_meminfo();
    double total = 0;
    double free = 0;
    double buffer = 0;
    double cached = 0;
    double sreclaim = 0;

    if (!array)
        return FAILURE;
    total = my_getnbr(array[0]);
    free = my_getnbr(array[1]);
    buffer = my_getnbr(array[3]);
    cached = my_getnbr(array[4]);
    sreclaim = my_getnbr(array[25]);
    print_total(total / KB);
    print_free(free / KB);
    print_used((total - free - (buffer + cached + sreclaim)) / KB);
    print_buff((buffer + cached + sreclaim) / KB);
    free_array(array);
    return SUCCESS;
}

int header_mem_info(void)
{
    printw("MiB Mem :");
    if (get_value() == FAILURE)
        return FAILURE;
    printw("\n");
    return SUCCESS;
}
