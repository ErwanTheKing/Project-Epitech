/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** sti
*/

#include "../../lib/Headers/corewar.h"

static int read_index_arg(prog_t *prog, cursor_t *cursor, arg_read_t *arg)
{
    int value = 0;

    if (arg->type == T_REG)
        return cw_get_reg(prog, cursor,
            prog->memory[cw_addr(arg->pos)], &arg->value);
    value = cw_read_mem(prog, arg->pos,
        arg->type == T_DIR ? arg->direct_size : IND_SIZE);
    if (arg->type == T_IND)
        arg->value = cw_read_mem(prog, cursor->index + (value % IDX_MOD),
            IND_SIZE);
    else
        arg->value = value;
    return SUCCESS;
}

int sti(prog_t *prog, cursor_t *cursor)
{
    arg_read_t args[MAX_ARGS_NUMBER] = {0};
    int size = get_instruction_size(prog, cursor, 11);
    int value = 0;
    int dest = 0;

    if (cw_parse_arg_pos(prog, cursor, args, 11) == FAILURE)
        return size;
    if (cw_get_reg(prog, cursor,
            prog->memory[cw_addr(args[0].pos)], &value) == FAILURE)
        return size;
    if (read_index_arg(prog, cursor, &args[1]) == FAILURE)
        return size;
    if (read_index_arg(prog, cursor, &args[2]) == FAILURE)
        return size;
    dest = (args[1].value + args[2].value) % IDX_MOD;
    cw_write_mem(prog, cursor->index + dest, value, REG_SIZE);
    cw_set_owner(prog, cursor->index + dest, REG_SIZE, cursor->champion);
    return size;
}
