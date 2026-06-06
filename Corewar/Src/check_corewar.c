/*
** EPITECH PROJECT, 2026
** check
** File description:
** corewar
*/

#include "../lib/Headers/corewar.h"

int check_corewar(int ac, char **av)
{
    int cor = 0;
    int flag = 0;

    for (int i = 1; i < ac; i++) {
        if (is_visual_flag(av[i]) == TRUE)
            continue;
        flag = is_flag(av, i, ac);
        if (flag == TRUE) {
            i++;
            continue;
        }
        cor = is_cor_file(av[i]);
        if (cor == TRUE)
            continue;
        return FALSE;
    }
    return TRUE;
}
