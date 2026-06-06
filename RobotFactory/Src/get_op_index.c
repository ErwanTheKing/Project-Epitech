/*
** EPITECH PROJECT, 2026
** UsineAMarvin
** File description:
** The get_op_index.c
*/
/**
 * @file get_op_index.c
 * @brief The get_op_index.c
 * @author Erwan Lo Presti
 */

#include "../include/my.h"
#include "../lib/Headers/factory.h"

int get_op_index(char *op)
{
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (my_strcmp(op, op_tab[i].mnemonique) == 0) {
            return i;
        }
    }
    return NOT_FOUND;
}
