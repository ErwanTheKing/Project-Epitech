/*
** EPITECH PROJECT, 2025
** BSmy_radar
** File description:
** The functions.h
*/
/**
 * @file functions.h
 * @brief The functions.h
 * @author Erwan Lo Presti
 */

#ifndef BSMY_RADAR_FUNCTIONS_H
    #define BSMY_RADAR_FUNCTIONS_H
    #include "includes.h"
void event_basic(main_radar_t *radar);
int create_window(char **argv);
void display_state(main_radar_t *radar);
int create_sprite_main(main_radar_t *radar);
int create_text_main(main_radar_t *radar);
void destroy_main_menu(main_radar_t *radar);
void display_main_menu(main_radar_t *radar);
int create_main(main_radar_t *radar);
void click_exit_main(main_radar_t *radar);
void click_play_main(main_radar_t *radar);
void click_settings_main(main_radar_t *radar);
int create_effects(main_radar_t *radar);
int create_sounds(main_radar_t *radar);
void destroy_sounds(main_radar_t *radar);
int create_music(main_radar_t *radar);
int create_sprite_game(main_radar_t *radar);
int create_game(main_radar_t *radar);
void destroy_game(main_radar_t *radar);
void display_game(main_radar_t *radar);
int verif_file(char *file, main_radar_t *radar);
int add_plane(plane_t **plane, char *buffer);
int add_tower(tower_t **tower, char *buffer);
void draw_plane(main_radar_t *radar);
void del_plane(plane_t **plane);
void draw_tower(main_radar_t *radar);
void del_tower(tower_t **tower);
int create_text_pause(main_radar_t *radar);
int create_sprite_pause(main_radar_t *radar);
void destroy_pause(main_radar_t *radar);
int create_pause(main_radar_t *radar);
void display_pause(main_radar_t *radar);
void click_exit_pause(main_radar_t *radar);
void click_resume_pause(main_radar_t *radar);
void move_plane(infos_plane_t *infos_plane, main_radar_t *radar);
int create_text_game(main_radar_t *radar);
#endif /* BSMY_RADAR_FUNCTIONS_H */
