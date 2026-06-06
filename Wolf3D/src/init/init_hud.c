/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** HUD initialization
*/

#include "../../include/wolf3d.h"

static void init_hud_hp(hud_t *hud)
{
    hud->bar[0] = sfRectangleShape_create();
    hud->bar[1] = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->bar[0], (sfVector2f){1, 1});
    sfRectangleShape_setSize(hud->bar[1], (sfVector2f){1, 1});
    sfRectangleShape_setFillColor(hud->bar[0], (sfColor){0, 0, 0, 130});
    sfRectangleShape_setFillColor(hud->bar[1], (sfColor){30, 200, 30, 255});
    sfRectangleShape_setOutlineThickness(hud->bar[0], -HUD_OUTLINE_T);
    sfRectangleShape_setOutlineColor(hud->bar[0], (sfColor){255, 255, 255, 40});
}

static void init_hud_stamina(hud_t *hud)
{
    hud->bar[2] = sfRectangleShape_create();
    hud->bar[3] = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->bar[2], (sfVector2f){1, 1});
    sfRectangleShape_setSize(hud->bar[3], (sfVector2f){1, 1});
    sfRectangleShape_setFillColor(hud->bar[2], (sfColor){0, 0, 0, 100});
    sfRectangleShape_setFillColor(hud->bar[3], (sfColor){30, 140, 255, 255});
    sfRectangleShape_setOutlineThickness(hud->bar[2], -HUD_OUTLINE_T);
    sfRectangleShape_setOutlineColor(hud->bar[2], (sfColor){255, 255, 255, 40});
}

static void set_text_outline(sfText *t)
{
    sfText_setOutlineColor(t, (sfColor){0, 0, 0, 220});
    sfText_setOutlineThickness(t, HUD_TXT_OUTLINE);
}

static void init_hud_texts(hud_t *hud, sfFont *font)
{
    int i;

    for (i = 0; i < 5; i++) {
        hud->text[i] = sfText_create();
        sfText_setFont(hud->text[i], font);
        sfText_setFillColor(hud->text[i], sfWhite);
        set_text_outline(hud->text[i]);
    }
    sfText_setString(hud->text[0], "HP");
    sfText_setString(hud->text[1], "STA");
    sfText_setString(hud->text[2], "---");
    sfText_setString(hud->text[3], "100");
    sfText_setString(hud->text[4], "Score: 0");
    sfText_setFillColor(hud->text[0], (sfColor){210, 210, 210, 220});
    sfText_setFillColor(hud->text[1], (sfColor){210, 210, 210, 220});
    sfText_setFillColor(hud->text[4], (sfColor){255, 215, 0, 220});
}

static void init_minimap(hud_t *hud)
{
    hud->mm_bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(hud->mm_bg, (sfColor){8, 8, 20, 200});
    sfRectangleShape_setOutlineThickness(hud->mm_bg, -2.0f);
    sfRectangleShape_setOutlineColor(hud->mm_bg, (sfColor){140, 140, 180, 130});
    hud->mm_tile = sfRectangleShape_create();
    hud->mm_player = sfRectangleShape_create();
    sfRectangleShape_setFillColor(hud->mm_player, sfWhite);
    hud->mm_enemy = sfRectangleShape_create();
    sfRectangleShape_setFillColor(hud->mm_enemy, (sfColor){220, 50, 50, 230});
}

void init_hud(hud_t *hud, sfFont *font)
{
    hud->panel = sfRectangleShape_create();
    init_hud_hp(hud);
    init_hud_stamina(hud);
    init_hud_texts(hud, font);
    init_minimap(hud);
}

void free_hud(hud_t *hud)
{
    if (!hud)
        return;
    if (hud->panel)
        sfRectangleShape_destroy(hud->panel);
    for (int i = 0; i < 4; i++) {
        if (hud->bar[i])
            sfRectangleShape_destroy(hud->bar[i]);
    }
    for (int i = 0; i < 5; i++) {
        if (hud->text[i])
            sfText_destroy(hud->text[i]);
    }
    if (hud->mm_bg)
        sfRectangleShape_destroy(hud->mm_bg);
    if (hud->mm_tile)
        sfRectangleShape_destroy(hud->mm_tile);
    if (hud->mm_player)
        sfRectangleShape_destroy(hud->mm_player);
    if (hud->mm_enemy)
        sfRectangleShape_destroy(hud->mm_enemy);
}
