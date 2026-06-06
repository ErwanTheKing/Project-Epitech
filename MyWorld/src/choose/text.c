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

static int back(choose_t *choose, world_t *world)
{
    sfFloatRect size;

    if (!world->settings.font)
        return FAILURE;
    choose->back_t = sfText_create();
    sfText_setFont(choose->back_t, world->settings.font);
    sfText_setString(choose->back_t, "BACK");
    sfText_setOutlineThickness(choose->back_t, 3);
    sfText_setCharacterSize(choose->back_t, 60);
    size = sfText_getGlobalBounds(choose->back_t);
    sfText_setOrigin(choose->back_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(choose->back_t,
        (sfVector2f){world->mode.width / 2, world->mode.height / 1.26});
    sfText_setColor(choose->back_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int create(choose_t *choose, world_t *world)
{
    sfFloatRect size;

    if (!world->settings.font)
        return FAILURE;
    choose->create_t = sfText_create();
    sfText_setFont(choose->create_t, world->settings.font);
    sfText_setString(choose->create_t, "CREATE");
    sfText_setOutlineThickness(choose->create_t, 3);
    sfText_setCharacterSize(choose->create_t, 60);
    size = sfText_getGlobalBounds(choose->create_t);
    sfText_setOrigin(choose->create_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(choose->create_t,
        (sfVector2f){world->mode.width / 2.75, world->mode.height / 1.44});
    sfText_setColor(choose->create_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int load(choose_t *choose, world_t *world)
{
    sfFloatRect size;

    if (!world->settings.font)
        return FAILURE;
    choose->load_t = sfText_create();
    sfText_setFont(choose->load_t, world->settings.font);
    sfText_setString(choose->load_t, "LOAD");
    sfText_setOutlineThickness(choose->load_t, 3);
    sfText_setCharacterSize(choose->load_t, 60);
    size = sfText_getGlobalBounds(choose->load_t);
    sfText_setOrigin(choose->load_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(choose->load_t,
        (sfVector2f){world->mode.width / 1.57, world->mode.height / 1.44});
    sfText_setColor(choose->load_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int small(choose_t *choose, world_t *world)
{
    sfFloatRect size;

    if (!world->settings.font_num)
        return FAILURE;
    choose->small_t = sfText_create();
    sfText_setFont(choose->small_t, world->settings.font_num);
    sfText_setString(choose->small_t, "Small    8x8");
    sfText_setOutlineThickness(choose->small_t, 1);
    sfText_setCharacterSize(choose->small_t, 18);
    size = sfText_getGlobalBounds(choose->small_t);
    sfText_setOrigin(choose->small_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(choose->small_t,
        (sfVector2f){world->mode.width / 3.3, world->mode.height / 2.25});
    sfText_setColor(choose->small_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int medium(choose_t *choose, world_t *world)
{
    sfFloatRect size;

    choose->medium_t = sfText_create();
    sfText_setFont(choose->medium_t, world->settings.font_num);
    sfText_setString(choose->medium_t, "Medium    16x16");
    sfText_setOutlineThickness(choose->medium_t, 1);
    sfText_setCharacterSize(choose->medium_t, 18);
    size = sfText_getGlobalBounds(choose->medium_t);
    sfText_setOrigin(choose->medium_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(choose->medium_t,
        (sfVector2f){world->mode.width / 3.36, world->mode.height / 2.05});
    sfText_setColor(choose->medium_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int custom(choose_t *choose, world_t *world)
{
    sfFloatRect size;

    choose->custom_t = sfText_create();
    sfText_setFont(choose->custom_t, world->settings.font_num);
    sfText_setString(choose->custom_t, "Custom :");
    sfText_setOutlineThickness(choose->custom_t, 1);
    sfText_setCharacterSize(choose->custom_t, 18);
    size = sfText_getGlobalBounds(choose->custom_t);
    sfText_setOrigin(choose->custom_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(choose->custom_t,
        (sfVector2f){world->mode.width / 3.31, world->mode.height / 1.74});
    sfText_setColor(choose->custom_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int large(choose_t *choose, world_t *world)
{
    sfFloatRect size;

    choose->large_t = sfText_create();
    sfText_setFont(choose->large_t, world->settings.font_num);
    sfText_setString(choose->large_t, "Large    32x32");
    sfText_setOutlineThickness(choose->large_t, 1);
    sfText_setCharacterSize(choose->large_t, 18);
    size = sfText_getGlobalBounds(choose->large_t);
    sfText_setOrigin(choose->large_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(choose->large_t,
        (sfVector2f){world->mode.width / 3.34, world->mode.height / 1.88});
    sfText_setColor(choose->large_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

static int x_t(choose_t *choose, world_t *world)
{
    sfFloatRect size;

    choose->x_t = sfText_create();
    sfText_setFont(choose->x_t, world->settings.font_num);
    sfText_setString(choose->x_t, "X");
    sfText_setOutlineThickness(choose->x_t, 3);
    sfText_setCharacterSize(choose->x_t, 50);
    size = sfText_getGlobalBounds(choose->x_t);
    sfText_setOrigin(choose->x_t,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(choose->x_t,
        (sfVector2f){world->mode.width / 2.685, world->mode.height / 1.65});
    sfText_setColor(choose->x_t, sfColor_fromRGB(165, 253, 254));
    return SUCCESS;
}

int text_choose(choose_t *choose, world_t *world)
{
    if (back(choose, world) == FAILURE)
        return FAILURE;
    create(choose, world);
    load(choose, world);
    if (small(choose, world) == FAILURE)
        return FAILURE;
    medium(choose, world);
    large(choose, world);
    custom(choose, world);
    x_t(choose, world);
    return SUCCESS;
}
