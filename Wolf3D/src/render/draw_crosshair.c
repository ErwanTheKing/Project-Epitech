/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** draw weapon crosshair
*/

#include "../../include/wolf3d.h"

static void update_crosshair_view(wolf_t *wolf, window_t *win,
    int dx, int dy)
{
    wolf->player->angle += (float)(dx / 400.f);
    wolf->player->z -= (float)(dy / 2.f);
    wolf->player->z -= joystick_axis(sfJoystickV) * 22.0f;
    if (wolf->player->z >= 600)
        wolf->player->z = 600;
    if (wolf->player->z <= -800)
        wolf->player->z = -800;
    sfMouse_setPositionRenderWindow(
        (sfVector2i){win->width / 2, win->height / 2}, win->window);
}

void draw_crosshair(wolf_t *wolf, window_t *win)
{
    sfSprite *sprite = NULL;
    sfVector2i pos = sfMouse_getPositionRenderWindow(win->window);
    sfVector2i center = {win->width / 2, win->height / 2};

    if (!wolf || !wolf->game || !wolf->game->crosshair.cursor)
        return;
    sprite = wolf->game->crosshair.cursor->sprite;
    if (!sprite)
        return;
    update_crosshair_view(wolf, win, pos.x - center.x, pos.y - center.y);
    if (!wolf->settings || wolf->settings->crosshair)
        sfRenderWindow_drawSprite(win->window, sprite, NULL);
}
