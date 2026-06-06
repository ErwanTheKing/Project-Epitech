/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The main_event.c
*/
/**
 * @file main_event.c
 * @brief The main_event.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"

static void exec_button(world_t *world)
{
    if (world->event.type == sfEvtMouseButtonReleased &&
        world->event.mouseButton.button == sfMouseLeft) {
        click_quit(world);
        click_settings(world);
        click_start(world);
    }
}

void event_main(world_t *world)
{
    exec_button(world);
}
