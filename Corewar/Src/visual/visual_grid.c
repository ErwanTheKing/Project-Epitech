/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** visual grid helpers
*/

#include <ncurses.h>
#undef ERR
#include "../../lib/Headers/corewar.h"

int visual_get_champ_color(prog_t *prog, int champion)
{
    champ_t *champ = NULL;
    int pos = 0;

    if (champion <= 0)
        return 7;
    for (node_t *tmp = prog->list; tmp != NULL; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        if (champ->nb == champion)
            return (pos % 6) + 1;
        pos++;
    }
    return 7;
}

void visual_get_grid(visual_grid_t *grid)
{
    grid->height = getmaxy(stdscr);
    grid->width = getmaxx(stdscr);
    if (grid->height < 1)
        grid->height = 1;
    if (grid->width < VISUAL_CELL_WIDTH)
        grid->width = VISUAL_CELL_WIDTH;
    grid->cols = grid->width / VISUAL_CELL_WIDTH;
    grid->rows = grid->height;
    grid->cells = grid->cols * grid->rows;
    if (grid->cells < 1)
        grid->cells = 1;
}

int visual_get_cell_start(const visual_grid_t *grid, int cell)
{
    long value = (long)cell * MEM_SIZE;

    return (int)(value / grid->cells);
}

int visual_get_cell_end(const visual_grid_t *grid, int cell)
{
    long value = (long)(cell + 1) * MEM_SIZE;
    int end = (int)((value + grid->cells - 1) / grid->cells);
    int start = visual_get_cell_start(grid, cell);

    if (end <= start)
        end = start + 1;
    if (end > MEM_SIZE)
        end = MEM_SIZE;
    return end;
}
