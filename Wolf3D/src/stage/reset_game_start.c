/*
** EPITECH PROJECT, 2026
** stage
** File description:
** reset game start
*/

#include "../include/wolf3d.h"
#include <time.h>

void reset_game_run(wolf_t *wolf)
{
    reset_game_run_seed(wolf, (uint32_t)time(NULL));
}
