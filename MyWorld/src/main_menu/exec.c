/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The exec.c
*/
/**
 * @file exec.c
 * @brief The exec.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"

void click_quit(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds = sfSprite_getGlobalBounds(world->main_menu.quit.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->st_game = EXIT;
    }
}

void click_settings(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->main_menu.settings.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->st_game = SETTINGS_M;
    }
}

void click_start(world_t *world)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(world->window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(world->window, pixelPos,
        NULL);
    sfFloatRect bounds
    = sfSprite_getGlobalBounds(world->main_menu.start.sprite);

    if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
        world->st_game = CHOOSE;
    }
}

static void apply_change(world_t *world)
{
    sfRenderWindow_setMouseCursorVisible(world->window, sfFalse);
    if (world->settings.vsync == sfTrue)
        sfRenderWindow_setVerticalSyncEnabled(world->window, sfTrue);
    else
        sfRenderWindow_setVerticalSyncEnabled(world->window, sfFalse);
    sfRenderWindow_setFramerateLimit(world->window, world->settings.vsync_int);
    resize(world);
}

void switch_full(world_t *world)
{
    sfVideoMode fullMode = sfVideoMode_getDesktopMode();

    sfRenderWindow_destroy(world->window);
    if (world->settings.fullscreen == sfFalse) {
        world->window = sfRenderWindow_create(fullMode,
            "Transform Mars", sfFullscreen, NULL);
        world->mode = fullMode;
        world->settings.fullscreen = sfTrue;
    } else {
        world->mode = world->oldMode;
        world->window = sfRenderWindow_create(world->mode, "Transform Mars",
            sfTitlebar | sfClose, NULL);
        world->settings.fullscreen = sfFalse;
    }
    apply_change(world);
}
