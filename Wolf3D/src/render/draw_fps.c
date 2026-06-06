/*
** EPITECH PROJECT, 2026
** render
** File description:
** draw fps
*/

#include "../../include/wolf3d.h"

static void init_fps_text(wolf_t *wolf)
{
    if (wolf->fps_text)
        return;
    wolf->fps_text = sfText_create();
    if (!wolf->fps_text)
        return;
    sfText_setFont(wolf->fps_text, wolf->data->font);
    sfText_setCharacterSize(wolf->fps_text, 20);
    sfText_setFillColor(wolf->fps_text, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(wolf->fps_text, (sfVector2f){20.0f, 20.0f});
}

static void update_fps_counter(wolf_t *wolf)
{
    sfTime elapsed = sfClock_getElapsedTime(wolf->fps_clock);

    wolf->fps_frame_count++;
    if (sfTime_asSeconds(elapsed) < 1.0f)
        return;
    wolf->fps_current = wolf->fps_frame_count;
    wolf->fps_frame_count = 0;
    sfClock_restart(wolf->fps_clock);
}

void draw_fps(wolf_t *wolf)
{
    char buffer[32];

    if (!wolf || !wolf->window_data || !wolf->data || !wolf->data->font)
        return;
    if (!wolf->fps_clock)
        wolf->fps_clock = sfClock_create();
    init_fps_text(wolf);
    if (!wolf->fps_clock || !wolf->fps_text)
        return;
    update_fps_counter(wolf);
    snprintf(buffer, sizeof(buffer), "FPS: %d", wolf->fps_current);
    sfText_setString(wolf->fps_text, buffer);
    sfRenderWindow_drawText(wolf->window_data->window, wolf->fps_text, NULL);
}
