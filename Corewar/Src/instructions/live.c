/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** live
*/

#include "../../lib/Headers/corewar.h"

static champ_t *find_champ_by_id(prog_t *prog, int player_id)
{
    champ_t *champ = NULL;

    for (node_t *tmp = prog->list; tmp != NULL; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        if (champ->process.id == player_id)
            return champ;
    }
    return NULL;
}

int live(prog_t *prog, cursor_t *cursor)
{
    int player_id = cw_read_mem(prog, cursor->index + 1, DIR_SIZE);
    champ_t *champ = find_champ_by_id(prog, player_id);

    if (champ == NULL || champ->process.is_dead)
        return LIVE;
    cursor->alive = ALIVE;
    cursor->process.alive = ALIVE;
    prog->nbr_live++;
    champ->process.alive = ALIVE;
    prog->last_live = champ;
    if (prog->visual)
        return LIVE;
    my_putstr("The player ");
    my_put_nbr(champ->process.id);
    my_putchar('(');
    my_putstr(champ->process.name);
    my_putstr(") is alive.\n");
    return LIVE;
}
