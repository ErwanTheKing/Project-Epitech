/*
** EPITECH PROJECT, 2026
** ~/EpitechProjects/Wolf3d/src/init
** File description:
** init_settings
*/

#include "wolf3d.h"

static void init_graphics_settings(settings_game_t *settings)
{
    settings->resolution = (sfVideoMode){1920, 1080, 32};
    settings->fullscreen = sfFalse;
    settings->vsync = sfTrue;
    settings->fov = 66;
    settings->brightness = 50;
    settings->max_fps = 144;
}

static void init_audio_settings(settings_game_t *settings)
{
    settings->master_volume = 80;
    settings->music_volume = 60;
    settings->sfx_volume = 90;
    settings->ambient_volume = 70;
}

static void init_slot_settings(settings_game_t *settings)
{
    settings->key_bindings[CTRL_SLOT_1] = sfKeyNum1;
    settings->key_bindings[CTRL_SLOT_2] = sfKeyNum2;
    settings->key_bindings[CTRL_SLOT_3] = sfKeyNum3;
    settings->key_bindings[CTRL_SLOT_4] = sfKeyNum4;
    settings->key_bindings[CTRL_SLOT_5] = sfKeyNum5;
    settings->key_bindings[CTRL_SLOT_6] = sfKeyNum6;
    settings->key_bindings[CTRL_SLOT_7] = sfKeyNum7;
    settings->key_bindings[CTRL_SLOT_8] = sfKeyNum8;
}

static void init_control_settings(settings_game_t *settings)
{
    settings->key_bindings[CTRL_FORWARD] = sfKeyZ;
    settings->key_bindings[CTRL_BACKWARD] = sfKeyS;
    settings->key_bindings[CTRL_LEFT] = sfKeyQ;
    settings->key_bindings[CTRL_RIGHT] = sfKeyD;
    settings->key_bindings[CTRL_TURN_LEFT] = sfKeyLeft;
    settings->key_bindings[CTRL_TURN_RIGHT] = sfKeyRight;
    settings->key_bindings[CTRL_SPRINT] = sfKeyLShift;
    settings->key_bindings[CTRL_INVENTORY] = sfKeyE;
    settings->key_bindings[CTRL_EQUIP] = sfKeySpace;
    settings->key_bindings[CTRL_RELOAD] = sfKeyR;
    settings->key_bindings[CTRL_FLASHLIGHT] = sfKeyF;
    settings->key_bindings[CTRL_HEAL] = sfKeyA;
    settings->key_bindings[CTRL_PAUSE] = sfKeyEscape;
    init_slot_settings(settings);
}

static void init_controller_settings(settings_game_t *settings)
{
    for (int i = 0; i < CTRL_COUNT; i++)
        settings->joystick_bindings[i] = -1;
    settings->joystick_bindings[CTRL_SPRINT] = JOY_BTN_LSTICK;
    settings->joystick_bindings[CTRL_INVENTORY] = JOY_BTN_INVENTORY;
    settings->joystick_bindings[CTRL_EQUIP] = JOY_BTN_EQUIP;
    settings->joystick_bindings[CTRL_RELOAD] = JOY_BTN_RELOAD;
    settings->joystick_bindings[CTRL_FLASHLIGHT] = JOY_BTN_FLASHLIGHT;
    settings->joystick_bindings[CTRL_HEAL] = JOY_BTN_HEAL;
    settings->joystick_bindings[CTRL_PAUSE] = JOY_BTN_OPTIONS;
    settings->joystick_bindings[CTRL_SLOT_1] = JOY_BTN_SLOT_PREV;
    settings->joystick_bindings[CTRL_SLOT_2] = JOY_BTN_SLOT_NEXT;
}

static void init_gameplay_settings(settings_game_t *settings)
{
    settings->mouse_sensitivity = 50;
    settings->invert_mouse = sfFalse;
    settings->show_hud = sfTrue;
    settings->show_fps = sfFalse;
    settings->show_minimap = sfTrue;
    settings->crosshair = sfTrue;
}

settings_game_t *init_settings_params(void)
{
    settings_game_t *settings = malloc(sizeof(settings_game_t));

    if (!settings)
        return NULL;
    init_graphics_settings(settings);
    init_audio_settings(settings);
    init_gameplay_settings(settings);
    init_control_settings(settings);
    init_controller_settings(settings);
    return settings;
}
