/*
** EPITECH PROJECT, 2026
** fill
** File description:
** champs options
*/

#include "../lib/Headers/corewar.h"

static void fill_champion_options(champ_t *champ, int address, int prog_number)
{
    if (address != -1) {
        champ->address.activate = true;
        champ->address.infos = address;
    }
    if (prog_number != -1) {
        champ->prog_number.activate = true;
        champ->prog_number.infos = prog_number;
    }
}

static champ_t *get_champion_at_index(prog_t *prog, int index)
{
    node_t *tmp = prog->list;

    for (int i = 0; i < index && tmp != NULL; i++)
        tmp = tmp->next;
    return (tmp != NULL) ? (champ_t *)tmp->data : NULL;
}

static void process_champion(prog_t *prog, int *champ_index,
    int *current_address, int *current_prog_number)
{
    champ_t *champ = get_champion_at_index(prog, *champ_index);

    if (champ != NULL) {
        fill_champion_options(champ, *current_address,
            *current_prog_number);
        if (*current_prog_number != -1) {
            champ->nb = *current_prog_number;
            champ->process.reg[0] = champ->nb;
        }
        *current_address = -1;
        *current_prog_number = -1;
        (*champ_index)++;
    }
}

static int is_id_used(prog_t *prog, int id)
{
    champ_t *champ = NULL;

    for (node_t *tmp = prog->list; tmp != NULL; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        if (champ->prog_number.activate && champ->nb == id)
            return TRUE;
    }
    return FALSE;
}

static void assign_missing_ids(prog_t *prog)
{
    champ_t *champ = NULL;
    int next_id = 1;

    for (node_t *tmp = prog->list; tmp != NULL; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        if (champ->prog_number.activate)
            continue;
        while (is_id_used(prog, next_id))
            next_id++;
        champ->nb = next_id;
        champ->process.reg[0] = champ->nb;
        next_id++;
    }
}

static int process_flags(char **av, int *i, int ac, int *current_address)
{
    if (my_strcmp(av[*i], (char *)FLAG_ADDRESS) != 0)
        return 0;
    if (*i + 1 < ac)
        *current_address = my_getnbr(av[*i + 1]);
    (*i)++;
    return 1;
}

static int process_prog_number(char **av, int *i, int ac,
    int *current_prog_number)
{
    if (my_strcmp(av[*i], (char *)FLAG_NUMBER) != 0)
        return 0;
    if (*i + 1 < ac)
        *current_prog_number = my_getnbr(av[*i + 1]);
    (*i)++;
    return 1;
}

void fill_champs_options(prog_t *prog, int ac, char **av)
{
    int current_address = -1;
    int current_prog_number = -1;
    int champ_index = 0;

    for (int i = 1; i < ac; i++) {
        if (process_flags(av, &i, ac, &current_address))
            continue;
        if (process_prog_number(av, &i, ac, &current_prog_number))
            continue;
        if (is_champion(av[i]) == TRUE)
            process_champion(prog, &champ_index, &current_address,
                &current_prog_number);
    }
    assign_missing_ids(prog);
}
