/*
** EPITECH PROJECT, 2026
** puterr
** File description:
** puterr
*/

#include "../lib/Headers/corewar.h"

int puterr(const char *error)
{
    write(2, error, my_strlen(error));
    return FAILED;
}
