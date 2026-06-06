/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The myworld.c
*/
/**
 * @file myworld.c
 * @brief The myworld.c
 * @author Erwan Lo Presti
 */

#include "../lib/my/headers/myworld.h"

#include <stdio.h>

#include "../lib/my/headers/defines.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

static void destroy(world_t *world)
{
    destroy_main(&world->main_menu);
    destroy_settings(&world->settings);
    if (world->launch == sfTrue)
        destroy_game(world->map);
    destroy_pause(&world->pause);
    destroy_choose(&world->choose);
    sfClock_destroy(world->clock);
    sfRenderWindow_destroy(world->window);
}

static int create_sprite(world_t *world)
{
    if (create_sound(world) == FAILURE)
        return FAILURE;
    if (create_main(world) == FAILURE)
        return FAILURE;
    if (create_settings(world) == FAILURE)
        return FAILURE;
    if (create_pause(world) == FAILURE)
        return FAILURE;
    if (create_choose(world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

static void set_var(world_t *world)
{
    world->st_game = MAIN;
    world->old_st = MAIN_O;
    world->st_res = RES1920;
    world->st_frame = FRAME0;
    world->oldMode = world->mode;
    world->coords.x = 8;
    world->coords.y = 8;
    world->launch = sfFalse;
    sfRenderWindow_setMouseCursorVisible(world->window, sfFalse);
    sfRenderWindow_setVerticalSyncEnabled(world->window, sfTrue);
    sfRenderWindow_setFramerateLimit(world->window, 0);
    world->clock = sfClock_create();
    world->dt = 0.0;
}

int init_game(world_t *world)
{
    sfVector2u size;

    world->map = create_map(world);
    if (world->map == NULL)
        return FAILURE;
    size = sfRenderWindow_getSize(world->window);
    center_map(world->map, size.x, size.y);
    if (create_game(world) == FAILURE)
        return FAILURE;
    if (create_toolbox(world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

static int init_world(world_t *world)
{
    set_var(world);
    if (create_sprite(world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

static void game_loop(world_t *world)
{
    while (sfRenderWindow_isOpen(world->window)) {
        world->dt = sfTime_asSeconds(sfClock_restart(world->clock));
        event_basic(world);
        display_state(world);
        sfRenderWindow_display(world->window);
    }
}

int create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    world_t *world = malloc(sizeof(world_t));

    if (!world)
        return FAILURE;
    world->mode = mode;
    world->window = sfRenderWindow_create(mode, "Transform Mars",
        sfTitlebar | sfClose, NULL);
    if (init_world(world) == FAILURE) {
        free(world);
        return FAILURE;
    }
    game_loop(world);
    destroy(world);
    free(world);
    return SUCCESS;
}
