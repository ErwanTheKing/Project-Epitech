/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** move cursor
*/

#include "../lib/Headers/corewar.h"

static const instruction_t instructions = {live, ld_corewar, st_corewar,
    add, sub, and, or_corewar, xor, zjmp, ldi, sti, fork_corewar, lld,
    lldi, lfork, print};

static int get_instruction_index(unsigned char opcode)
{
    for (int i = 1; op_tab[i].code != 0; i++) {
        if (op_tab[i].code == opcode)
            return i - 1;
    }
    return -1;
}

static int fetch_instruction(prog_t *prog, cursor_t *cursor)
{
    int index = 0;

    cursor->opcode = prog->memory[cw_addr(cursor->index)];
    index = get_instruction_index(cursor->opcode);
    if (index == -1) {
        cursor->opcode = 0;
        cw_set_owner(prog, cursor->index, 1, cursor->champion);
        cursor->index = cw_addr(cursor->index + 1);
        cw_update_pc(prog, cursor);
        return FAILURE;
    }
    cursor->cooldown = op_tab[index + 1].nbr_cycles - 1;
    return SUCCESS;
}

static int prepare_instruction(prog_t *prog, cursor_t *cursor)
{
    if (cursor->opcode == 0)
        return fetch_instruction(prog, cursor);
    if (cursor->cooldown > 0) {
        cursor->cooldown--;
        return FAILURE;
    }
    return SUCCESS;
}

static void execute_instruction(prog_t *prog, cursor_t *cursor)
{
    int index = get_instruction_index(cursor->opcode);
    int old_pc = cursor->index;
    int move = 0;

    if (index == -1) {
        cursor->index = cw_addr(cursor->index + 1);
        cursor->opcode = 0;
        return;
    }
    move = instructions[index](prog, cursor);
    if (move > 0)
        cw_set_owner(prog, old_pc, move, cursor->champion);
    if (cursor->index == old_pc)
        cursor->index = cw_addr(cursor->index + move);
    cursor->opcode = 0;
    cw_update_pc(prog, cursor);
}

static void move_cursor(prog_t *prog, cursor_t *cursor)
{
    if (prepare_instruction(prog, cursor) == FAILURE)
        return;
    execute_instruction(prog, cursor);
}

void move_cursors(prog_t *prog)
{
    cursor_t *next = NULL;

    for (cursor_t *current = prog->cursors; current; current = next) {
        next = current->next;
        move_cursor(prog, current);
    }
}
