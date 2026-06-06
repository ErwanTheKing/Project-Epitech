/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The text.c
*/
/**
 * @file text.c
 * @brief The text.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"
#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/macros.h"

static int text_resume(pause_t *pause, world_t *world)
{
    sfFloatRect size;

    if (!world->settings.font)
        return FAILURE;
    pause->resume_t = sfText_create();
    sfText_setFont(pause->resume_t, world->settings.font);
    sfText_setString(pause->resume_t, "RESUME");
    sfText_setOutlineThickness(pause->resume_t, 5);
    sfText_setCharacterSize(pause->resume_t, 70);
    size = sfText_getGlobalBounds(pause->resume_t);
    sfText_setOrigin(pause->resume_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(pause->resume_t,
        (sfVector2f){world->mode.width / 3, world->mode.height / 3});
    sfText_setColor(pause->resume_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int text_settings_p(pause_t *pause, world_t *world)
{
    sfFloatRect size;

    if (!world->settings.font)
        return FAILURE;
    pause->settings_t = sfText_create();
    sfText_setFont(pause->settings_t, world->settings.font);
    sfText_setString(pause->settings_t, "SETTINGS");
    sfText_setOutlineThickness(pause->settings_t, 5);
    sfText_setCharacterSize(pause->settings_t, 70);
    size = sfText_getGlobalBounds(pause->settings_t);
    sfText_setOrigin(pause->settings_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(pause->settings_t,
        (sfVector2f){world->mode.width / 1.5, world->mode.height / 3});
    sfText_setColor(pause->settings_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int text_quit(pause_t *pause, world_t *world)
{
    sfFloatRect size;

    if (!world->settings.font)
        return FAILURE;
    pause->quit_t = sfText_create();
    sfText_setFont(pause->quit_t, world->settings.font);
    sfText_setString(pause->quit_t, "QUIT");
    sfText_setOutlineThickness(pause->quit_t, 5);
    sfText_setCharacterSize(pause->quit_t, 70);
    size = sfText_getGlobalBounds(pause->quit_t);
    sfText_setOrigin(pause->quit_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(pause->quit_t,
        (sfVector2f){world->mode.width / 2, world->mode.height / 1.5});
    sfText_setColor(pause->quit_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int text_main(pause_t *pause, world_t *world)
{
    sfFloatRect size;

    if (!world->settings.font)
        return FAILURE;
    pause->main_t = sfText_create();
    sfText_setFont(pause->main_t, world->settings.font);
    sfText_setString(pause->main_t, "MAIN MENU");
    sfText_setOutlineThickness(pause->main_t, 5);
    sfText_setCharacterSize(pause->main_t, 70);
    size = sfText_getGlobalBounds(pause->main_t);
    sfText_setOrigin(pause->main_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(pause->main_t,
        (sfVector2f){world->mode.width / 2, world->mode.height / 1.25});
    sfText_setColor(pause->main_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

int text_pause(pause_t *pause, world_t *world)
{
    if (text_resume(pause, world) == FAILURE)
        return FAILURE;
    if (text_settings_p(pause, world) == FAILURE)
        return FAILURE;
    if (text_quit(pause, world) == FAILURE)
        return FAILURE;
    if (text_main(pause, world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
