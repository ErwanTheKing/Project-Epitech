/*
** EPITECH PROJECT, 2026
** My_Top
** File description:
** free_all
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../Headers/my.h"

int free_many(int count, ...)
{
    va_list args;
    void *p;

    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        p = va_arg(args, void *);
        free(p);
    }
    va_end(args);
    return FAILURE;
}

static void free_in(void **a)
{
    for (int j = 0; a[j] != NULL; ++j)
        free(a[j]);
}

int free_many_arrays(int count, ...)
{
    va_list args;
    void **a;

    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        a = va_arg(args, void **);
        if (a) {
            free_in(a);
            free(a);
        }
    }
    va_end(args);
    return FAILURE;
}
