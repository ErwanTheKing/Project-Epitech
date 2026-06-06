/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The basic_event*.c
*/
/**
 * @file basic_event.c
 * @brief The basic_event.c
 * @author Erwan Lo Presti
 */

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "../../lib/my/headers/myworld.h"

static void zoom_control(world_t *world)
{
    if (world->event.mouseWheelScroll.delta > 0)
        world->map->zoom += 1.0;
    if (world->event.mouseWheelScroll.delta < 0)
        world->map->zoom -= 1.0;
    if (world->map->zoom < 2.0)
        world->map->zoom = 2.0;
}

static void change_game(world_t *world)
{
    if (world->st_game == GAME || world->st_game == PAUSE_M) {
        if (world->st_game == GAME)
            world->st_game = PAUSE_M;
        else
            world->st_game = GAME;
    }
}

static void exit_window(world_t *world)
{
    if (world->event.type == sfEvtClosed || world->st_game == EXIT)
        sfRenderWindow_close(world->window);
}

void event_basic(world_t *world)
{
    resize(world);
    while (sfRenderWindow_pollEvent(world->window, &world->event)) {
        exit_window(world);
        if (world->st_game == MAIN)
            event_main(world);
        if (world->st_game == SETTINGS_M)
            event_settings(world);
        if (world->st_game == GAME)
            event_game(world);
        if (world->st_game == PAUSE_M)
            event_pause(world);
        if (world->st_game == CHOOSE)
            event_choose(world);
        if (world->st_game == GAME
            && world->event.type == sfEvtMouseWheelScrolled)
            zoom_control(world);
        if (world->event.type == sfEvtKeyPressed
            && world->event.key.code == sfKeyEscape)
            change_game(world);
    }
}

static void change_res(world_t *world)
{
    if (world->event.type == sfEvtKeyPressed &&
        world->event.key.code == sfKeyF11)
        switch_full(world);
}

void display_state(world_t *world)
{
    sfRenderWindow_clear(world->window, sfBlack);
    change_res(world);
    if (world->st_game == MAIN)
        display_main(world);
    if (world->st_game == SETTINGS_M)
        display_settings(world);
    if (world->st_game == GAME) {
        display_game(world);
        manage_camera(world);
        update_terrain(world);
    }
    if (world->st_game == PAUSE_M)
        display_pause(world);
    if (world->st_game == CHOOSE)
        display_choose(world);
}
