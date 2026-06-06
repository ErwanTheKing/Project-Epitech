/*
** EPITECH PROJECT, 2026
** create
** File description:
** cursor
*/

#include "../lib/Headers/corewar.h"

static void init_cursor_process(cursor_t *cursor, champ_t *champ, int index)
{
    cursor->process = champ->process;
    cursor->process.pc = index;
    cursor->process.alive = 0;
    cursor->process.is_dead = 0;
}

void create_cursor(int nb, int index, prog_t *prog)
{
    cursor_t *new = malloc(sizeof(cursor_t));
    cursor_t *current = NULL;
    champ_t *champ = get_champ(prog, nb);

    if (!new || !champ)
        return;
    new->champion = nb;
    new->opcode = 0;
    new->alive = 0;
    new->index = cw_addr(index);
    new->cooldown = 0;
    new->next = NULL;
    init_cursor_process(new, champ, new->index);
    if (!prog->cursors) {
        prog->cursors = new;
        return;
    }
    for (current = prog->cursors; current && current->next;
        current = current->next);
    current->next = new;
}
