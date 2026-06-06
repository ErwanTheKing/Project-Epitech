/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** cleanup entry point
*/

#include "../../include/wolf3d.h"

void free_wolf(wolf_t *wolf)
{
    if (!wolf)
        return;
    if (wolf->net.socket)
        client_close(&wolf->net);
    free_wolf_resources(wolf);
    if (wolf->player)
        destroy_player(wolf->player);
    free_game(wolf->game);
    free_menu_lists(wolf);
    free_game_entities(wolf);
    free_pause_lists(wolf);
    free_settings_lists(wolf);
    if (wolf->data)
        free(wolf->data);
    if (wolf->settings)
        free(wolf->settings);
    if (wolf->tmp_settings)
        free(wolf->tmp_settings);
    free(wolf);
}
