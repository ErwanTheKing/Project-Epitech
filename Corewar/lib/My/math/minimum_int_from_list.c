/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** minimum_int_from_list
*/

#include <stdarg.h>
#include "../../Headers/my.h"

int minimum_int_from_list(int count, ...)
{
    va_list int_list;
    int min_value = 0;
    int temp_value = 0;

    va_start(int_list, count);
    if (count <= 0) {
        va_end(int_list);
        return SUCCESS;
    }
    min_value = va_arg(int_list, int);
    for (int i = 1; i < count; i++) {
        temp_value = va_arg(int_list, int);
        if (temp_value < min_value) {
            min_value = temp_value;
        }
    }
    va_end(int_list);
    return min_value;
}
