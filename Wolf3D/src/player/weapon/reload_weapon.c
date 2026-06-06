/*
** EPITECH PROJECT, 2026
** weapon
** File description:
** weapon reload
*/

#include "../../../include/wolf3d.h"
#include <math.h>

static void reload_gun_end(sfVector2f *pos, window_t *win, weapon_t *weapon)
{
    sfSprite_setPosition(weapon->entity->sprite,
        (sfVector2f){pos->x, win->height});
    weapon->reloading = 0;
    weapon->current_ammo = weapon->max_ammo;
}

static void reload_gun(sfVector2f *pos, window_t *win,
    weapon_t *weapon, float elapsed)
{
    float reload_time = sqrtf(weapon->attack_speed) * 2.5f;
    float half = reload_time / 2.0f;

    if (elapsed < half) {
        sfSprite_setPosition(weapon->entity->sprite,
            (sfVector2f){pos->x, win->height + (win->height / 2) *
                (elapsed / half)});
        return;
    }
    if (elapsed < reload_time) {
        sfSprite_setPosition(weapon->entity->sprite,
            (sfVector2f){pos->x, win->height + (win->height / 2) * (1.f -
                    (elapsed - half) / half)});
        return;
    }
    reload_gun_end(pos, win, weapon);
}

static int get_reload_frame(float t)
{
    if (t < 0.5f)
        return 1600;
    if (t < 0.75f)
        return 2000;
    return 2400;
}

static void reload_shotgun(weapon_t *weapon, float elapsed)
{
    float reload_time = weapon->attack_speed * 2.0f;
    float t = elapsed / reload_time;

    if (t >= 0.9f) {
        weapon->rect.left = 0;
        sfSprite_setTextureRect(weapon->entity->sprite, weapon->rect);
        weapon->reloading = 0;
        weapon->current_ammo = weapon->max_ammo;
        return;
    }
    if (t >= 0.25f) {
        weapon->rect.left = get_reload_frame(t);
        sfSprite_setTextureRect(weapon->entity->sprite, weapon->rect);
    }
}

void reload_weapon(window_t *win, weapon_t *weapon)
{
    float elapsed = sfTime_asSeconds(sfClock_getElapsedTime(weapon->cd));
    sfVector2f pos = sfSprite_getPosition(weapon->entity->sprite);

    switch (weapon->type) {
        case GUN:
            reload_gun(&pos, win, weapon, elapsed);
            break;
        case SHOTGUN:
        case VACUUM:
            reload_shotgun(weapon, elapsed);
            break;
        default:
            break;
    }
}
