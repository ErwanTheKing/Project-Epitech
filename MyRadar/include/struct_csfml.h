/*
** EPITECH PROJECT, 2025
** BSmy_radar
** File description:
** The struct_csfml.h
*/
/**
 * @file struct_csfml.h
 * @brief The struct_csfml.h
 * @author Erwan Lo Presti
 */

#ifndef BSMY_RADAR_STRUCT_CSFML_H
    #define BSMY_RADAR_STRUCT_CSFML_H
    #include "includes.h"
typedef enum state_game_e {
    MAIN,
    PAUSE,
    GAME,
    EXIT
} state_game_t;

typedef enum state_main_e {
    PLAY,
    LEAVE
} state_main_t;

typedef enum state_pause_e {
    RESUME,
    QUIT
} state_pause_t;

typedef struct sprite_texture_s {
    sfTexture *texture;
    sfSprite *sprite;
} sprite_texture_t;

typedef struct my_clock_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} my_clock_t;

typedef struct infos_plane_s {
    int dep_x;
    int dep_y;
    int arr_x;
    int arr_y;
    int speed;
    int time_dep;
    sfBool arr;
    sprite_texture_t design;
    sfRectangleShape *hitbox;
    sfBool disp_plane;
    sfBool disp_hitbox;
} infos_plane_t;

typedef struct plane_s {
    void *data;
    struct plane_s *next;
} plane_t;

typedef struct infos_tower_s {
    int x;
    int y;
    int radius;
    sprite_texture_t design;
    sfCircleShape *area;
    sfBool disp_tower;
    sfBool disp_area;
} infos_tower_t;

typedef struct tower_s {
    void *data;
    struct tower_s *next;
} tower_t;

typedef struct asset_main_s {
    sprite_texture_t background;
    sprite_texture_t logo;
    sfFont *font;
    sfText *exit;
    sfText *play;
    int touch_play;
    int touch_exit;
} asset_main_t;

typedef struct asset_pause_s {
    sprite_texture_t background;
    sprite_texture_t logo;
    sprite_texture_t over_pause;
    sfFont *font;
    sfText *pause;
    sfText *resume;
    sfText *exit;
    int touch_resume;
    int touch_exit;
} asset_pause_t;

typedef struct asset_game_s {
    sprite_texture_t background;
    sfFont *font;
    sfText *hitbox;
    sfText *sprite;
    sfText *hit_status;
    sfText *spr_status;
    sfText *time_l;
    sfText *time_r;
    sfText *separator;
    sfText *fps;
    sfText *fps_status;
} asset_game_t;

typedef struct asset_music_s
{
    sfMusic *click;
    sfMusic *select;
    sfMusic *music;
} asset_music_t;

typedef struct main_radar_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    my_clock_t clock;
    my_clock_t last_clock;
    state_game_t st_game;
    state_main_t st_main;
    state_pause_t st_pause;
    asset_main_t main;
    asset_game_t game;
    asset_pause_t pause;
    asset_music_t sounds;
    plane_t *plane;
    tower_t *tower;
    char **file_infos;
    sfBool escape_pause;
    sfBool disp_sprite;
    sfBool disp_hitbox;
    sfClock *clock_time;
    sfTime time;
    int minutes;
    float seconds;
    sfClock *clock_fps;
    int first;
    int fps;
} main_radar_t;
#endif /* BSMY_RADAR_STRUCT_CSFML_H */
