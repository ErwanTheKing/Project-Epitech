/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** check period and dead cursors
*/

#include "../lib/Headers/corewar.h"
#include <stdlib.h>

static int champion_has_cursor(prog_t *prog, int champion)
{
    for (cursor_t *cur = prog->cursors; cur != NULL; cur = cur->next) {
        if (cur->champion == champion)
            return TRUE;
    }
    return FALSE;
}

static int count_alive_champions(prog_t *prog)
{
    int count = 0;
    champ_t *champ = NULL;

    for (node_t *tmp = prog->list; tmp != NULL; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        if (!champ->process.is_dead && champ->process.alive)
            count++;
    }
    return count;
}

static int cursor_must_die(prog_t *prog, cursor_t *cur)
{
    champ_t *champ = get_champ(prog, cur->champion);

    if (champ == NULL || champ->process.is_dead)
        return TRUE;
    if (!champ->process.alive)
        return TRUE;
    if (!cur->alive)
        return TRUE;
    return FALSE;
}

static cursor_t *remove_cursor(prog_t *prog, cursor_t *prev, cursor_t *cur)
{
    cursor_t *next = cur->next;

    if (prev != NULL)
        prev->next = next;
    if (prev == NULL)
        prog->cursors = next;
    free(cur);
    return next;
}

static void remove_dead_cursors(prog_t *prog)
{
    cursor_t *cur = prog->cursors;
    cursor_t *prev = NULL;

    while (cur != NULL) {
        if (cursor_must_die(prog, cur)) {
            cur = remove_cursor(prog, prev, cur);
            continue;
        }
        cur->alive = 0;
        cur->process.alive = 0;
        prev = cur;
        cur = cur->next;
    }
}

static void update_champions_state(prog_t *prog)
{
    champ_t *champ = NULL;

    for (node_t *tmp = prog->list; tmp != NULL; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        if (!champion_has_cursor(prog, champ->nb))
            champ->process.is_dead = 1;
        champ->process.alive = 0;
    }
}

static int active_champions_count(prog_t *prog)
{
    int count = 0;
    champ_t *champ = NULL;

    for (node_t *tmp = prog->list; tmp != NULL; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        if (champion_has_cursor(prog, champ->nb))
            count++;
    }
    return count;
}

void corewar_check_period(prog_t *prog)
{
    int alive_champs = count_alive_champions(prog);

    remove_dead_cursors(prog);
    update_champions_state(prog);
    if (alive_champs <= 1 || active_champions_count(prog) <= 1) {
        prog->cycle_to_die = 0;
        prog->nbr_live = 0;
        return;
    }
    if (prog->nbr_live >= NBR_LIVE || prog->checks >= MAX_CHECKS) {
        prog->cycle_to_die -= CYCLE_DELTA;
        prog->checks = 0;
    } else {
        prog->checks++;
    }
    prog->nbr_live = 0;
}
