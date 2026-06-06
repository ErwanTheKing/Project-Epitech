/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Stage and stage functions
*/

#ifndef STAGE_H
    #define STAGE_H

    #include "types.h"
void init_card(wolf_t *wolf, intermission_t *inter);
void rise_card(wolf_t *wolf, intermission_t *inter);
void draw_card(wolf_t *wolf, intermission_t *inter);
void recreate_card_set(wolf_t *wolf, window_t *win, intermission_t *inter);
void create_card(wolf_t *wolf, card_t *card, sfVector2f *pos,
    sfVector2f *size);
void create_bonus(card_t *card, int rd, inv_t *inv);
void apply_card(wolf_t *wolf, player_t *p, card_t *card);
void create_map(wolf_t *wolf, wall_t *wall);
sfBool are_all_players_dead(wolf_t *wolf);
void reset_game_run(wolf_t *wolf);
void reset_game_run_seed(wolf_t *wolf, uint32_t seed);
void reset_round_run(wolf_t *wolf);
void reset_round_run_seed(wolf_t *wolf, uint32_t seed);
void clear_entity_list(list_t **list);
void reset_game_clocks(wolf_t *wolf);
void reset_inventory_round(inv_t *inv);
void reset_player_state(player_t *player);
void reset_player_round_state(player_t *player);
void notify_game_reset(wolf_t *wolf);
void notify_next_round(wolf_t *wolf);
void notify_game_card(wolf_t *wolf);
void notify_card_ready(wolf_t *wolf);
void notify_player_dead(wolf_t *wolf);
void stage(wolf_t *wolf, player_t *player, sfEvent event);
void card_action(wolf_t *wolf, player_t *player, sfEvent event);
void handle_card_input(wolf_t *wolf, intermission_t *inter, sfEvent event);
int card_under_cursor(wolf_t *wolf, intermission_t *inter);
int hovered_card(intermission_t *inter);
void move_card_cursor(wolf_t *wolf);
bsp_t *bsp_new(int x, int y, int w, int h);
void bsp_free(bsp_t *node);
void bsp_split(bsp_t *node, int depth);
void carve_h(int map[MAP_HEIGHT][MAP_WIDTH], int x1, int x2, int y);
void carve_v(int map[MAP_HEIGHT][MAP_WIDTH], int y1, int y2, int x);
int bsp_room_shape_from_roll(int roll);
void bsp_carve_room_shape(bsp_t *node, int map[MAP_HEIGHT][MAP_WIDTH],
    int shape);
void bsp_place_rooms(bsp_t *node, int map[MAP_HEIGHT][MAP_WIDTH]);
sfVector2i bsp_center(bsp_t *node);

#endif
