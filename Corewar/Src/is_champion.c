/*
** EPITECH PROJECT, 2026
** is
** File description:
** champion
*/

#include "../lib/Headers/corewar.h"

int is_champion(char *str)
{
    int len = 0;

    if (!str)
        return FALSE;
    len = my_strlen(str);
    if (len < 5)
        return FALSE;
    if (my_strcmp(&str[len - CORE_LEN], CORE_FORMATING) == 0)
        return TRUE;
    return FALSE;
}
