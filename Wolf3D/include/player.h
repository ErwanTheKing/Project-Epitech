/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Player movement, sprint and collision functions
*/

#ifndef PLAYER_H
    #define PLAYER_H

    #include "types.h"

void sprint_player(player_t *player, game_t *game,
    settings_game_t *settings);
float get_speed(player_t *player, float speed, float accel,
    settings_game_t *settings);
void move_player(wolf_t *wolf, player_t *player, sfEvent event,
    game_t *game);
int check_collision(wall_t *wall, float x, float y);
float joystick_axis(sfJoystickAxis axis);
sfBool joystick_action_down(settings_game_t *settings,
    control_action_t action);
sfBool joystick_action_event(settings_game_t *settings,
    control_action_t action, sfEvent event);
sfBool joystick_shoot_down(void);
sfBool joystick_menu_up(sfEvent event);
sfBool joystick_menu_down(sfEvent event);
sfBool joystick_menu_left(sfEvent event);
sfBool joystick_menu_right(sfEvent event);
sfBool joystick_menu_confirm(settings_game_t *settings, sfEvent event);
int joystick_bound_button(settings_game_t *settings, control_action_t action,
    int fallback);
sfBool joystick_slot_previous(settings_game_t *settings, sfEvent event);
sfBool joystick_slot_next(settings_game_t *settings, sfEvent event);
void open_inventory(wolf_t *wolf, sfEvent event, inv_t *inv);
void use_inventory_item(player_t *player, slot_t *slot);
void move_inventory_slot(wolf_t *wolf, sfEvent event, inv_t *inv);
void use_moved_inventory_slot(wolf_t *wolf, sfEvent event, inv_t *inv);
sfBool iskeypressed(int key, sfEvent event);
sfBool isactiondown(settings_game_t *settings, control_action_t action);
sfBool isactionpressed(settings_game_t *settings, control_action_t action,
    sfEvent event);
void draw_selected_item(wolf_t *wolf, inv_t *inv);
void draw_inventory_item(window_t *win, inv_t *inv, int i);
void use_heal(wolf_t *wolf, player_t *player);
#endif
