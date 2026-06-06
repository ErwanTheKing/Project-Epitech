/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** All game types, structs and enums
*/

#ifndef TYPES_H
    #define TYPES_H

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include "constants.h"
    #include "network.h"
    #include <SFML/Audio.h>

typedef struct entity_s {
    char *name;
    sfClock *clock;
    sfSprite *sprite;
    sfTexture *texture;
} entity_t;

typedef enum {
    PLAYER,
    ENNEMY,
    GARBAGE_T,
    HEAL_T,
} p_type_t;

typedef enum {
    GUN,
    SHOTGUN,
    VACUUM,
    BANDAGE,
} wp_type_t;

typedef struct weapon_s {
    sfClock *cd;
    wp_type_t type;
    sfIntRect rect;
    int max_ammo;
    int current_ammo;
    int damage;
    float attack_speed;
    int current_frame;
    int reloading;
    entity_t *entity;
} weapon_t;

typedef struct bfs_s {
    int visited[MAP_HEIGHT][MAP_WIDTH];
    int from_x[MAP_HEIGHT][MAP_WIDTH];
    int from_y[MAP_HEIGHT][MAP_WIDTH];
    int qx[BFS_QUEUE_SIZE];
    int qy[BFS_QUEUE_SIZE];
    int head;
    int tail;
} bfs_t;

typedef struct bsp_s {
    int x;
    int y;
    int w;
    int h;
    int rx;
    int ry;
    int rw;
    int rh;
    struct bsp_s *left;
    struct bsp_s *right;
} bsp_t;

typedef struct player_s {
    int net_id;
    float x;
    float y;
    float z;
    float speed;
    float angle;
    int max_hp;
    int hp;
    float stamina;
    float regen_cd;
    p_type_t type;
    weapon_t *weapon;
    sfBool alive;
    sfBool running;
    sfClock *ai_clock;
    sfClock *attack_clock;
    sfClock *damage_clock;
    sfBool took_damage;
    float path_target_x;
    float path_target_y;
} player_t;

typedef struct hud_s {
    sfRectangleShape *panel;
    sfRectangleShape *bar[4];
    sfText *text[5];
    sfRectangleShape *mm_bg;
    sfRectangleShape *mm_tile;
    sfRectangleShape *mm_player;
    sfRectangleShape *mm_enemy;
} hud_t;

typedef enum {
    MENU,
    GAME,
    SETTINGS,
    PAUSE,
    NEWGAME_MENU,
    LOBBY,
    GAME_OVER,
    QUIT,
} state_t;

typedef struct lobby_s {
    int phase;
    char ip[16];
    int ip_len;
    int nb_connected;
    int is_host;
    int connect_error;
} lobby_t;

typedef enum {
    SAVE_INPUT_NONE,
    SAVE_INPUT_SAVE,
    SAVE_INPUT_LOAD,
} save_input_mode_t;

typedef struct save_input_s {
    save_input_mode_t mode;
    char name[SAVE_NAME_MAX + 1];
    int len;
    char status[96];
} save_input_t;

typedef struct weapon_save_s {
    int type;
    int ammo;
    int max_ammo;
    int damage;
    float attack_speed;
} weapon_save_t;

typedef enum {
    NEWGAME,
    CONTINUE,
    OPTIONS,
    LEAVE,
    SOLO,
    MULTI,
} menu_t;

typedef enum {
    STAGE,
    CARD,
} game_state_t;

typedef enum {
    SPEED,
    AS,
    DAMAGE,
    ITEM,
    HP,
} card_bonus_t;

typedef struct card_s {
    card_bonus_t bonus;
    double efficiency;
    sfRectangleShape *rect;
    sfText *text;
    sfBool hoover;
} card_t;

typedef struct intermission_s {
    sfClock *clock;
    sfBool done;
    sfBool selected;
    sfBool confirm_down;
    int round; /* 0 = first set, 1 = second set */
    card_t card[3];
} intermission_t;

typedef struct row_s {
    int y;
    float fog;
    int tex_idx;
} row_t;

typedef struct item_s {
    char *name;
    wp_type_t type;
    void *data;
    entity_t *entity;
} item_t;

typedef struct slot_s {
    int index;
    item_t item;
    sfBool selected;
} slot_t;

typedef struct inv_s {
    sfBool open;
    sfText *text;
    slot_t slot[8];
    sfRectangleShape *rect[10];
    item_t item[8];
} inv_t;

typedef struct player_draw_s {
    int num;
    p_type_t type;
    double distance;
    sfVector2f sprite;
    sfVector2f plane;
    sfVector2f transform;
    int sprite_height;
    int sprite_width;
    sfVector2f drawStart;
    sfVector2f drawEnd;
    int offset;
} player_draw_t;

typedef struct list_s {
    void *data;
    struct list_s *next;
} list_t;

typedef enum {
    GRAPHICS,
    AUDIO,
    GAMEPLAY,
    CONTROLS,
    CONTROLLER,
    ACCESSIBILITY,
} settings_t;

