/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** corewar
*/

#include "../lib/Headers/corewar.h"

static int load_champions(prog_t *prog)
{
    node_t *tmp = NULL;
    champ_t *champ = NULL;
    int position = 0;
    int address = 0;

    for (tmp = prog->list; tmp != NULL; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        if (champ->address.activate)
            address = champ->address.infos;
        else
            address = position * (MEM_SIZE / prog->nb_champ);
        if (read_champ(champ, prog, address) == FAILURE) {
            close_files(prog);
            return FAILURE;
        }
        position++;
    }
    return SUCCESS;
}

int corewar(int ac, char **av)
{
    prog_t prog = {0};

    if (count_champions(&prog, ac, av) != TRUE)
        return FAILURE;
    fill_champs_options(&prog, ac, av);
    if (is_files_open(&prog) == FALSE)
        return FAILURE;
    fill_prog(&prog, ac, av);
    init_vm(&prog);
    if (load_champions(&prog) == FAILURE)
        return FAILURE;
    if (prog.visual)
        corewar_visual_loop(&prog);
    else
        corewar_loop(&prog);
    if (prog.dump_cycle < 0)
        print_winner(&prog);
    close_files(&prog);
    return SUCCESS;
}
