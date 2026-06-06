/*
** EPITECH PROJECT, 2026
** weapon
** File description:
** weapon draw and reload
*/

#include "../../../include/wolf3d.h"
#include <math.h>

static int apply_frame(weapon_t *weapon,
    float elapsed, float frame, int rect_left)
{
    if (elapsed < frame) {
        weapon->rect.left = rect_left;
        sfSprite_setTextureRect(weapon->entity->sprite, weapon->rect);
        return 1;
    }
    return 0;
}

int animate_shot(weapon_t *weapon, sfVector2f *rect_1,
    sfVector2f *rect_2, sfVector2f *rect_3)
{
    float elapsed = sfTime_asSeconds(sfClock_getElapsedTime(weapon->cd));

    if (apply_frame(weapon, elapsed, rect_1->x, rect_1->y) ||
        apply_frame(weapon, elapsed, rect_2->x, rect_2->y) ||
        apply_frame(weapon, elapsed, rect_3->x, rect_3->y))
        return 0;
    weapon->rect.left = 0;
    sfSprite_setTextureRect(weapon->entity->sprite, weapon->rect);
    return 1;
}

static void shot_weapon(weapon_t *w)
{
    float elapsed = sfTime_asSeconds(sfClock_getElapsedTime(w->cd));
    float end_frame = w->type == GUN ? 0.3 : 0.6;

    if ((w->type == SHOTGUN || w->type == VACUUM) && elapsed >= end_frame) {
        w->reloading = 1;
        return;
    }
    animate_shot(w, &(sfVector2f){w->type == GUN ? 0.1 : 0.2, 400},
        &(sfVector2f){w->type == GUN ? 0.2 : 0.4, 800},
        &(sfVector2f){w->type == GUN ? 0.3 : 0.6, 1200});
}

static sfBool is_weapon_walk(wolf_t *wolf)
{
    return (isactiondown(wolf->settings, CTRL_LEFT)
        ^ isactiondown(wolf->settings, CTRL_RIGHT)
        || isactiondown(wolf->settings, CTRL_FORWARD)
        ^ isactiondown(wolf->settings, CTRL_BACKWARD)
        || joystick_axis(sfJoystickX) != 0.0f
        || joystick_axis(sfJoystickY) != 0.0f);
}

void draw_weapon(wolf_t *wolf, window_t *win, weapon_t *w)
{
    if (!w)
        return;
    if (w->reloading)
        reload_weapon(wolf->window_data, w);
    else
        shot_weapon(w);
    if (!w->reloading && is_weapon_walk(wolf))
        animate_weapon_walk(wolf, wolf->window_data, w);
    else if (!w->reloading)
        sfSprite_setPosition(w->entity->sprite,
            (sfVector2f){win->width / 2, win->height});
    sfRenderWindow_drawSprite(win->window, w->entity->sprite, NULL);
}
