/*
** EPITECH PROJECT, 2026
** close
** File description:
** files
*/

#include "../lib/Headers/corewar.h"

void close_files(prog_t *prog)
{
    champ_t *tmp;

    for (node_t *current = prog->list; current; current = current->next) {
        tmp = (champ_t *)current->data;
        if (tmp->fd != -1)
            close(tmp->fd);
    }
}
