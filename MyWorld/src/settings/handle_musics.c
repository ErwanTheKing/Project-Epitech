/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The handle_musics.c
*/
/**
 * @file handle_musics.c
 * @brief The handle_musics.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"
#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/macros.h"

static int more(settings_t *settings, world_t *world)
{
    sfVector2u textureSize;

    settings->more.texture = sfTexture_createFromFile(BACK_SQUARE, NULL);
    if (!settings->more.texture)
        return FAILURE;
    settings->more.sprite = sfSprite_create();
    sfSprite_setTexture(settings->more.sprite,
        settings->more.texture, sfTrue);
    textureSize = sfTexture_getSize(settings->more.texture);
    sfSprite_setOrigin(settings->more.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(settings->more.sprite,
        (sfVector2f){world->mode.width / 1.8, world->mode.height / 1.7});
    sfSprite_setScale(settings->more.sprite, (sfVector2f){0.1, 0.1});
    return SUCCESS;
}

static int less(settings_t *settings, world_t *world)
{
    sfVector2u textureSize;

    settings->less.texture = sfTexture_createFromFile(BACK_SQUARE, NULL);
    if (!settings->less.texture)
        return FAILURE;
    settings->less.sprite = sfSprite_create();
    sfSprite_setTexture(settings->less.sprite,
        settings->less.texture, sfTrue);
    textureSize = sfTexture_getSize(settings->less.texture);
    sfSprite_setOrigin(settings->less.sprite,
        (sfVector2f){textureSize.x / 2, textureSize.y / 2});
    sfSprite_setPosition(settings->less.sprite,
        (sfVector2f){world->mode.width / 2.2, world->mode.height / 1.7});
    sfSprite_setScale(settings->less.sprite, (sfVector2f){0.1, 0.1});
    return SUCCESS;
}

static int more_t(settings_t *settings, world_t *world)
{
    sfFloatRect size;

    if (!settings->font)
        return FAILURE;
    settings->more_t = sfText_create();
    sfText_setFont(settings->more_t, settings->font);
    sfText_setString(settings->more_t, "+");
    sfText_setOutlineThickness(settings->more_t, 3);
    sfText_setCharacterSize(settings->more_t, 60);
    size = sfText_getGlobalBounds(settings->more_t);
    sfText_setOrigin(settings->more_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(settings->more_t,
        (sfVector2f){world->mode.width / 1.8, world->mode.height / 1.7});
    sfText_setColor(settings->more_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int less_t(settings_t *settings, world_t *world)
{
    sfFloatRect size;

    if (!settings->font)
        return FAILURE;
    settings->less_t = sfText_create();
    sfText_setFont(settings->less_t, settings->font);
    sfText_setString(settings->less_t, "-");
    sfText_setOutlineThickness(settings->less_t, 3);
    sfText_setCharacterSize(settings->less_t, 60);
    size = sfText_getGlobalBounds(settings->less_t);
    sfText_setOrigin(settings->less_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(settings->less_t,
        (sfVector2f){world->mode.width / 2.2, world->mode.height / 1.7});
    sfText_setColor(settings->less_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int volume(settings_t *settings, world_t *world)
{
    sfFloatRect size;

    if (!settings->font)
        return FAILURE;
    settings->volume = sfText_create();
    sfText_setFont(settings->volume, settings->font_num);
    sfText_setString(settings->volume, "0");
    sfText_setOutlineThickness(settings->volume, 3);
    sfText_setCharacterSize(settings->volume, 30);
    size = sfText_getGlobalBounds(settings->volume);
    sfText_setOrigin(settings->volume,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(settings->volume,
        (sfVector2f){world->mode.width / 2, world->mode.height / 1.7});
    sfText_setColor(settings->volume, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

void click_more(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse
    = sfRenderWindow_mapPixelToCoords(world->window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(world->settings.more.sprite);
    float volume = sfMusic_getVolume(world->main_menu.music);
    float newvolume = volume + 10;

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        if (newvolume > 100.0f)
            newvolume = 100.0f;
        sfMusic_setVolume(world->main_menu.music, newvolume);
    }
}

void click_less(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse
    = sfRenderWindow_mapPixelToCoords(world->window, pixelPos, NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(world->settings.less.sprite);
    float volume = sfMusic_getVolume(world->main_menu.music);
    float newvolume = volume - 10;

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        if (newvolume < 0.0f)
            newvolume = 0.0f;
        sfMusic_setVolume(world->main_menu.music, newvolume);
    }
}

int sprite_musics(settings_t *settings, world_t *world)
{
    if (more(settings, world) == FAILURE)
        return FAILURE;
    if (less(settings, world) == FAILURE)
        return FAILURE;
    if (more_t(settings, world) == FAILURE)
        return FAILURE;
    if (less_t(settings, world) == FAILURE)
        return FAILURE;
    if (volume(settings, world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
