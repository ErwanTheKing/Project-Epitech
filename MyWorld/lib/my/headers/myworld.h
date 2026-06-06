/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The myworld.h
*/
/**
 * @file myworld.h
 * @brief The myworld.h
 * @author Erwan Lo Presti
 */

#ifndef G_ING_200_NCE_2_1_MYWORLD_1_MYWORLD_H
    #define G_ING_200_NCE_2_1_MYWORLD_1_MYWORLD_H
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
typedef struct s_vector3f {
    float x;
    float y;
    float z;
} vector3f_t;
typedef struct s_vector2f {
    float x;
    float y;
} vector2f_t;
typedef enum state_game_e {
    MAIN,
    GAME,
    SETTINGS_M,
    EXIT,
    PAUSE_M,
    CHOOSE
} state_game_t;
typedef enum old_state_e {
    MAIN_O,
    GAME_O
} old_state_t;
typedef enum state_res_e {
    RES1920,
    RES800
} state_res_t;
typedef enum state_frame_e {
    FRAME0,
    FRAME30,
    FRAME60,
    FRAME120,
    FRAME144,
    FRAME240
} state_frame_t;
typedef enum size_map_e {
    SIZE8,
    SIZE16,
    SIZE32,
    SIZE0
} size_map_t;
typedef struct sprite_s {
    sfTexture *texture;
    sfSprite *sprite;
} sprite_t;
typedef enum tool_sens_e {
    RAISE_T,
    DECREASE_T
} tool_sens_t;
typedef enum tool_size_e {
    POINT_T,
    AREA_T
} tool_size_t;
typedef struct toolbox_s {
    sfFont *font;
    sprite_t tool;
    sprite_t close;
    sprite_t raise;
    sprite_t decrease;
    sprite_t point;
    sprite_t area;
    tool_sens_t sens;
    tool_size_t size;
    sfText *raise_t;
    sfText *decrease_t;
    sfText *point_t;
    sfText *area_t;
    sfBool raise_h;
    sfBool decrease_h;
    sfBool point_h;
    sfBool area_h;
    sfText *size_area;
} toolbox_t;
typedef struct help_s {
    sfRectangleShape *rectangle;
    sfText *help;
    sfText *help_t;
    sfText *toolbox;
    sfText *zoom;
    sfText *move;
    sfText *rotate;
    sfText *direction;
    sfText *size;
    sfText *fullscreen;
    sfText *modify_area;
} help_t;
typedef struct s_map {
    int width;
    int height;
    vector3f_t **points;
    float zoom;
    float angle_x;
    float angle_y;
    sfVector2f offset;
    sprite_t background;
    sprite_t ground;
    toolbox_t toolbox;
    sfBool tool;
    help_t help;
    sfBool help_b;
    sfSound *raise;
    sfSoundBuffer *up;
    sfSound *decrease;
    sfSoundBuffer *down;
    sprite_t underground;
    sprite_t mountain;
    sprite_t save;
    unsigned int size;
} map_t;
typedef struct main_menu_s {
    sprite_t background;
    sprite_t start;
    sprite_t settings;
    sprite_t quit;
    sprite_t logo;
    sprite_t cursor;
    sfMusic *music;
} main_menu_t;
typedef struct settings_s {
    sprite_t settings;
    sprite_t back;
    sfFont *font;
    sfFont *font_num;
    sfText *back_t;
    sfText *full_t;
    sfText *vsync_t;
    sfText *res_t;
    sfText *frame_t;
    sprite_t full_case;
    sprite_t full_check;
    sprite_t vsync_case;;
    sprite_t vsync_check;
    sprite_t res_case;
    sprite_t frame_case;
    sfBool fullscreen;
    sfBool vsync;
    sprite_t more;
    sprite_t less;
    sfText *more_t;
    sfText *less_t;
    sfText *musics;
    sfText *volume;
    int vsync_int;
} settings_t;
typedef struct pause_s {
    sprite_t resume;
    sfText *resume_t;
    sprite_t settings;
    sfText *settings_t;
    sprite_t quit;
    sfText *quit_t;
    sprite_t main;
    sfText *main_t;
} pause_t;
typedef struct textbox_s {
    sfRectangleShape *rectangle;
    sfText *text;
    sfFont *font;
    int length;
    char input[50];
    int selected;
} textbox_t;
typedef struct map_entry_s
{
    sfText *text;
    sfRectangleShape *rectangle;
    sfFont *font;
    char *name;
    char *fullname;
} map_entry_t;
typedef struct choose_s {
    sprite_t background;
    sprite_t back;
    sfText *back_t;
    sprite_t create;
    sfText *create_t;
    sprite_t load;
    sfText *load_t;
    sfCircleShape *small;
    sfText *small_t;
    sfCircleShape *medium;
    sfText *medium_t;
    sfCircleShape *large;
    sfText *large_t;
    sfCircleShape *custom;
    sfText *custom_t;
    sfCircleShape *selected;
    size_map_t size;
    textbox_t *name;
    textbox_t *size_x;
    textbox_t *size_y;
    sfText *x_t;
    map_entry_t *maps;
    int count_map;
    int len;
    int up_down;
    int index_selected;
} choose_t;
typedef struct coords_s {
    unsigned int x;
    unsigned int y;
} coords_t;
typedef struct world_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfVideoMode oldMode;
    sfEvent event;
    main_menu_t main_menu;
    settings_t settings;
    pause_t pause;
    choose_t choose;
    state_game_t st_game;
    old_state_t old_st;
    state_res_t st_res;
    state_frame_t st_frame;
    map_t *map;
    coords_t coords;
    sfBool launch;
    sfClock *clock;
    float dt;
} world_t;
int create_window(void);
void event_basic(world_t *world);
int sprite_main(main_menu_t *main_menu, world_t *world);
void display_main(world_t *world);
void display_state(world_t *world);
int create_main(world_t *world);
void destroy_main(main_menu_t *main_menu);
int create_sound(world_t *world);
sfVector2f project_iso_point(int x, int y, float z, map_t *map);
sfVertexArray *create_quad(sfVector2f *p1, sfVector2f *p2,
    sfVector2f *p3, sfVector2f *p4);
