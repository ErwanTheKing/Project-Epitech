/*
** EPITECH PROJECT, 2026
** mytop
** File description:
** The header_swap_info.c
*/
/**
 * @file header_l5.c
 * @brief The header_l5.c
 * @author Erwan Lo Presti
 */

#include "../../include/my.h"
#include "../../include/my_top.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

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

    if (total != 0)
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
    printw(" used.");
    free(text);
}

static void print_available(double available)
{
    char *text = my_nbr_to_str((int)available, 0);
    int len = strlen(text);

    if (available != 0)
        len--;
    for (int i = len; i < 7; i++)
        printw(" ");
    attron(A_BOLD);
    printw("%.1f", available);
    attroff(A_BOLD);
    printw(" avail Mem");
    free(text);
}

static int get_value(void)
{
    char **array = open_meminfo();
    double total = 0;
    double free = 0;
    double available = 0;

    if (!array)
        return FAILURE;
    total = my_getnbr(array[14]);
    free = my_getnbr(array[15]);
    available = my_getnbr(array[2]);
    print_total(total / KB);
    print_free(free / KB);
    print_used((total - free) / KB);
    print_available(available / KB);
    free_array(array);
    return SUCCESS;
}

int header_swap_info(void)
{
    printw("MiB Swap:");
    if (get_value() == FAILURE)
        return FAILURE;
    printw("\n");
    return SUCCESS;
}
