/*
** EPITECH PROJECT, 2026
** iscor
** File description:
** iscor
*/

#include "../lib/Headers/corewar.h"

int is_cor_file(char *str)
{
    int len = 0;

    if (!str)
        return FALSE;
    len = my_strlen(str);
    if (len < 5)
        return FALSE;
    if (my_strcmp(&str[len - CORE_LEN], CORE_FORMATING) == 0)
        return TRUE;
    puterr(CORE_FORMATING_ERR);
    return FALSE;
}
