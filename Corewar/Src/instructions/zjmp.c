/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** zjmp
*/

#include "../../lib/Headers/corewar.h"

int16_t read_i16(const prog_t *prog, int pos)
{
    return (int16_t)cw_read_mem(prog, pos, IND_SIZE);
}

champ_t *get_champ(prog_t *prog, int nb)
{
    champ_t *champ = NULL;

    for (node_t *tmp = prog->list; tmp != NULL; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        if (champ->nb == nb)
            return champ;
    }
    return NULL;
}

int zjmp(prog_t *prog, cursor_t *cursor)
{
    int offset = cw_read_mem(prog, cursor->index + 1, IND_SIZE);

    (void)prog;
    if (cursor->process.carry != 1)
        return OPCODE + IND_SIZE;
    cursor->index = cw_addr(cursor->index + (offset % IDX_MOD));
    cw_update_pc(prog, cursor);
    return 0;
}
