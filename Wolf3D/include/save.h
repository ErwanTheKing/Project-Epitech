/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Save system
*/

#ifndef SAVE_H
    #define SAVE_H

    #include "types.h"

int save_game(wolf_t *wolf, const char *name);
int load_game(wolf_t *wolf, const char *name);
void save_write_entities(FILE *file, wolf_t *wolf);
int save_read_entities(FILE *file, wolf_t *wolf);
int save_read_inventory_items(FILE *file, inv_t *inv);
void start_save_input(wolf_t *wolf, save_input_mode_t mode);
sfBool handle_save_input(wolf_t *wolf, sfEvent event);
void draw_save_input(wolf_t *wolf);

#endif
