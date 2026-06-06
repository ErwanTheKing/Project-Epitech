/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Menu, game state and monster functions
*/

#ifndef MENU_H
    #define MENU_H

    #include "types.h"

void menu(wolf_t *wolf);
void manage_menu(wolf_t *wolf, sfEvent event);
void manage_game_over(wolf_t *wolf, sfEvent event);
void manage_pause(wolf_t *wolf, sfEvent event);
void init_pause_entities(wolf_t *wolf, window_t *window);
void init_pause_buttons(wolf_t *wolf, window_t *window);
void pause_apply_action(wolf_t *wolf, const char *name);
sfBool iskeypressed(int key, sfEvent event);
void manage_newgame_menu(wolf_t *wolf, sfEvent event);
void manage_lobby(wolf_t *wolf, sfEvent event);
void draw_lobby(wolf_t *wolf);
void back_to_newgame_menu(wolf_t *wolf);
void check_player_state(wolf_t *wolf);
void is_near_monster(wolf_t *wolf, player_t *player);

#endif
