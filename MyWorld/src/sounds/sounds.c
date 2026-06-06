/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The sounds.c
*/
/**
 * @file sounds.c
 * @brief The sounds.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/macros.h"
#include "../../lib/my/headers/myworld.h"

static int main_sound(main_menu_t *main_menu)
{
    main_menu->music = sfMusic_createFromFile(MAIN_SOUND);
    if (!main_menu->music)
        return FAILURE;
    sfMusic_setVolume(main_menu->music, 50);
    sfMusic_setLoop(main_menu->music, sfTrue);
    return SUCCESS;
}

int create_sound(world_t *world)
{
    if (main_sound(&world->main_menu) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
