/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The button_pause.c
*/
/**
 * @file button_pause.c
 * @brief The button_pause.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

static void create_pause(button_pause_t *manage_button)
{
    manage_button->pause.texture
    = sfTexture_createFromFile("asset/bg/pausemenu.jpg", NULL);
    if (!manage_button->pause.texture)
        return;
    manage_button->pause.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->pause.sprite,
        manage_button->pause.texture, sfTrue);
    sfSprite_setPosition(manage_button->pause.sprite,
        (sfVector2f){120, 50});
    sfSprite_setScale(manage_button->pause.sprite,
        (sfVector2f){0.6f, 0.6f});
}

static void create_resume(button_pause_t *manage_button)
{
    manage_button->resume.texture
    = sfTexture_createFromFile("asset/button/resume.jpg", NULL);
    if (!manage_button->resume.texture)
        return;
    manage_button->resume.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->resume.sprite,
        manage_button->resume.texture, sfTrue);
    sfSprite_setPosition(manage_button->resume.sprite,
        (sfVector2f){150, 170});
    sfSprite_setScale(manage_button->resume.sprite,
        (sfVector2f){0.3f, 0.3f});
}

static void create_restart(button_pause_t *manage_button)
{
    manage_button->restart.texture
    = sfTexture_createFromFile("asset/button/restart.jpg", NULL);
    if (!manage_button->restart.texture)
        return;
    manage_button->restart.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->restart.sprite,
        manage_button->restart.texture, sfTrue);
    sfSprite_setPosition(manage_button->restart.sprite,
        (sfVector2f){400, 170});
    sfSprite_setScale(manage_button->restart.sprite,
        (sfVector2f){0.3f, 0.3f});
}

static void create_settings(button_pause_t *manage_button)
{
    manage_button->settings.texture
    = sfTexture_createFromFile("asset/button/settings_pause.jpg", NULL);
    if (!manage_button->settings.texture)
        return;
    manage_button->settings.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->settings.sprite,
        manage_button->settings.texture, sfTrue);
    sfSprite_setPosition(manage_button->settings.sprite,
        (sfVector2f){150, 280});
    sfSprite_setScale(manage_button->settings.sprite,
        (sfVector2f){0.3f, 0.3f});
}

static void create_mainmenu(button_pause_t *manage_button)
{
    manage_button->mainmenu.texture
    = sfTexture_createFromFile("asset/button/mainmenu.jpg", NULL);
    if (!manage_button->mainmenu.texture)
        return;
    manage_button->mainmenu.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->mainmenu.sprite,
        manage_button->mainmenu.texture, sfTrue);
    sfSprite_setPosition(manage_button->mainmenu.sprite,
        (sfVector2f){400, 280});
    sfSprite_setScale(manage_button->mainmenu.sprite,
        (sfVector2f){0.3f, 0.3f});
}

static void create_exit(button_pause_t *manage_button)
{
    manage_button->exit.texture
    = sfTexture_createFromFile("asset/button/exit_pause.jpg", NULL);
    if (!manage_button->exit.texture)
        return;
    manage_button->exit.sprite = sfSprite_create();
    sfSprite_setTexture(manage_button->exit.sprite,
        manage_button->exit.texture, sfTrue);
    sfSprite_setPosition(manage_button->exit.sprite,
        (sfVector2f){280, 380});
    sfSprite_setScale(manage_button->exit.sprite,
        (sfVector2f){0.3f, 0.3f});
}

void create_button_pause(button_pause_t *manage_button)
{
    create_pause(manage_button);
    create_resume(manage_button);
    create_restart(manage_button);
    create_settings(manage_button);
    create_mainmenu(manage_button);
    create_exit(manage_button);
}
