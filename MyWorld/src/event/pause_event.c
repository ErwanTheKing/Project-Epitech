/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The game_event.c
*/
/**
 * @file game_event.c
 * @brief The game_event.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../../lib/my/headers/myworld.h"

static void exec_button(world_t *world)
{
    if (world->event.type == sfEvtMouseButtonPressed
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        click_quit_p(world);
        click_resume(world);
        click_settings_p(world);
        click_main(world);
    }
}

void event_pause(world_t *world)
{
    exec_button(world);
}
