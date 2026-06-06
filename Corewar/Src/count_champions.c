/*
** EPITECH PROJECT, 2026
** count
** File description:
** champions
*/

#include "../lib/Headers/corewar.h"

int count_champions(prog_t *prog, int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (is_champion(av[i]) == TRUE) {
            add_champion(prog, av[i]);
        }
    }
    if (prog->nb_champ < 2)
        return FALSE;
    return TRUE;
}
