/*
** EPITECH PROJECT, 2025
** RADAR
** File description:
** csfml
*/

#ifndef CSFML_H_
    #define CSFML_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>

typedef enum {
    STATE_MENU,
    STATE_SETTINGS,
    STATE_GAME,
    STATE_QUIT,
} state_t;
typedef struct general_window_struct_s {
    sfRenderWindow *window_ptr;
    sfVideoMode window_dim;
    sfEvent event;
    state_t state;
} general_window_struct_t;

#endif
