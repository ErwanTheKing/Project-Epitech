/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The button_settings2.c
*/
/**
 * @file button_settings2.c
 * @brief The button_settings2.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

static void create_800x600(button_setting_t *manage_button)
{
    manage_button->res800.texture
    = sfTexture_createFromFile("asset/button/800x600.jpg", NULL);
    if (!manage_button->res800.texture)
        return;
    manage_button->res800.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->res800.sprite,
        manage_button->res800.texture, sfTrue);
    sfSprite_setPosition(manage_button->res800.sprite,
        (sfVector2f){400, 240});
    sfSprite_setScale(manage_button->res800.sprite,
        (sfVector2f){0.5f, 0.5f});
}

static void create_enable(button_setting_t *manage_button)
{
    manage_button->enable.texture
    = sfTexture_createFromFile("asset/button/enable.jpg", NULL);
    if (!manage_button->enable.texture)
        return;
    manage_button->enable.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->enable.sprite,
        manage_button->enable.texture, sfTrue);
    sfSprite_setPosition(manage_button->enable.sprite,
        (sfVector2f){430, 300});
    sfSprite_setScale(manage_button->enable.sprite,
        (sfVector2f){0.5f, 0.5f});
}

static void create_disable(button_setting_t *manage_button)
{
    manage_button->disable.texture
    = sfTexture_createFromFile("asset/button/disable.jpg", NULL);
    if (!manage_button->disable.texture)
        return;
    manage_button->disable.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->disable.sprite,
        manage_button->disable.texture, sfTrue);
    sfSprite_setPosition(manage_button->disable.sprite,
        (sfVector2f){430, 300});
    sfSprite_setScale(manage_button->disable.sprite,
        (sfVector2f){0.5f, 0.5f});
}

static void create_30(button_setting_t *manage_button)
{
    manage_button->fps30.texture
    = sfTexture_createFromFile("asset/button/30.jpg", NULL);
    if (!manage_button->fps30.texture)
        return;
    manage_button->fps30.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->fps30.sprite,
        manage_button->fps30.texture, sfTrue);
    sfSprite_setPosition(manage_button->fps30.sprite,
        (sfVector2f){450, 355});
    sfSprite_setScale(manage_button->fps30.sprite,
        (sfVector2f){0.5f, 0.5f});
}

static void create_60(button_setting_t *manage_button)
{
    manage_button->fps60.texture
    = sfTexture_createFromFile("asset/button/60.jpg", NULL);
    if (!manage_button->fps60.texture)
        return;
    manage_button->fps60.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->fps60.sprite,
        manage_button->fps60.texture, sfTrue);
    sfSprite_setPosition(manage_button->fps60.sprite,
        (sfVector2f){455, 355});
    sfSprite_setScale(manage_button->fps60.sprite,
        (sfVector2f){0.5f, 0.5f});
}

void create_button_settings2(button_setting_t *manage_button)
{
    create_800x600(manage_button);
    create_enable(manage_button);
    create_disable(manage_button);
    create_30(manage_button);
    create_60(manage_button);
}
