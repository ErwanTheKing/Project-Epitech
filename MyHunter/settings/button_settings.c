/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The button_settings.c
*/
/**
 * @file button_settings.c
 * @brief The button_settings.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../include/includes.h"

void create_background(button_setting_t *manage_button)
{
    manage_button->background.texture
    = sfTexture_createFromFile("asset/bg/mainmenu.jpg", NULL);
    if (!manage_button->background.texture)
        return;
    manage_button->background.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->background.sprite,
        manage_button->background.texture, sfTrue);
    sfSprite_setPosition(manage_button->background.sprite,
        (sfVector2f){0, 0});
    sfSprite_setScale(manage_button->background.sprite,
        (sfVector2f){0.6f, 0.6f});
}

static void create_settings(button_setting_t *manage_button)
{
    manage_button->settings.texture
    = sfTexture_createFromFile("asset/bg/settingsmenu.jpg", NULL);
    if (!manage_button->settings.texture)
        return;
    manage_button->settings.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->settings.sprite,
        manage_button->settings.texture, sfTrue);
    sfSprite_setPosition(manage_button->settings.sprite,
        (sfVector2f){-55, 0});
    sfSprite_setScale(manage_button->settings.sprite,
        (sfVector2f){0.6f, 0.6f});
}

static void create_back(button_setting_t *manage_button)
{
    manage_button->back.texture
    = sfTexture_createFromFile("asset/button/back.jpg", NULL);
    if (!manage_button->back.texture)
        return;
    manage_button->back.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->back.sprite,
        manage_button->back.texture, sfTrue);
    sfSprite_setPosition(manage_button->back.sprite,
        (sfVector2f){330, 420});
    sfSprite_setScale(manage_button->back.sprite,
        (sfVector2f){0.2f, 0.2f});
}

static void create_more(button_setting_t *manage_button)
{
    manage_button->more.texture
    = sfTexture_createFromFile("asset/button/more.jpg", NULL);
    if (!manage_button->more.texture)
        return;
    manage_button->more.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->more.sprite,
        manage_button->more.texture, sfTrue);
    sfSprite_setPosition(manage_button->more.sprite,
        (sfVector2f){500, 185});
    sfSprite_setScale(manage_button->more.sprite,
        (sfVector2f){0.05f, 0.05f});
}

static void create_less(button_setting_t *manage_button)
{
    manage_button->less.texture
    = sfTexture_createFromFile("asset/button/less.jpg", NULL);
    if (!manage_button->less.texture)
        return;
    manage_button->less.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->less.sprite,
        manage_button->less.texture, sfTrue);
    sfSprite_setPosition(manage_button->less.sprite,
        (sfVector2f){440, 185});
    sfSprite_setScale(manage_button->less.sprite,
        (sfVector2f){0.05f, 0.05f});
}

static void create_1920x1080(button_setting_t *manage_button)
{
    manage_button->res1920.texture
    = sfTexture_createFromFile("asset/button/1920x1080.jpg", NULL);
    if (!manage_button->res1920.texture)
        return;
    manage_button->res1920.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->res1920.sprite,
        manage_button->res1920.texture, sfTrue);
    sfSprite_setPosition(manage_button->res1920.sprite,
        (sfVector2f){400, 240});
    sfSprite_setScale(manage_button->res1920.sprite,
        (sfVector2f){0.5f, 0.5f});
}

void create_120(button_setting_t *manage_button)
{
    manage_button->fps120.texture
    = sfTexture_createFromFile("asset/button/120.jpg", NULL);
    if (!manage_button->fps120.texture)
        return;
    manage_button->fps120.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->fps120.sprite,
        manage_button->fps120.texture, sfTrue);
    sfSprite_setPosition(manage_button->fps120.sprite,
        (sfVector2f){430, 355});
    sfSprite_setScale(manage_button->fps120.sprite,
        (sfVector2f){0.5f, 0.5f});
}

void create_unlimited(button_setting_t *manage_button)
{
    manage_button->unlimited.texture
    = sfTexture_createFromFile("asset/button/unlimited.jpg", NULL);
    if (!manage_button->unlimited.texture)
        return;
    manage_button->unlimited.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->unlimited.sprite,
        manage_button->unlimited.texture, sfTrue);
    sfSprite_setPosition(manage_button->unlimited.sprite,
        (sfVector2f){415, 355});
    sfSprite_setScale(manage_button->unlimited.sprite,
        (sfVector2f){0.5f, 0.5f});
}

void create_button_settings(button_setting_t *manage_button)
{
    create_background(manage_button);
    create_settings(manage_button);
    create_back(manage_button);
    create_more(manage_button);
    create_less(manage_button);
    create_1920x1080(manage_button);
    create_button_settings2(manage_button);
    create_120(manage_button);
    create_unlimited(manage_button);
}
