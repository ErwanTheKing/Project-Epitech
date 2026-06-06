/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** st
*/

#include "../../lib/Headers/corewar.h"

int st_corewar(prog_t *prog, cursor_t *cursor)
{
    arg_read_t args[MAX_ARGS_NUMBER] = {0};
    int size = get_instruction_size(prog, cursor, 3);
    int value = 0;
    int dest = 0;

    if (cw_parse_arg_pos(prog, cursor, args, 3) == FAILURE)
        return size;
    if (cw_get_reg(prog, cursor,
            prog->memory[cw_addr(args[0].pos)], &value) == FAILURE)
        return size;
    if (args[1].type == T_REG)
        cw_set_reg(prog, cursor, prog->memory[cw_addr(args[1].pos)], value);
    else {
        dest = cw_read_mem(prog, args[1].pos, IND_SIZE) % IDX_MOD;
        cw_write_mem(prog, cursor->index + dest, value, REG_SIZE);
        cw_set_owner(prog, cursor->index + dest, REG_SIZE, cursor->champion);
    }
    return size;
}
