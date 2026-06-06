/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** visual drawing
*/

#include <ncurses.h>
#undef ERR
#include "../../lib/Headers/corewar.h"

static void draw_empty_cell(int y, int x)
{
    attron(COLOR_PAIR(7));
    mvaddch(y, x, '[');
    mvaddch(y, x + 1, ']');
    attroff(COLOR_PAIR(7));
}

static void draw_owned_cell(int y, int x, int color)
{
    attron(COLOR_PAIR(color) | A_BOLD);
    mvaddch(y, x, '#');
    mvaddch(y, x + 1, '#');
    attroff(COLOR_PAIR(color) | A_BOLD);
}

static void draw_cursor_cell(int y, int x, int color)
{
    attron(COLOR_PAIR(color) | A_BOLD);
    mvaddch(y, x, '@');
    mvaddch(y, x + 1, '@');
    attroff(COLOR_PAIR(color) | A_BOLD);
}

static void draw_cell(prog_t *prog, const visual_grid_t *grid, int y, int col)
{
    int cell = y * grid->cols + col;
    int start = visual_get_cell_start(grid, cell);
    int end = visual_get_cell_end(grid, cell);
    int cursor = visual_get_cursor_owner(prog, start, end);
    int owner = visual_get_range_owner(prog, start, end);
    int x = col * VISUAL_CELL_WIDTH;

    if (cursor > 0) {
        draw_cursor_cell(y, x, visual_get_champ_color(prog, cursor));
        return;
    }
    if (owner > 0) {
        draw_owned_cell(y, x, visual_get_champ_color(prog, owner));
        return;
    }
    draw_empty_cell(y, x);
}

void visual_draw_memory(prog_t *prog)
{
    visual_grid_t grid = {0};

    visual_get_grid(&grid);
    erase();
    for (int y = 0; y < grid.rows; y++) {
        for (int col = 0; col < grid.cols; col++)
            draw_cell(prog, &grid, y, col);
    }
    refresh();
}

void visual_draw_winner(prog_t *prog)
{
    int height = getmaxy(stdscr);
    int width = getmaxx(stdscr);
    int start = 0;

    attron(A_BOLD | COLOR_PAIR(7));
    if (prog->last_live != NULL) {
        start = (width - 24) / 2;
        if (start < 0)
            start = 0;
        mvprintw(height / 2, start, "Winner: %d(%s)",
            prog->last_live->process.id, prog->last_live->process.name);
    } else {
        start = (width - 9) / 2;
        if (start < 0)
            start = 0;
        mvprintw(height / 2, start, "No winner");
    }
    attroff(A_BOLD | COLOR_PAIR(7));
    refresh();
}
