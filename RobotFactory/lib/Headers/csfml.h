/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** CSFML helper structures and graphics utility function prototypes
*/
/**
 * @file csfml.h
 * @brief CSFML helper structures and graphics utility function prototypes
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#ifndef CSFML_H_
    #define CSFML_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>

typedef enum {
    STATE_MENU,
    STATE_NEW_MAP,
    STATE_LOAD_MAP,
    STATE_CREATE_MAP,
    STATE_PAUSE,
    STATE_SAVE,
    STATE_SETTINGS,
    STATE_QUIT,
} state_t;
typedef struct button_s {
    sfVector2f position;
    sfVector2f size;
    sfSprite *sprite;
    sfSprite *dark_sprite;
    sfSprite *click_sprite;
    sfTexture *tex;
    sfTexture *tex_d;
    sfTexture *tex_c;
    void (*callback)(void);
} button_t;
typedef struct menu_s {
    button_t *new;
    button_t *load;
    button_t *quit;
    button_t *setts;
    button_t *save;
} menu_t;
typedef struct general_window_struct_s {
    sfRenderWindow *window_ptr;
    sfVideoMode window_dim;
    sfEvent event;
    state_t state;
    state_t prev_state;
    menu_t menu;
    sfVector2i mouse_pos;
    unsigned int target_fps;
} general_window_struct_t;

typedef struct specification_s specification_t;
void handle_button_event(menu_t *menu_t, general_window_struct_t *window_t,
    specification_t *spec);
void handle_save_menu(general_window_struct_t *window_t,
    menu_t *menu, specification_t *spec);

#endif
