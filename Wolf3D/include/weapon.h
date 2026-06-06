/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Weapon and animation functions
*/

#ifndef WEAPON_H
    #define WEAPON_H

    #include "types.h"

void draw_weapon(wolf_t *wolf, window_t *win, weapon_t *weapon);
void reload_weapon(window_t *win, weapon_t *weapon);
void use_weapon(music_t *music, game_t *game, weapon_t *weapon,
    settings_game_t *settings);
void animate_weapon_walk(wolf_t *wolf, window_t *win, weapon_t *weapon);
void damage_monster(weapon_t *weapon, wolf_t *wolf,
    player_draw_t *draw, player_t *monster);
void damage_monster_by_index(wolf_t *wolf, p_type_t type,
    int entity_index, int damage);

#endif
