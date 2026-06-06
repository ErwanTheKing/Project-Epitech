/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** visual memory owner helpers
*/

#include "../../lib/Headers/corewar.h"

int visual_get_range_owner(prog_t *prog, int start, int end)
{
    for (int i = start; i < end; i++) {
        if (prog->owner[i] > 0)
            return prog->owner[i];
    }
    return 0;
}

int visual_get_cursor_owner(prog_t *prog, int start, int end)
{
    int index = 0;

    for (cursor_t *cur = prog->cursors; cur != NULL; cur = cur->next) {
        index = cw_addr(cur->index);
        if (index >= start && index < end)
            return cur->champion;
    }
    return 0;
}
