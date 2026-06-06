/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Initialization and cleanup functions
*/

#ifndef INIT_H
    #define INIT_H

    #include "types.h"

typedef struct weapon_config_s {
    wp_type_t type;
    int damage;
    int max_ammo;
    entity_t *entity;
} weapon_config_t;

wolf_t *init_wolf(void);
void init_menu_text(wolf_t *wolf, window_t *window);
game_t *init_game(window_t *window_data);
player_t *init_player(window_t *win, p_type_t type, sfVector2f *pos);
void destroy_player(player_t *player);
void init_menu_entities(wolf_t *wolf, window_t *window);
void free_wolf(wolf_t *wolf);
void free_wolf_resources(wolf_t *wolf);
void free_game(game_t *game);
void free_player_list(list_t **list);
void free_draw_list(wolf_t *wolf, int state, int index);
void free_menu_lists(wolf_t *wolf);
void free_pause_lists(wolf_t *wolf);
void free_settings_lists(wolf_t *wolf);
void free_game_entities(wolf_t *wolf);
void init_hud(hud_t *hud, sfFont *font);
void free_hud(hud_t *hud);
window_t *create_inv(data_t *data, window_t *win, inv_t *inv);
void free_inv(inv_t *inv);
weapon_t *init_weapon(wp_type_t type, int damage,
    int max_ammo, entity_t *entity);
sfRectangleShape *create_rect(sfVector2f *size,
    sfVector2f *pos, sfColor *color);
wolf_t *init_sound_effect(wolf_t *wolf);
void play_sound(sfSound *sound);

#endif
