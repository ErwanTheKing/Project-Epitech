/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** sub
*/

#include "../../lib/Headers/corewar.h"

int sub(prog_t *prog, cursor_t *cursor)
{
    int size = get_instruction_size(prog, cursor, 5);
    int r1 = prog->memory[cw_addr(cursor->index + 2)];
    int r2 = prog->memory[cw_addr(cursor->index + 3)];
    int r3 = prog->memory[cw_addr(cursor->index + 4)];
    int a = 0;
    int b = 0;

    if (prog->memory[cw_addr(cursor->index + 1)] != 0x54)
        return size;
    if (cw_get_reg(prog, cursor, r1, &a) == FAILURE)
        return size;
    if (cw_get_reg(prog, cursor, r2, &b) == FAILURE)
        return size;
    cw_set_reg(prog, cursor, r3, a - b);
    return size;
}
