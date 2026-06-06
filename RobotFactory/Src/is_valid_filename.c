/*
** EPITECH PROJECT, 2026
** is
** File description:
** is
*/

#include "../lib/Headers/factory.h"

int is_valid_filename(char *filename)
{
    int last_dot = -1;

    for (int i = 0; filename[i] != '\0'; i++)
        if (filename[i] == '.')
            last_dot = i;
    if (last_dot == -1)
        return FALSE;
    return (my_strcmp(&filename[last_dot], ".s") == 0) ? TRUE : FALSE;
}
