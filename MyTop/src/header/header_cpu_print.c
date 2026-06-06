/*
** EPITECH PROJECT, 2026
** mytop
** File description:
** The header_cpu_print.c
*/
/**
 * @file header_cpu_print.c
 * @brief The header_cpu_print.c
 * @author Erwan Lo Presti
 */

#include <ncurses.h>

static void print_st(double st)
{
    printw("  ");
    attron(A_BOLD);
    printw("%.1f", st);
    attroff(A_BOLD);
    printw(" st");
}

static void print_si(double si)
{
    printw("  ");
    attron(A_BOLD);
    printw("%.1f", si);
    attroff(A_BOLD);
    printw(" si,");
}

static void print_hi(double hi)
{
    printw("  ");
    attron(A_BOLD);
    printw("%.1f", hi);
    attroff(A_BOLD);
    printw(" hi,");
}

void print_wa(double wa, double hi, double si, double st)
{
    printw("  ");
    attron(A_BOLD);
    printw("%.1f", wa);
    attroff(A_BOLD);
    printw(" wa,");
    print_hi(hi);
    print_si(si);
    print_st(st);
}

static void print_id(double id)
{
    printw("  ");
    attron(A_BOLD);
    printw("%.1f", id);
    attroff(A_BOLD);
    printw(" id,");
}

static void print_ni(double ni)
{
    printw("  ");
    attron(A_BOLD);
    printw("%.1f", ni);
    attroff(A_BOLD);
    printw(" ni,");
}

static void print_sy(double sy)
{
    printw("  ");
    attron(A_BOLD);
    printw("%.1f", sy);
    attroff(A_BOLD);
    printw(" sy,");
}

void print_us(double us, double sy, double ni, double id)
{
    printw("  ");
    attron(A_BOLD);
    printw("%.1f", us);
    attroff(A_BOLD);
    printw(" us,");
    print_sy(sy);
    print_ni(ni);
    print_id(id);
}
