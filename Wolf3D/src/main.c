/*
** EPITECH PROJECT, 2026
** main
** File description:
** main
*/

#include "../include/wolf3d.h"

int main(void)
{
    wolf_t *wolf = init_wolf();
    int status = 0;

    if (!wolf)
        return 84;
    status = program(wolf->window_data->window, (sfEvent){0}, wolf);
    free_wolf(wolf);
    return status;
}
