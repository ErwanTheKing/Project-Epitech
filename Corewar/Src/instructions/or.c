/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** or
*/

#include "../../lib/Headers/corewar.h"

int or_corewar(prog_t *prog, cursor_t *cursor)
{
    arg_read_t args[MAX_ARGS_NUMBER] = {0};
    int size = get_instruction_size(prog, cursor, 7);
    int reg = 0;

    if (cw_parse_arg_pos(prog, cursor, args, 7) == FAILURE)
        return size;
    if (cw_read_arg(prog, cursor, &args[0], TRUE) == FAILURE)
        return size;
    if (cw_read_arg(prog, cursor, &args[1], TRUE) == FAILURE)
        return size;
    reg = prog->memory[cw_addr(args[2].pos)];
    cw_set_reg(prog, cursor, reg, args[0].value | args[1].value);
    return size;
}
