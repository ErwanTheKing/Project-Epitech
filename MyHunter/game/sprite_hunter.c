/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The sprite_hunter.c
*/
/**
 * @file sprite_hunter.c
 * @brief The sprite_hunter.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

static void cr_background(manage_sprite_t *manage_sprite)
{
    char *back[4] = {"asset/bg/BG_01.jpg", "asset/bg/BG_02.jpg",
        "asset/bg/BG_03.jpg", "asset/bg/BG_04.jpg"};
    int BG = 0;

    srand(time(NULL));
    BG = rand() % 4;
    manage_sprite->background.texture = sfTexture_createFromFile(back[BG],
        NULL);
    if (!manage_sprite->background.texture)
        return;
    manage_sprite->background.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->background.sprite,
        manage_sprite->background.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->background.sprite,
        (sfVector2f){0, 0});
    sfSprite_setScale(manage_sprite->background.sprite,
        (sfVector2f){0.45f, 0.56f});
}

static void create_visor(manage_sprite_t *manage_sprite, sfRenderWindow *window)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);

    manage_sprite->visor.texture
    = sfTexture_createFromFile("asset/obj/visor.png", NULL);
    if (!manage_sprite->visor.texture)
        return;
    manage_sprite->visor.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->visor.sprite,
        manage_sprite->visor.texture, sfTrue);
    sfSprite_setOrigin(manage_sprite->visor.sprite, (sfVector2f){460, 510});
    sfSprite_setPosition(manage_sprite->visor.sprite,
        mouse);
    sfSprite_setScale(manage_sprite->visor.sprite,
        (sfVector2f){0.08f, 0.08f});
}

static void create_heart1(manage_sprite_t *manage_sprite)
{
    manage_sprite->heart1.texture
    = sfTexture_createFromFile("asset/obj/heart.png", NULL);
    if (!manage_sprite->heart1.texture)
        return;
    manage_sprite->heart1.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->heart1.sprite,
        manage_sprite->heart1.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->heart1.sprite,
        (sfVector2f){720, 510});
    sfSprite_setScale(manage_sprite->heart1.sprite,
        (sfVector2f){0.05f, 0.05f});
}

static void create_heart2(manage_sprite_t *manage_sprite)
{
    manage_sprite->heart2.texture
    = sfTexture_createFromFile("asset/obj/heart.png", NULL);
    if (!manage_sprite->heart2.texture)
        return;
    manage_sprite->heart2.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->heart2.sprite,
        manage_sprite->heart2.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->heart2.sprite,
        (sfVector2f){670, 510});
    sfSprite_setScale(manage_sprite->heart2.sprite,
        (sfVector2f){0.05f, 0.05f});
}

static void create_heart3(manage_sprite_t *manage_sprite)
{
    manage_sprite->heart3.texture
    = sfTexture_createFromFile("asset/obj/heart.png", NULL);
    if (!manage_sprite->heart3.texture)
        return;
    manage_sprite->heart3.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->heart3.sprite,
        manage_sprite->heart3.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->heart3.sprite,
        (sfVector2f){620, 510});
    sfSprite_setScale(manage_sprite->heart3.sprite,
        (sfVector2f){0.05f, 0.05f});
}

static void create_heart4(manage_sprite_t *manage_sprite)
{
    manage_sprite->heart4.texture
    = sfTexture_createFromFile("asset/obj/heart.png", NULL);
    if (!manage_sprite->heart4.texture)
        return;
    manage_sprite->heart4.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->heart4.sprite,
        manage_sprite->heart4.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->heart4.sprite,
        (sfVector2f){570, 510});
    sfSprite_setScale(manage_sprite->heart4.sprite,
        (sfVector2f){0.05f, 0.05f});
}

static void create_heart5(manage_sprite_t *manage_sprite)
{
    manage_sprite->heart5.texture
    = sfTexture_createFromFile("asset/obj/heart.png", NULL);
    if (!manage_sprite->heart5.texture)
        return;
    manage_sprite->heart5.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->heart5.sprite,
        manage_sprite->heart5.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->heart5.sprite,
        (sfVector2f){520, 510});
    sfSprite_setScale(manage_sprite->heart5.sprite,
        (sfVector2f){0.05f, 0.05f});
}

void create_bg_score(manage_sprite_t *manage_sprite)
{
    manage_sprite->bg_score.texture
    = sfTexture_createFromFile("asset/button/score.jpg", NULL);
    if (!manage_sprite->bg_score.texture)
        return;
    manage_sprite->bg_score.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->bg_score.sprite,
        manage_sprite->bg_score.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->bg_score.sprite,
        (sfVector2f){50, 510});
    sfSprite_setScale(manage_sprite->bg_score.sprite,
        (sfVector2f){0.2f, 0.2f});
}

void create_bg_heart(manage_sprite_t *manage_sprite)
{
    manage_sprite->bg_heart.texture
    = sfTexture_createFromFile("asset/button/score.jpg", NULL);
    if (!manage_sprite->bg_heart.texture)
        return;
    manage_sprite->bg_heart.sprite = sfSprite_create();
    sfSprite_setTexture(manage_sprite->bg_heart.sprite,
        manage_sprite->bg_heart.texture, sfTrue);
    sfSprite_setPosition(manage_sprite->bg_heart.sprite,
        (sfVector2f){510, 510});
    sfSprite_setScale(manage_sprite->bg_heart.sprite,
        (sfVector2f){0.35f, 0.2f});
}

void create_sprite_game(manage_sprite_t *manage_sprite,
    sfRenderWindow *window)
{
    cr_background(manage_sprite);
    create_visor(manage_sprite, window);
    create_bg_score(manage_sprite);
    create_bg_heart(manage_sprite);
    create_heart1(manage_sprite);
    create_heart2(manage_sprite);
    create_heart3(manage_sprite);
    create_heart4(manage_sprite);
    create_heart5(manage_sprite);
}
