/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** lld
*/

#include "../../lib/Headers/corewar.h"

int lld(prog_t *prog, cursor_t *cursor)
{
    arg_read_t args[MAX_ARGS_NUMBER] = {0};
    int size = get_instruction_size(prog, cursor, 13);
    int reg = 0;

    if (cw_parse_arg_pos(prog, cursor, args, 13) == FAILURE)
        return size;
    if (cw_read_arg(prog, cursor, &args[0], FALSE) == FAILURE)
        return size;
    reg = prog->memory[cw_addr(args[1].pos)];
    cw_set_reg(prog, cursor, reg, args[0].value);
    return size;
}
