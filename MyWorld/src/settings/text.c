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

static int text_back(settings_t *settings, world_t *world)
{
    sfFloatRect size;

    settings->font = sfFont_createFromFile(FONT);
    if (!settings->font)
        return FAILURE;
    settings->back_t = sfText_create();
    sfText_setFont(settings->back_t, settings->font);
    sfText_setString(settings->back_t, "BACK");
    sfText_setOutlineThickness(settings->back_t, 5);
    sfText_setCharacterSize(settings->back_t, 70);
    size = sfText_getGlobalBounds(settings->back_t);
    sfText_setOrigin(settings->back_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(settings->back_t,
        (sfVector2f){world->mode.width / 2, world->mode.height / 1.33});
    sfText_setColor(settings->back_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int text_fullscreen(settings_t *settings, world_t *world)
{
    sfFloatRect size;

    if (!settings->font)
        return FAILURE;
    settings->full_t = sfText_create();
    sfText_setFont(settings->full_t, settings->font);
    sfText_setString(settings->full_t, "Fullscreen");
    sfText_setOutlineThickness(settings->full_t, 5);
    sfText_setCharacterSize(settings->full_t, 30);
    size = sfText_getGlobalBounds(settings->full_t);
    sfText_setOrigin(settings->full_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(settings->full_t,
        (sfVector2f){world->mode.width / 2.25, world->mode.height / 3.1});
    sfText_setColor(settings->full_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int text_vsync(settings_t *settings, world_t *world)
{
    sfFloatRect size;

    if (!settings->font)
        return FAILURE;
    settings->vsync_t = sfText_create();
    sfText_setFont(settings->vsync_t, settings->font);
    sfText_setString(settings->vsync_t, "Vsync");
    sfText_setOutlineThickness(settings->vsync_t, 5);
    sfText_setCharacterSize(settings->vsync_t, 30);
    size = sfText_getGlobalBounds(settings->vsync_t);
    sfText_setOrigin(settings->vsync_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(settings->vsync_t,
        (sfVector2f){world->mode.width / 2.37, world->mode.height / 2.52});
    sfText_setColor(settings->vsync_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int text_res(settings_t *settings, world_t *world)
{
    sfFloatRect size;

    settings->font_num = sfFont_createFromFile(FONT_NUM);
    if (!settings->font_num)
        return FAILURE;
    settings->res_t = sfText_create();
    sfText_setFont(settings->res_t, settings->font_num);
    sfText_setString(settings->res_t, "Resolution : 1920x1080");
    sfText_setOutlineThickness(settings->res_t, 3);
    sfText_setCharacterSize(settings->res_t, 18);
    size = sfText_getGlobalBounds(settings->res_t);
    sfText_setOrigin(settings->res_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(settings->res_t,
        (sfVector2f){world->mode.width / 2.4, world->mode.height / 2.1});
    sfText_setColor(settings->res_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int text_frame(settings_t *settings, world_t *world)
{
    sfFloatRect size;

    if (!settings->font_num)
        return FAILURE;
    settings->frame_t = sfText_create();
    sfText_setFont(settings->frame_t, settings->font_num);
    sfText_setString(settings->frame_t, "Framerate : Unlimited");
    sfText_setOutlineThickness(settings->frame_t, 3);
    sfText_setCharacterSize(settings->frame_t, 18);
    size = sfText_getGlobalBounds(settings->frame_t);
    sfText_setOrigin(settings->frame_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(settings->frame_t,
        (sfVector2f){world->mode.width / 1.72, world->mode.height / 2.1});
    sfText_setColor(settings->frame_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int text_musics(settings_t *settings, world_t *world)
{
    sfFloatRect size;

    if (!settings->font)
        return FAILURE;
    settings->musics = sfText_create();
    sfText_setFont(settings->musics, settings->font);
    sfText_setString(settings->musics, "Musics");
    sfText_setOutlineThickness(settings->musics, 3);
    sfText_setCharacterSize(settings->musics, 50);
    size = sfText_getGlobalBounds(settings->musics);
    sfText_setOrigin(settings->musics,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(settings->musics,
        (sfVector2f){world->mode.width / 2, world->mode.height / 1.9});
    sfText_setColor(settings->musics, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

int text_settings(settings_t *settings, world_t *world)
{
    if (text_back(settings, world) == FAILURE)
        return FAILURE;
    if (text_fullscreen(settings, world) == FAILURE)
        return FAILURE;
    if (text_vsync(settings, world) == FAILURE)
        return FAILURE;
    if (text_res(settings, world) == FAILURE)
        return FAILURE;
    if (text_frame(settings, world) == FAILURE)
        return FAILURE;
    if (text_musics(settings, world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
