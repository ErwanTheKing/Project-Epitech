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

static int text_hitbox(main_radar_t *radar)
{
    radar->game.font = sfFont_createFromFile(FONT);
    if (!radar->game.font)
        return FAILURE;
    radar->game.hitbox = sfText_create();
    sfText_setFont(radar->game.hitbox, radar->game.font);
    sfText_setString(radar->game.hitbox, "Shapes (L)");
    sfText_setOutlineThickness(radar->game.hitbox, 4);
    sfText_setCharacterSize(radar->game.hitbox, 50);
    sfText_setPosition(radar->game.hitbox, (sfVector2f){10, 1000});
    return SUCCESS;
}

static int text_hitbox_status(main_radar_t *radar)
{
    radar->game.font = sfFont_createFromFile(FONT);
    if (!radar->game.font)
        return FAILURE;
    radar->game.hit_status = sfText_create();
    sfText_setFont(radar->game.hit_status, radar->game.font);
    sfText_setString(radar->game.hit_status, "ON");
    sfText_setOutlineThickness(radar->game.hit_status, 4);
    sfText_setCharacterSize(radar->game.hit_status, 50);
    sfText_setPosition(radar->game.hit_status, (sfVector2f){300, 1000});
    sfText_setColor(radar->game.hit_status, sfGreen);
    return SUCCESS;
}

static int text_sprite(main_radar_t *radar)
{
    radar->game.font = sfFont_createFromFile(FONT);
    if (!radar->game.font)
        return FAILURE;
    radar->game.sprite = sfText_create();
    sfText_setFont(radar->game.sprite, radar->game.font);
    sfText_setString(radar->game.sprite, "Sprites (S)");
    sfText_setOutlineThickness(radar->game.sprite, 4);
    sfText_setCharacterSize(radar->game.sprite, 50);
    sfText_setPosition(radar->game.sprite, (sfVector2f){10, 900});
    return SUCCESS;
}

static int text_sprite_status(main_radar_t *radar)
{
    radar->game.font = sfFont_createFromFile(FONT);
    if (!radar->game.font)
        return FAILURE;
    radar->game.spr_status = sfText_create();
    sfText_setFont(radar->game.spr_status, radar->game.font);
    sfText_setString(radar->game.spr_status, "ON");
    sfText_setOutlineThickness(radar->game.spr_status, 4);
    sfText_setCharacterSize(radar->game.spr_status, 50);
    sfText_setPosition(radar->game.spr_status, (sfVector2f){300, 900});
    sfText_setColor(radar->game.spr_status, sfGreen);
    return SUCCESS;
}

static int text_time_left(main_radar_t *radar)
{
    radar->game.font = sfFont_createFromFile(FONT);
    if (!radar->game.font)
        return FAILURE;
    radar->game.time_l = sfText_create();
    sfText_setFont(radar->game.time_l, radar->game.font);
    sfText_setString(radar->game.time_l, "00");
    sfText_setOutlineThickness(radar->game.time_l, 20);
    sfText_setCharacterSize(radar->game.time_l, 50);
    sfText_setPosition(radar->game.time_l, (sfVector2f){1690, 10});
    return SUCCESS;
}

static int text_time_right(main_radar_t *radar)
{
    radar->game.font = sfFont_createFromFile(FONT);
    if (!radar->game.font)
        return FAILURE;
    radar->game.time_r = sfText_create();
    sfText_setFont(radar->game.time_r, radar->game.font);
    sfText_setString(radar->game.time_r, "00");
    sfText_setOutlineThickness(radar->game.time_r, 20);
    sfText_setCharacterSize(radar->game.time_r, 50);
    sfText_setPosition(radar->game.time_r, (sfVector2f){1830, 10});
    return SUCCESS;
}

static int text_separator(main_radar_t *radar)
{
    radar->game.font = sfFont_createFromFile(FONT);
    if (!radar->game.font)
        return FAILURE;
    radar->game.separator = sfText_create();
    sfText_setFont(radar->game.separator, radar->game.font);
    sfText_setString(radar->game.separator, ":");
    sfText_setOutlineThickness(radar->game.separator, 5);
    sfText_setCharacterSize(radar->game.separator, 50);
    sfText_setPosition(radar->game.separator, (sfVector2f){1770, 10});
    return SUCCESS;
}

static int text_fps(main_radar_t *radar)
{
    radar->game.font = sfFont_createFromFile(FONT);
    if (!radar->game.font)
        return FAILURE;
    radar->game.fps = sfText_create();
    sfText_setFont(radar->game.fps, radar->game.font);
    sfText_setString(radar->game.fps, "FPS");
    sfText_setOutlineThickness(radar->game.fps, 5);
    sfText_setCharacterSize(radar->game.fps, 50);
    sfText_setPosition(radar->game.fps, (sfVector2f){10, 800});
    return SUCCESS;
}

static int text_fps_status(main_radar_t *radar)
{
    radar->game.font = sfFont_createFromFile(FONT);
    if (!radar->game.font)
        return FAILURE;
    radar->game.fps_status = sfText_create();
    sfText_setFont(radar->game.fps_status, radar->game.font);
    sfText_setString(radar->game.fps_status, "0");
    sfText_setOutlineThickness(radar->game.fps_status, 5);
    sfText_setCharacterSize(radar->game.fps_status, 50);
    sfText_setPosition(radar->game.fps_status, (sfVector2f){300, 800});
    return SUCCESS;
}

int create_text_game(main_radar_t *radar)
{
    if (text_hitbox(radar) == FAILURE || text_hitbox_status(radar) == FAILURE)
        return FAILURE;
    if (text_sprite(radar) == FAILURE || text_sprite_status(radar) == FAILURE)
        return FAILURE;
    if (text_time_left(radar) == FAILURE || text_time_right(radar) == FAILURE)
        return FAILURE;
    if (text_separator(radar) == FAILURE)
        return FAILURE;
    if (text_fps(radar) == FAILURE || text_fps_status(radar) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
