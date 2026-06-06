/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** HUD rendering (HP bar, stamina bar, ammo count)
*/

#include "../../include/wolf3d.h"
#include <stdio.h>

static sfColor get_hp_color(float ratio)
{
    float t;

    if (ratio > 0.5f) {
        t = (ratio - 0.5f) * 2.0f;
        return (sfColor){(sfUint8)(30 + (1.0f - t) * 190), 200, 30, 255};
    }
    t = ratio * 2.0f;
    return (sfColor){220, (sfUint8)(30 + t * 170), 30, 255};
}

static void set_bars(hud_t *hud, window_t *win)
{
    float w = (float)win->width;
    float h = (float)win->height;
    float bar_w = w * HUD_BAR_W;
    float bar_x = w * HUD_LEFT + w * HUD_LBL_W;
    float hp_y = h * HUD_HPY;
    float sta_y = h * HUD_STAY;

    sfRectangleShape_setSize(hud->bar[0], (sfVector2f){bar_w, h * HUD_HPH});
    sfRectangleShape_setSize(hud->bar[2], (sfVector2f){bar_w, h * HUD_STAH});
    sfRectangleShape_setPosition(hud->bar[0], (sfVector2f){bar_x, hp_y});
    sfRectangleShape_setPosition(hud->bar[1], (sfVector2f){bar_x, hp_y});
    sfRectangleShape_setPosition(hud->bar[2], (sfVector2f){bar_x, sta_y});
    sfRectangleShape_setPosition(hud->bar[3], (sfVector2f){bar_x, sta_y});
}

static void set_text_sizes(hud_t *hud, float h)
{
    sfText_setCharacterSize(hud->text[0], (unsigned int)(h * HUD_FONT));
    sfText_setCharacterSize(hud->text[1], (unsigned int)(h * HUD_FONT));
    sfText_setCharacterSize(hud->text[2], (unsigned int)(h * HUD_AFONT));
    sfText_setCharacterSize(hud->text[3], (unsigned int)(h * HUD_VFONT));
}

static void set_text_pos(hud_t *hud, window_t *win)
{
    float w = (float)win->width;
    float h = (float)win->height;
    float lx = w * HUD_LEFT;
    float bx = lx + w * HUD_LBL_W;
    float vx = bx + w * HUD_BAR_W + lx * 0.6f;
    float hy = h * HUD_HPY;
    float sy = h * HUD_STAY;
    unsigned int lbl = (unsigned int)(h * HUD_FONT);
    unsigned int val = (unsigned int)(h * HUD_VFONT);
    float hp_off = (h * HUD_HPH - (float)lbl) * 0.5f;
    float sta_off = (h * HUD_STAH - (float)lbl) * 0.5f;
    float val_off = (h * HUD_HPH - (float)val) * 0.5f;

    sfText_setPosition(hud->text[0], (sfVector2f){lx, hy + hp_off});
    sfText_setPosition(hud->text[1], (sfVector2f){lx, sy + sta_off});
    sfText_setPosition(hud->text[2],
        (sfVector2f){w * HUD_AMMO_X, h * HUD_AMMO_Y});
    sfText_setPosition(hud->text[3], (sfVector2f){vx, hy + val_off});
    sfText_setPosition(hud->text[4], (sfVector2f){10, 10});
}

static void clamp_ratios(float *hp, float *sta)
{
    if (*hp < 0.0f)
        *hp = 0.0f;
    if (*hp > 1.0f)
        *hp = 1.0f;
    if (*sta < 0.0f)
        *sta = 0.0f;
}

static void update_bars(hud_t *hud, player_t *player, window_t *win)
{
    float w = (float)win->width;
    float h = (float)win->height;
    float hp_ratio = (float)player->hp / player->max_hp;
    float sta_ratio = (float)player->stamina / MAX_STAMINA;
    sfColor hp_color;
    char buf[16];

    clamp_ratios(&hp_ratio, &sta_ratio);
    hp_color = get_hp_color(hp_ratio);
    sfRectangleShape_setSize(hud->bar[1],
        (sfVector2f){w * HUD_BAR_W * hp_ratio, h * HUD_HPH});
    sfRectangleShape_setSize(hud->bar[3],
        (sfVector2f){w * HUD_BAR_W * sta_ratio, h * HUD_STAH});
    sfRectangleShape_setFillColor(hud->bar[1], hp_color);
    sfText_setFillColor(hud->text[3], hp_color);
    snprintf(buf, sizeof(buf), "%d", player->hp);
    sfText_setString(hud->text[3], buf);
}

static void update_texts(hud_t *hud, player_t *player, wolf_t *wolf)
{
    char buf[32];

    if (!player->weapon) {
        sfText_setString(hud->text[2], "---");
    } else {
        snprintf(buf, sizeof(buf), "%d / %d",
            player->weapon->current_ammo, player->weapon->max_ammo);
        sfText_setString(hud->text[2], buf);
    }
    snprintf(buf, sizeof(buf), "Score: %d", wolf->score);
    sfText_setString(hud->text[4], buf);
}

static void draw_blood_overlay(hud_t *hud, window_t *win, player_t *player)
{
    float elapsed;
    float ratio;
    sfColor color = {130, 0, 0, BLOOD_FLASH_ALPHA};

    if (!player->took_damage || !player->damage_clock)
        return;
    elapsed = sfTime_asSeconds(sfClock_getElapsedTime(player->damage_clock));
    if (elapsed >= BLOOD_FLASH_TIME) {
        player->took_damage = sfFalse;
        return;
    }
    ratio = 1.0f - elapsed / BLOOD_FLASH_TIME;
    color.a = (sfUint8)(BLOOD_FLASH_ALPHA * ratio);
    sfRectangleShape_setSize(hud->panel,
        (sfVector2f){(float)win->width, (float)win->height});
    sfRectangleShape_setPosition(hud->panel, (sfVector2f){0.0f, 0.0f});
    sfRectangleShape_setFillColor(hud->panel, color);
    sfRenderWindow_drawRectangleShape(win->window, hud->panel, NULL);
}

static void draw_hud_content(hud_t *hud, window_t *win)
{
    sfRenderWindow_drawRectangleShape(win->window, hud->bar[0], NULL);
    sfRenderWindow_drawRectangleShape(win->window, hud->bar[1], NULL);
    sfRenderWindow_drawRectangleShape(win->window, hud->bar[2], NULL);
    sfRenderWindow_drawRectangleShape(win->window, hud->bar[3], NULL);
    sfRenderWindow_drawText(win->window, hud->text[0], NULL);
    sfRenderWindow_drawText(win->window, hud->text[1], NULL);
    sfRenderWindow_drawText(win->window, hud->text[2], NULL);
    sfRenderWindow_drawText(win->window, hud->text[3], NULL);
    sfRenderWindow_drawText(win->window, hud->text[4], NULL);
}

void draw_hud(wolf_t *wolf, window_t *win, player_t *player)
{
    hud_t *hud = &wolf->game->hud;

    set_bars(hud, win);
    set_text_sizes(hud, (float)win->height);
    set_text_pos(hud, win);
    update_bars(hud, player, win);
    update_texts(hud, player, wolf);
    draw_blood_overlay(hud, win, player);
    if (!wolf->settings || wolf->settings->show_hud) {
        draw_hud_content(hud, win);
    }
    if (!wolf->settings || wolf->settings->show_minimap)
        draw_minimap(wolf, player);
}
