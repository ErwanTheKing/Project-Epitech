/*
** EPITECH PROJECT, 2026
** add
** File description:
** champion
*/

#include "../lib/Headers/corewar.h"

void add_champion(prog_t *prog, char *filename)
{
    champ_t *champ = calloc(1, sizeof(champ_t));

    if (champ == NULL)
        return;
    champ->fd = open(filename, O_RDONLY);
    champ->ops = NULL;
    champ->header = NULL;
    champ->prog_number.activate = false;
    champ->prog_number.infos = 0;
    champ->address.activate = false;
    champ->address.infos = 0;
    prog->nb_champ++;
    champ->nb = prog->nb_champ;
    champ->process.reg[0] = champ->nb;
    push_back(&prog->list, champ);
}
