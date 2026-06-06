/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** register utils
*/

#include "../../lib/Headers/corewar.h"

int cw_is_valid_reg(int reg)
{
    return reg >= 1 && reg <= REG_NUMBER;
}

int cw_get_reg(prog_t *prog, cursor_t *cursor, int reg, int *value)
{
    (void)prog;
    if (!cursor || !cw_is_valid_reg(reg))
        return FAILURE;
    *value = cursor->process.reg[reg - 1];
    return SUCCESS;
}

int cw_set_reg(prog_t *prog, cursor_t *cursor, int reg, int value)
{
    (void)prog;
    if (!cursor || !cw_is_valid_reg(reg))
        return FAILURE;
    cursor->process.reg[reg - 1] = value;
    cursor->process.carry = (value == 0) ? 1 : 0;
    return SUCCESS;
}
