/*
** EPITECH PROJECT, 2026
** get
** File description:
** get
*/

#include "../lib/Headers/corewar.h"

static int get_arg_type(unsigned char coding, int arg)
{
    return (coding >> (6 - (arg * 2))) & 0x03;
}

static int arg_size(int type, int direct_size)
{
    if (type == T_REG)
        return 1;
    if (type == T_DIR)
        return direct_size;
    if (type == T_IND)
        return 2;
    return 0;
}

static int direct_size_for_op(int op_code)
{
    switch (op_code) {
        case 9:
        case 10:
        case 11:
        case 12:
        case 14:
        case 15:
            return IND_SIZE;
        default:
            return DIR_SIZE;
    }
}

static bool has_coding_byte_for_op(int op_code)
{
    return !(op_code == 1 || op_code == 9 || op_code == 12 || op_code == 15);
}

int get_instruction_size(prog_t *prog, cursor_t *cursor, int op_index)
{
    int op_code = op_tab[op_index].code;
    int direct_size = direct_size_for_op(op_code);
    int size = OPCODE;
    unsigned char coding = 0;

    if (!has_coding_byte_for_op(op_code))
        return size + direct_size;
    coding = prog->memory[(cursor->index + 1) % MEM_SIZE];
    size += 1;
    for (int i = 0; i < op_tab[op_index].nbr_args; i++)
        size += arg_size(get_arg_type(coding, i), direct_size);
    return size;
}
