/*
** EPITECH PROJECT, 2026
** ~/Epitech/Project/G-CPE-200-NCE-2-1-corewar-5/Src/instructions
** File description:
** memory_utils
*/

#include "../../lib/Headers/corewar.h"
#include <stdint.h>

int cw_addr(int pos)
{
    pos %= MEM_SIZE;
    if (pos < 0)
        pos += MEM_SIZE;
    return pos;
}

int cw_read_mem(const prog_t *prog, int pos, int size)
{
    unsigned int value = 0;

    for (int i = 0; i < size; i++)
        value = (value << 8) | prog->memory[cw_addr(pos + i)];
    if (size == 2)
        return (int16_t)value;
    return (int)value;
}

void cw_write_mem(prog_t *prog, int pos, int value, int size)
{
    for (int i = size - 1; i >= 0; i--) {
        prog->memory[cw_addr(pos + i)] = value & 0xFF;
        value >>= 8;
    }
}

void cw_set_owner(prog_t *prog, int pos, int size, int champion)
{
    for (int i = 0; i < size; i++)
        prog->owner[cw_addr(pos + i)] = champion;
}

static void copy_cursor_view(champ_t *champ, cursor_t *cursor)
{
    for (int i = 0; i < REG_NUMBER; i++)
        champ->process.reg[i] = cursor->process.reg[i];
    champ->process.pc = cursor->index;
    champ->process.carry = cursor->process.carry;
}

void cw_update_pc(prog_t *prog, cursor_t *cursor)
{
    champ_t *champ = NULL;

    if (cursor == NULL)
        return;
    champ = get_champ(prog, cursor->champion);
    cursor->process.pc = cursor->index;
    if (champ != NULL)
        copy_cursor_view(champ, cursor);
}
