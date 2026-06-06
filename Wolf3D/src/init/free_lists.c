/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** list cleanup
*/

#include "../../include/wolf3d.h"

void free_game_entities(wolf_t *wolf)
{
    free_player_list(&wolf->list[GAME][MONSTER]);
    free_player_list(&wolf->list[GAME][GARBAGE]);
    free_player_list(&wolf->list[GAME][HEAL]);
}

void free_menu_lists(wolf_t *wolf)
{
    free_draw_list(wolf, MENU, TEXT);
    free_draw_list(wolf, MENU, SPRITE);
    free_draw_list(wolf, NEWGAME_MENU, TEXT);
    free_draw_list(wolf, NEWGAME_MENU, SPRITE);
    free_draw_list(wolf, LOBBY, SPRITE);
    free_draw_list(wolf, GAME_OVER, TEXT);
    free_draw_list(wolf, GAME_OVER, RECT);
}

void free_pause_lists(wolf_t *wolf)
{
    free_draw_list(wolf, PAUSE, RECT);
    free_draw_list(wolf, PAUSE, TEXT);
    free_draw_list(wolf, PAUSE, SPRITE);
}

void free_settings_lists(wolf_t *wolf)
{
    free_draw_list(wolf, SETTINGS, RECT);
    free_draw_list(wolf, SETTINGS, TEXT);
    free_draw_list(wolf, SETTINGS, SPRITE);
    free_draw_list(wolf, SETTINGS, LINE);
    free_draw_list(wolf, SETTINGS, TRIANGLE);
}
