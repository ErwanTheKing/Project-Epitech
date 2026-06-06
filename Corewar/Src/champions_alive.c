/*
** EPITECH PROJECT, 2026
** champions
** File description:
** alive
*/

#include "../lib/Headers/corewar.h"

int champions_alive(prog_t *prog)
{
    int alive = 0;
    champ_t *champ = NULL;

    for (node_t *tmp = prog->list; tmp != NULL; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        if (!champ->process.is_dead)
            alive++;
    }
    if (alive < 2)
        return FALSE;
    return TRUE;
}
