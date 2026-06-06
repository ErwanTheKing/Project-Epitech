/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** print
*/

#include "../../lib/Headers/corewar.h"

int print(prog_t *prog, cursor_t *cursor)
{
    int size = get_instruction_size(prog, cursor, 16);
    int reg = prog->memory[cw_addr(cursor->index + 2)];
    int value = 0;

    if (prog->memory[cw_addr(cursor->index + 1)] != 0x40)
        return size;
    if (cw_get_reg(prog, cursor, reg, &value) == FAILURE)
        return size;
    if (!prog->visual)
        my_putchar(value % 256);
    return size;
}