void draw_map(sfRenderWindow *window, map_t *map);
void click_quit(world_t *world);
void event_main(world_t *world);
void destroy_settings(settings_t *settings);
int sprite_settings(settings_t *settings, world_t *world);
void display_cursor(world_t *world);
void display_settings(world_t *world);
int create_settings(world_t *world);
void click_settings(world_t *world);
void event_settings(world_t *world);
void click_back_s(world_t *world);
int text_settings(settings_t *settings, world_t *world);
void click_full(world_t *world);
void resize_sprite(sfSprite *sprite, sfVector2f *position, sfVector2f *scale);
void resize_main(main_menu_t *main_menu, world_t *world);
void resize_settings(settings_t *settings, world_t *world);
void resize_text(sfText *text, sfVector2f *position, unsigned int scale);
void click_vsync(world_t *world);
void click_start(world_t *world);
map_t *create_map(world_t *world);
void manage_camera(world_t *world);
int sprite_game(map_t *map);
void destroy_game(map_t *map);
void display_game(world_t *world);
int create_game(world_t *world);
void click_res(world_t *world);
void resize(world_t *world);
void chose_framerate(world_t *world);
void click_frame(world_t *world);
int sprite_musics(settings_t *settings, world_t *world);
void click_more(world_t *world);
void click_less(world_t *world);
void resize_game(map_t *map, world_t *world);
void event_game(world_t *world);
int sprite_pause(pause_t *pause, world_t *world);
int create_pause(world_t *world);
void destroy_pause(pause_t *pause);
void display_pause(world_t *world);
void event_pause(world_t *world);
int text_pause(pause_t *pause, world_t *world);
void resize_pause(pause_t *pause, world_t *world);
void click_quit_p(world_t *world);
void click_resume(world_t *world);
void click_settings_p(world_t *world);
void click_main(world_t *world);
int sprite_choose(choose_t *choose, world_t *world);
int create_choose(world_t *world);
void destroy_choose(choose_t *choose);
void display_choose(world_t *world);
void event_choose(world_t *world);
void resize_choose(choose_t *choose, world_t *world);
int text_choose(choose_t *choose, world_t *world);
void click_back_c(world_t *world);
int circle_choose(choose_t *choose, world_t *world);
void resize_circle(sfCircleShape *circle, sfVector2f *position, float radius);
int init_game(world_t *world);
void click_create(world_t *world);
void click_size(world_t *world);
sfVector2f get_mouse_3d_pos(sfVector2i *mouse, map_t *map);
void update_terrain(world_t *world);
void display_toolbox(world_t *world);
void destroy_toolbox(toolbox_t *toolbox);
int sprite_toolbox(toolbox_t *toolbox, world_t *world);
int create_toolbox(world_t *world);
void click_tool(world_t *world);
void click_close(world_t *world);
void hover(world_t *world);
void selected_tool(world_t *world);
void click_toolbox(world_t *world);
int text_toolbox(toolbox_t *toolbox, world_t *world);
void resize_toolbox(toolbox_t *toolbox, world_t *world);
int rectangle_help(help_t *help, world_t *world);
int text_game(help_t *help, world_t *world);
void switch_full(world_t *world);
textbox_t *create_textbox(sfVector2f *pos, sfVector2f *size);
int textbox(choose_t *choose, world_t *world);
void click_box(world_t *world, textbox_t *box);
void resize_textbox(textbox_t *box, sfVector2f *position, sfVector2f *size,
    unsigned int scale);
int text_help(help_t *help, world_t *world);
int create_disp_maps(choose_t *choose);
void click_load_map(map_entry_t *maps, world_t *world);
int len_array(char **array);
map_t *load_map(world_t *world);
void click_load(world_t *world);
void center_map(map_t *map, int window_width, int window_height);
int save_map(map_t *map, choose_t *choose);
void click_save(world_t *world);
void get_size_custom(world_t *world, textbox_t *sizeX, textbox_t *sizeY);
#endif /* G_ING_200_NCE_2_1_MYWORLD_1_MYWORLD_H */