typedef enum {
    CTRL_FORWARD,
    CTRL_BACKWARD,
    CTRL_LEFT,
    CTRL_RIGHT,
    CTRL_TURN_LEFT,
    CTRL_TURN_RIGHT,
    CTRL_SPRINT,
    CTRL_INVENTORY,
    CTRL_EQUIP,
    CTRL_RELOAD,
    CTRL_FLASHLIGHT,
    CTRL_HEAL,
    CTRL_PAUSE,
    CTRL_SLOT_1,
    CTRL_SLOT_2,
    CTRL_SLOT_3,
    CTRL_SLOT_4,
    CTRL_SLOT_5,
    CTRL_SLOT_6,
    CTRL_SLOT_7,
    CTRL_SLOT_8,
    CTRL_COUNT
} control_action_t;

typedef struct settings_game_s {
    sfVideoMode resolution;
    sfBool fullscreen;
    sfBool vsync;
    int fov;
    int brightness;
    int max_fps;
    int master_volume;
    int music_volume;
    int sfx_volume;
    int ambient_volume;
    int mouse_sensitivity;
    sfBool invert_mouse;
    sfBool show_hud;
    sfBool show_fps;
    sfBool show_minimap;
    sfBool crosshair;
    sfKeyCode key_bindings[CTRL_COUNT];
    int joystick_bindings[CTRL_COUNT];
} settings_game_t;

typedef enum {
    TYPE_MENU,
    TYPE_SETTINGS
} type_t;

typedef struct triangle_s triangle_t;

typedef struct vertex_s {
    sfVector2f start;
    sfVector2f end;
    sfVertex vertex;
} vertex_t;

typedef struct rect_s {
    char *name;
    int state;
    sfRectangleShape *rect;
    sfTexture *texture;
    sfTexture *click_texture;
    type_t type;
    sfBool always_display;
} rect_t;

typedef struct text_s {
    char *name;
    char *content;
    int state;
    type_t type;
    sfText *text;
    sfBool always_display;
    triangle_t *left_triangle;
    triangle_t *right_triangle;
} text_t;

struct triangle_s {
    sfConvexShape *shape;
    char *name;
    int state;
    int type;
};

typedef struct wall_s {
    int map[MAP_HEIGHT][MAP_WIDTH];
    sfUint8 *wall;
    int wall_index;
    sfTexture *texture;
    sfSprite *sprite;
    sfUint8 *pixel;
    sfUint8 *text_arr[2];
    sfUint8 *decor_arr[6];
} wall_t;

typedef struct crosshair_s {
    sfVector2f pos;
    entity_t *cursor;
} crosshair_t;

typedef struct game_s {
    sfClock *clock[2];
    player_t *entities[MAX_ENTITY];
    int numSprites;
    wall_t *wall;
    float *zbuffer;
    int has_shot;
    inv_t inv;
    crosshair_t crosshair;
    game_state_t state;
    intermission_t inter;
    hud_t hud;
    float camera_sway;
    float camera_bob;
} game_t;

typedef struct window_s {
    sfRenderWindow *window;
    int width;
    int height;
} window_t;

typedef struct data_s {
    sfFont *font;
} data_t;

typedef struct decor_s {
    sfVector2i t;
    sfVector2f floor;
    sfVector2f floorStep;
    sfVector2f rd0;
    sfVector2f rd1;
} decor_t;

typedef struct int_range_s {
    int min;
    int max;
    int step;
} int_range_t;


typedef struct resize_buffers_s {
    sfUint8 *pixel;
    float *zbuffer;
    sfTexture *texture;
} resize_buffers_t;

typedef struct setting_entry_s {
    char *name;
    char *content;
    char *value_name;
    int value;
    int index;
} setting_entry_t;

typedef struct ray_s {
    sfVector2i map;
    sfVector2f delta_dist;
    sfVector2f side_dist;
    sfVector2i step;
} ray_t;

typedef struct music_s {
    sfSound *sound[3];
    sfSoundBuffer *buffer[3];
    sfMusic *music[2];
} music_t;

typedef struct move_ctx_s {
    wall_t *wall;
    player_t *player;
    settings_game_t *settings;
    float dt;
} move_ctx_t;

typedef struct wolf_s {
    settings_game_t *settings;
    settings_game_t *tmp_settings;
    state_t state;
    state_t return_state;
    int menu_state;
    int settings_state;
    player_t *player;
    window_t *window_data;
    data_t *data;
    game_t *game;
    list_t *list[STATES][TO_DRAW];
    client_t net;
    int connected;
    player_t others[MAX_PLAYERS];
    int nb_others;
    sfBool pending_window_recreate;
    sfBool ignore_shot_until_release;
    sfBool flashlight_on;
    sfShader *brightness_shader;
    sfBool brightness_shader_ready;
    sfClock *fps_clock;
    sfText *fps_text;
    int fps_frame_count;
    int fps_current;
    music_t music;
    lobby_t lobby;
    save_input_t save_input;
    int rebinding_control_action;
    int stage;
    int score;
    uint32_t map_seed;
    int card_ready[MAX_PLAYERS];
} wolf_t;

#endif
