/*
** EPITECH PROJECT, 2026
** is
** File description:
** file
*/

#include "../lib/Headers/corewar.h"

int is_files_open(prog_t *prog)
{
    champ_t *tmp;
    int err = FALSE;

    for (node_t *current = prog->list; current; current = current->next) {
        tmp = (champ_t *)current->data;
        if (tmp->fd == -1) {
            err = TRUE;
            puterr(CANT_OPEN_FILE);
        }
    }
    if (err == TRUE) {
        close_files(prog);
        return FALSE;
    }
    return TRUE;
}
