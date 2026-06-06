/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Game constants and macros
*/

#ifndef CONSTANTS_H
    #define CONSTANTS_H
    #include <math.h>
    #define MIN_ATTACK_SPEED 0.15
    #define TEX_GARBAGE_SHEET_W 1600
    #define TEX_GARBAGE_W 400
    #define TEX_GARBAGE_H 500
    #define WALL_MIN_DISTANCE 0.15
    #define STATES 8
    #define TO_DRAW 8
    #define SPRITE 0
    #define TEXT 1
    #define MONSTER 2
    #define GARBAGE 3
    #define RECT 4
    #define LINE 5
    #define HEAL 7
    #define TRIANGLE 6
    #define NUM_RAYS 800
    #define TILE_SIZE 64
    #define MAP_WIDTH 24
    #define MAP_HEIGHT 24
    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080
    #define FOV (M_PI / 3)
    #define TEX_SIZE 64
    #define TEX_PLAYER_W 50
    #define TEX_PLAYER_H 100
    #define CLOUD_SPEED 20
    #define CEILING 0
    #define FLOOR 1
    #define MAX_ENTITY 50
    #define GLOBAL 0
    #define MOVE_CLOCK 1
    #define FOG_MAX_DIST 7.0f
    #define CROSSHAIR_SIZE 8
    #define CROSSHAIR_GAP 4
    #define CROSSHAIR_THICK 2
    #define CARD_SPEED 800.0
    #define CARD_W 0.2f
    #define CARD_H 0.6f
    #define CARD_GAP 0.05f
    #define BSP_MIN_SIZE 5
    #define BSP_MAX_DEPTH 4
    #define BSP_ROOM_MARGIN 1
    #define BSP_ROOM_MIN_SIZE 6
    #define BSP_ROOM_RECT_RATE 30
    #define BSP_ROOM_DIAMOND_RATE 25
    #define BSP_ROOM_CROSS_RATE 20
    #define BSP_ROOM_BLOB_RATE 25
    #define MAP_AREA 576
    #define BFS_QUEUE_SIZE 576
    #define MONSTER_SPEED 2.2f
    #define MONSTER_AGGRO_RANGE 5.0f
    #define MONSTER_WAYPOINT_REACH 0.20f
    #define MONSTER_DT_MAX 0.1f
    #define MONSTER_INTERCEPT 0.6f
    #define MONSTER_INTERCEPT_DRIFT 3.0f
    #define MONSTER_ATTACK_RANGE 0.9f
    #define MONSTER_ATTACK_DMG 10
    #define MONSTER_ATTACK_CD 1.0f
    #define BLOOD_FLASH_TIME 0.45f
    #define BLOOD_FLASH_ALPHA 130
    #define MAX_STAMINA 100
    #define STAMINA_DRAIN 40
    #define STAMINA_REGEN 20
    #define HUD_BAR_W 0.20f
    #define HUD_LEFT 0.016f
    #define HUD_LBL_W 0.045f
    #define HUD_HPH 0.013f
    #define HUD_STAH 0.008f
    #define HUD_HPY 0.918f
    #define HUD_STAY 0.950f
    #define HUD_FONT 0.018f
    #define HUD_VFONT 0.016f
    #define HUD_AFONT 0.055f
    #define HUD_AMMO_X 0.80f
    #define HUD_AMMO_Y 0.872f
    #define HUD_TXT_OUTLINE 2.0f
    #define HUD_OUTLINE_T 1.5f
    #define MINIMAP_SIZE_RATIO 0.13f
    #define MINIMAP_MARGIN 0.015f
    #define SAVE_NAME_MAX 31
    #define SAVE_PATH_MAX 128
    #define CAMERA_SWAY_SPEED 10.0f
    #define CAMERA_SWAY_AMOUNT 70.0f
    #define CAMERA_BOB_AMOUNT 34.0f
    #define CAMERA_SWAY_SMOOTH 0.18f
    #define JOYSTICK_ID 0
    #define JOYSTICK_DEADZONE 18.0f
    #define JOYSTICK_LOOK_SPEED 2.6f
    #define JOY_BTN_EQUIP 0
    #define JOY_BTN_HEAL 1
    #define JOY_BTN_INVENTORY 2
    #define JOY_BTN_RELOAD 3
    #define JOY_BTN_SLOT_PREV 4
    #define JOY_BTN_SLOT_NEXT 5
    #define JOY_BTN_FLASHLIGHT 6
    #define JOY_BTN_SHOOT 7
    #define JOY_BTN_OPTIONS 9
    #define JOY_BTN_LSTICK 11
    #define JOY_TRIGGER_THRESHOLD 0.45f

    #define WHITE (sfColor){180, 180, 180, 255}
    #define BLUE (sfColor){80, 170, 255, 255}
    #define GREEN (sfColor){0, 150, 0, 255}
    #define RED (sfColor){150, 0, 0, 255}
    #define PURPLE (sfColor){128, 0, 128, 255}
#endif
