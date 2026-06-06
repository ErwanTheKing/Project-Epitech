/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** visual flag
*/

#include "../lib/Headers/corewar.h"

int is_visual_flag(char *str)
{
    if (my_strcmp(str, (char *)FLAG_VISUAL) == 0)
        return TRUE;
    if (my_strcmp(str, (char *)FLAG_VISUAL_LONG) == 0)
        return TRUE;
    return FALSE;
}
