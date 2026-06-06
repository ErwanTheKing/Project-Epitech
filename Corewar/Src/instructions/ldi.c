/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** ldi
*/

#include "../../lib/Headers/corewar.h"

static int read_index_arg(prog_t *prog, cursor_t *cursor, arg_read_t *arg,
    int mod)
{
    int value = 0;

    if (arg->type == T_REG)
        return cw_get_reg(prog, cursor,
            prog->memory[cw_addr(arg->pos)], &arg->value);
    value = cw_read_mem(prog, arg->pos,
        arg->type == T_DIR ? arg->direct_size : IND_SIZE);
    if (arg->type == T_IND) {
        if (mod)
            value %= IDX_MOD;
        arg->value = cw_read_mem(prog, cursor->index + value, IND_SIZE);
    } else
        arg->value = value;
    return SUCCESS;
}

int ldi(prog_t *prog, cursor_t *cursor)
{
    arg_read_t args[MAX_ARGS_NUMBER] = {0};
    int size = get_instruction_size(prog, cursor, 10);
    int reg = 0;
    int value = 0;

    if (cw_parse_arg_pos(prog, cursor, args, 10) == FAILURE)
        return size;
    if (read_index_arg(prog, cursor, &args[0], TRUE) == FAILURE)
        return size;
    if (read_index_arg(prog, cursor, &args[1], TRUE) == FAILURE)
        return size;
    value = cw_read_mem(prog,
        cursor->index + ((args[0].value + args[1].value) % IDX_MOD), REG_SIZE);
    reg = prog->memory[cw_addr(args[2].pos)];
    cw_set_reg(prog, cursor, reg, value);
    return size;
}
