/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** The text_main.c
*/
/**
 * @file text_main.c
 * @brief The text_main.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static int text_pause(main_radar_t *radar)
{
    sfFloatRect size;

    radar->pause.font = sfFont_createFromFile(FONT);
    if (!radar->pause.font)
        return FAILURE;
    radar->pause.pause = sfText_create();
    sfText_setFont(radar->pause.pause, radar->pause.font);
    sfText_setString(radar->pause.pause, "PAUSE");
    sfText_setOutlineThickness(radar->pause.pause, 10);
    sfText_setCharacterSize(radar->pause.pause, 200);
    sfText_setPosition(radar->pause.pause, (sfVector2f){950, 110});
    size = sfText_getGlobalBounds(radar->pause.pause);
    sfText_setOrigin(radar->pause.pause,
        (sfVector2f){size.width / 2, size.height / 2});
    sfText_setColor(radar->pause.pause, sfColor_fromRGB(251, 199, 25));
    return SUCCESS;
}

static int text_resume(main_radar_t *radar)
{
    sfFloatRect size;

    radar->pause.font = sfFont_createFromFile(FONT);
    if (!radar->pause.font)
        return FAILURE;
    radar->pause.resume = sfText_create();
    sfText_setFont(radar->pause.resume, radar->pause.font);
    sfText_setString(radar->pause.resume, "RESUME");
    sfText_setOutlineThickness(radar->pause.resume, 7);
    sfText_setCharacterSize(radar->pause.resume, 70);
    sfText_setPosition(radar->pause.resume, (sfVector2f){950, 470});
    size = sfText_getGlobalBounds(radar->pause.resume);
    sfText_setOrigin(radar->pause.resume,
        (sfVector2f){size.width / 2, size.height / 2});
    return SUCCESS;
}

static int text_exit(main_radar_t *radar)
{
    sfFloatRect size;

    radar->pause.font = sfFont_createFromFile(FONT);
    if (!radar->pause.font)
        return FAILURE;
    radar->pause.exit = sfText_create();
    sfText_setFont(radar->pause.exit, radar->pause.font);
    sfText_setString(radar->pause.exit, "EXIT");
    sfText_setOutlineThickness(radar->pause.exit, 7);
    sfText_setCharacterSize(radar->pause.exit, 70);
    sfText_setPosition(radar->pause.exit, (sfVector2f){950, 570});
    size = sfText_getGlobalBounds(radar->pause.exit);
    sfText_setOrigin(radar->pause.exit,
        (sfVector2f){size.width / 2, size.height / 2});
    return SUCCESS;
}

int create_text_pause(main_radar_t *radar)
{
    if (text_pause(radar) == FAILURE)
        return FAILURE;
    if (text_resume(radar) == FAILURE)
        return FAILURE;
    if (text_exit(radar) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
