/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** ld
*/

#include "../../lib/Headers/corewar.h"

int ld_corewar(prog_t *prog, cursor_t *cursor)
{
    arg_read_t args[MAX_ARGS_NUMBER] = {0};
    int size = get_instruction_size(prog, cursor, 2);
    int reg = 0;

    if (cw_parse_arg_pos(prog, cursor, args, 2) == FAILURE)
        return size;
    if (cw_read_arg(prog, cursor, &args[0], TRUE) == FAILURE)
        return size;
    reg = prog->memory[cw_addr(args[1].pos)];
    if (cw_set_reg(prog, cursor, reg, args[0].value) == FAILURE)
        return size;
    return size;
}
