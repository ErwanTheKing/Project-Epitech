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

static int text_exit(main_radar_t *radar)
{
    sfFloatRect size;

    radar->main.font = sfFont_createFromFile(FONT);
    if (!radar->main.font)
        return FAILURE;
    radar->main.exit = sfText_create();
    sfText_setFont(radar->main.exit, radar->main.font);
    sfText_setString(radar->main.exit, "EXIT");
    sfText_setOutlineThickness(radar->main.exit, 4);
    sfText_setCharacterSize(radar->main.exit, 50);
    sfText_setPosition(radar->main.exit, (sfVector2f){240, 570});
    size = sfText_getGlobalBounds(radar->main.exit);
    sfText_setOrigin(radar->main.exit,
        (sfVector2f){size.width / 2, size.height / 2});
    return SUCCESS;
}

static int text_play(main_radar_t *radar)
{
    sfFloatRect size;

    if (!radar->main.font)
        return FAILURE;
    radar->main.play = sfText_create();
    sfText_setFont(radar->main.play, radar->main.font);
    sfText_setString(radar->main.play, "PLAY");
    sfText_setOutlineThickness(radar->main.play, 4);
    sfText_setCharacterSize(radar->main.play, 50);
    sfText_setPosition(radar->main.play, (sfVector2f){240, 470});
    size = sfText_getGlobalBounds(radar->main.play);
    sfText_setOrigin(radar->main.play,
        (sfVector2f){size.width / 2, size.height / 2});
    return SUCCESS;
}

int create_text_main(main_radar_t *radar)
{
    if (text_exit(radar) == FAILURE)
        return FAILURE;
    if (text_play(radar) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
