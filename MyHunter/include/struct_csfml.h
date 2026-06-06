/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The struct_csfml.h
*/
/**
 * @file struct_csfml.h
 * @brief The struct_csfml.h
 * @author Erwan Lo Presti
 */

#ifndef MY_HUNTER_STRUCT_CSFML_H
    #define MY_HUNTER_STRUCT_CSFML_H
    #include "includes.h"
typedef struct bird_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfBool touch;
    int currentFrame;
    sfIntRect rect;
    sfVector2f pos;
    struct bird_s *next;
} bird_t;

typedef struct ammo_s {
    sfTexture *texture;
    sfSprite *sprite;
    struct ammo_s *next;
} ammo_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
} sprite_t;

typedef struct button_main_s {
    sprite_t play;
    sprite_t settings;
    sprite_t exit;
    sfText *highscore;
    sfText *score;
    sfFont *font;
    sprite_t bg_score;
} button_main_t;

typedef struct text_s {
    sfFont *font;
    sfText *text;
} text_t;

typedef struct button_setting_s {
    sprite_t background;
    sprite_t settings;
    sprite_t back;
    sprite_t more;
    sprite_t less;
    sprite_t res1920;
    sprite_t res800;
    sprite_t enable;
    sprite_t disable;
    sprite_t fps30;
    sprite_t fps60;
    sprite_t fps120;
    sprite_t unlimited;
    text_t music_t;
    sfText *resolution;
    sfText *vsync;
    sfText *fps;
} button_setting_t;

typedef struct bool_s {
    sfRenderWindow *window;
    sfEvent event;
    sfBool res_on;
    sfBool vsync_on;
    int fps_on;
    int game_on;
    int pause_on;
    int settings_on;
    int settings_game;
    int count_point;
    char *str_count;
    sfBool touch;
    char highscore[1000];
    int life;
    int fd;
    int mode;
    bird_t *bird_right;
    ammo_t *mun;
    int speed;
    int ammo;
    float currentTime;
    float lastTime;
    float lastTime_bird;
    float lastTime_speed;
    float lastTime_mov;
} bool_t;

typedef struct button_pause_s {
    sprite_t pause;
    sprite_t restart;
    sprite_t resume;
    sprite_t settings;
    sprite_t mainmenu;
    sprite_t exit;
} button_pause_t;

typedef struct button_loose_s {
    sprite_t background;
    sprite_t mainmenu;
    sprite_t retry;
} button_loose_t;

typedef struct button_chose_mode_s {
    sprite_t background;
    sprite_t eric;
    sprite_t renaud;
    sprite_t back;
} button_chose_mode_t;

typedef struct manage_sprite_s
{
    sprite_t visor;
    sfMusic *snowball;
    sprite_t background;
    sprite_t bird;
    sfClock *clock;
    int currentFrame;
    sfIntRect rect;
    int sprite_count;
    float switchTime;
    sfTime Time;
    sfTime last_Time;
    float deltaTime;
    sfInt64 seconds;
    sfInt64 seconds2;
    sfVector2f vector;
    sfText *score;
    sfText *score_nb;
    sfFont *font;
    sprite_t bg_score;
    sprite_t bg_heart;
    sprite_t heart1;
    sprite_t heart2;
    sprite_t heart3;
    sprite_t heart4;
    sprite_t heart5;
} manage_sprite_t;

typedef struct music_s {
    sfMusic *music;
    sfMusic *snowball;
} music_t;
#endif /* MY_HUNTER_STRUCT_CSFML_H */
