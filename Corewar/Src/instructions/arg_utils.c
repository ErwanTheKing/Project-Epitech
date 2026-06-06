/*
** EPITECH PROJECT, 2026
** ~/Epitech/Project/G-CPE-200-NCE-2-1-corewar-5/Src/instructions
** File description:
** arg_utils
*/

#include "../../lib/Headers/corewar.h"
#include <stdint.h>

int cw_arg_type(unsigned char coding, int arg)
{
    int code = (coding >> (6 - (arg * 2))) & 0x03;

    if (code == 1)
        return T_REG;
    if (code == 2)
        return T_DIR;
    if (code == 3)
        return T_IND;
    return 0;
}

int cw_direct_size(int op_code)
{
    if (op_code == 9 || op_code == 10 || op_code == 11 || op_code == 12
        || op_code == 14 || op_code == 15)
        return IND_SIZE;
    return DIR_SIZE;
}

int cw_arg_size(int type, int direct_size)
{
    if (type == T_REG)
        return 1;
    if (type == T_DIR)
        return direct_size;
    if (type == T_IND)
        return IND_SIZE;
    return 0;
}

int cw_read_arg(prog_t *prog, cursor_t *cursor, arg_read_t *arg, int mod)
{
    int value = 0;

    if (arg->type == T_REG)
        return cw_get_reg(prog, cursor,
            prog->memory[cw_addr(arg->pos)], &arg->value);
    value = cw_read_mem(prog, arg->pos,
        arg->type == T_DIR ? arg->direct_size : IND_SIZE);
    if (arg->type == T_DIR) {
        arg->value = value;
        return SUCCESS;
    }
    if (mod)
        value %= IDX_MOD;
    arg->value = cw_read_mem(prog, cursor->index + value, REG_SIZE);
    return SUCCESS;
}

int cw_parse_arg_pos(prog_t *prog, cursor_t *cursor, arg_read_t args[],
    int op_index)
{
    unsigned char coding = prog->memory[cw_addr(cursor->index + 1)];
    int direct_size = cw_direct_size(op_tab[op_index].code);
    int pos = cursor->index + 2;
    int type = 0;

    for (int i = 0; i < op_tab[op_index].nbr_args; i++) {
        type = cw_arg_type(coding, i);
        if ((op_tab[op_index].type[i] & type) == 0 || type == 0)
            return FAILURE;
        args[i].type = type;
        args[i].pos = pos;
        args[i].direct_size = direct_size;
        args[i].value = 0;
        pos += cw_arg_size(type, direct_size);
    }
    return SUCCESS;
}
