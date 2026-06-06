/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The frame.c
*/
/**
 * @file frame.c
 * @brief The frame.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"

static void unlimited(world_t *world)
{
    world->settings.vsync_int = 0;
    sfRenderWindow_setFramerateLimit(world->window, 0);
    sfText_setString(world->settings.frame_t, "Framerate : Unlimited");
    world->st_frame = FRAME0;
}

static void frame30(world_t *world)
{
    world->settings.vsync_int = 30;
    sfRenderWindow_setFramerateLimit(world->window, 30);
    sfText_setString(world->settings.frame_t, "Framerate : 30 FPS");
    world->st_frame = FRAME30;
}

static void frame60(world_t *world)
{
    world->settings.vsync_int = 60;
    sfRenderWindow_setFramerateLimit(world->window, 60);
    sfText_setString(world->settings.frame_t, "Framerate : 60 FPS");
    world->st_frame = FRAME60;
}

static void frame120(world_t *world)
{
    world->settings.vsync_int = 120;
    sfRenderWindow_setFramerateLimit(world->window, 120);
    sfText_setString(world->settings.frame_t, "Framerate : 120 FPS");
    world->st_frame = FRAME120;
}

static void frame144(world_t *world)
{
    world->settings.vsync_int = 144;
    sfRenderWindow_setFramerateLimit(world->window, 144);
    sfText_setString(world->settings.frame_t, "Framerate : 144 FPS");
    world->st_frame = FRAME144;
}

static void frame240(world_t *world)
{
    world->settings.vsync_int = 240;
    sfRenderWindow_setFramerateLimit(world->window, 240);
    sfText_setString(world->settings.frame_t, "Framerate : 240 FPS");
    world->st_frame = FRAME240;
}

void chose_framerate(world_t *world)
{
    switch (world->st_frame) {
        case FRAME240:
            unlimited(world);
            break;
        case FRAME0:
            frame30(world);
            break;
        case FRAME30:
            frame60(world);
            break;
        case FRAME60:
            frame120(world);
            break;
        case FRAME120:
            frame144(world);
            break;
        case FRAME144:
            frame240(world);
            break;
    }
}

void click_frame(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->settings.frame_case.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        chose_framerate(world);
    }
}
