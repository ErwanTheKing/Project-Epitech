/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** lfork
*/

#include "../../lib/Headers/corewar.h"

static void insert_child_after(cursor_t *parent, cursor_t *child)
{
    child->next = parent->next;
    parent->next = child;
}

static cursor_t *clone_cursor(cursor_t *parent, int index)
{
    cursor_t *child = malloc(sizeof(cursor_t));

    if (!child)
        return NULL;
    child->index = cw_addr(index);
    child->champion = parent->champion;
    child->alive = parent->alive;
    child->process = parent->process;
    child->process.pc = child->index;
    child->cooldown = 0;
    child->opcode = 0;
    child->next = NULL;
    return child;
}

int lfork(prog_t *prog, cursor_t *cursor)
{
    int offset = cw_read_mem(prog, cursor->index + 1, IND_SIZE);
    int new_index = cw_addr(cursor->index + offset);
    cursor_t *child = clone_cursor(cursor, new_index);

    (void)prog;
    if (child)
        insert_child_after(cursor, child);
    return OPCODE + IND_SIZE;
}
