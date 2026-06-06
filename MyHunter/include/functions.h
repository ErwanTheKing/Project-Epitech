/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The functions.h
*/
/**
 * @file functions.h
 * @brief The functions.h
 * @author Erwan Lo Presti
 */

#ifndef MY_HUNTER_FUNCTIONS_H
    #define MY_HUNTER_FUNCTIONS_H
    #include "includes.h"
void dead(bool_t *bool, sfRenderWindow *window, music_t *music);
int create_window(void);
int main_menu(sfRenderWindow *window, music_t *music, bool_t *bool);
void create_button_main(button_main_t *manage_button);
void click_exit(sfSprite *sprite, sfRenderWindow *window);
void click_settings(sfSprite *sprite, sfRenderWindow *window, music_t *music,
    bool_t *bool);
int settings_menu(sfRenderWindow *window, music_t *music, bool_t *bool);
void create_button_settings(button_setting_t *manage_button);
void create_text_settings(button_setting_t *manage_button);
int click_back(sfSprite *sprite, sfRenderWindow *window, music_t *music,
    bool_t *bool);
void click_more(sfSprite *sprite, sfRenderWindow *window, music_t *music);
void click_less(sfSprite *sprite, sfRenderWindow *window, music_t *music);
int my_hunter(sfRenderWindow *window, music_t *music, bool_t *bool);
void click_play(sfSprite *sprite, sfRenderWindow *window, music_t *music,
    bool_t *bool);
bird_t *add_bird(bird_t *head, manage_sprite_t *manage_sprite);
void draw_bird(bird_t *head, sfRenderWindow *window);
void destroy_bird(bird_t *head);
void create_button_pause(button_pause_t *manage_button);
int pause_menu(sfRenderWindow *window, music_t *music, bool_t *bool);
void click_res(button_setting_t *manage_button, sfRenderWindow *window,
    bool_t *bool);
void click_vsync(button_setting_t *manage_button, sfRenderWindow *window,
    bool_t *bool);
void click_fps(button_setting_t *manage_button, sfRenderWindow *window,
    bool_t *bool);
void create_background(button_setting_t *manage_button);
int click_resume(sfSprite *sprite, sfRenderWindow *window);
int click_mainmenu(sfSprite *sprite, sfRenderWindow *window, music_t *music,
    bool_t *bool);
void click_sprite(sfRenderWindow *window, bool_t *bool);
void create_button_settings2(button_setting_t *manage_button);
void create_text_game(manage_sprite_t *manage_sprite);
char *my_nbr_to_str(int nb);
void create_sprite_game(manage_sprite_t *manage_sprite,
    sfRenderWindow *window);
void create_text_main(button_main_t *manage_sprite);
bird_t *create_bird(bird_t *head);
int my_strlen(char *str);
int my_strcmp(char const *s1, char const *s2);
void destroy_hunter(manage_sprite_t *manage_sprite, bool_t *bool);
void execute_hunter(sfRenderWindow *window, manage_sprite_t *manage_sprite,
    bool_t *bool);
int loose_menu(sfRenderWindow *window, bool_t *bool, music_t *music);
int my_getnbr(char const *str);
void create_sprite_loose(button_loose_t *manage_sprite);
int click_retry(sfSprite *sprite, sfRenderWindow *window,
    music_t *music, bool_t *bool);
int click_mainmenu_loose(sfSprite *sprite, sfRenderWindow *window,
    music_t *music, bool_t *bool);
void create_sprite_chose(button_chose_mode_t *manage_sprite);
int chose_mode(sfRenderWindow *window, bool_t *bool, music_t *music);
int click_eric(sfSprite *sprite, sfRenderWindow *window,
    music_t *music, bool_t *bool);
int click_renaud(sfSprite *sprite, sfRenderWindow *window,
    music_t *music, bool_t *bool);
int click_back_chose(sfSprite *sprite, sfRenderWindow *window, music_t *music,
    bool_t *bool);
ammo_t *add_ammo(ammo_t *ammo);
void draw_ammo(sfRenderWindow *window, ammo_t *ammo, bool_t *bool);
void destroy_ammo(ammo_t *ammo);
void loose_ammo(bool_t *bool);
#endif /* MY_HUNTER_FUNCTIONS_H */
