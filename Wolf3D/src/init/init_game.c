/*
** EPITECH PROJECT, 2026
** init
** File description:
** player
*/

#include "../../include/wolf3d.h"

static void free_wall(wall_t *wall)
{
    if (!wall)
        return;
    for (int i = 0; i < 2; i++) {
        if (wall->text_arr[i])
            free(wall->text_arr[i]);
    }
    for (int i = 0; i < 6; i++) {
        if (wall->decor_arr[i])
            free(wall->decor_arr[i]);
    }
    if (wall->pixel)
        free(wall->pixel);
    if (wall->texture)
        sfTexture_destroy(wall->texture);
    if (wall->sprite)
        sfSprite_destroy(wall->sprite);
    free(wall);
}

static void free_game_partial(game_t *game)
{
    if (!game)
        return;
    for (int i = 0; i < 2; i++) {
        if (game->clock[i])
            sfClock_destroy(game->clock[i]);
    }
    free_wall(game->wall);
    free(game->zbuffer);
    free(game);
}

wall_t *init_texture(wall_t *wall, int size, char *path, sfUint8 **pixel)
{
    sfImage *image = sfImage_createFromFile(path);
    const sfUint8 *tmp = NULL;

    if (!image)
        return NULL;
    tmp = sfImage_getPixelsPtr(image);
    *pixel = malloc(size);
    if (!*pixel)
        return sfImage_destroy(image), NULL;
    if (!tmp) {
        free(*pixel);
        sfImage_destroy(image);
        return NULL;
    }
    memcpy(*pixel, tmp, size);
    sfImage_destroy(image);
    return wall;
}

static wall_t *init_pixels(wall_t *wall, int size)
{
    int psize = TEX_PLAYER_W * TEX_PLAYER_H * 4;
    int gsize = 1600 * 500 * 4;

    if (!init_texture(wall, size, "assets/wall.png", &wall->text_arr[0]) ||
        !init_texture(wall, size, "assets/wall_2.png", &wall->text_arr[1]) ||
        !init_texture(wall, size, "assets/ceiling.png", &wall->decor_arr[0]) ||
        !init_texture(wall, size, "assets/floor.png", &wall->decor_arr[1]) ||
        !init_texture(wall, psize, "assets/player.png", &wall->decor_arr[2]) ||
        !init_texture(wall, psize, "assets/ennemy.png", &wall->decor_arr[3]) ||
        !init_texture(wall, gsize, "assets/garbage.png", &wall->decor_arr[4]) ||
        !init_texture(wall, psize, "assets/heal.png", &wall->decor_arr[5]))
        return NULL;
    return wall;
}

wall_t *init_wall(window_t *window_data)
{
    wall_t *wall = calloc(1, sizeof(wall_t));
    int size = TEX_SIZE * TEX_SIZE * 4;

    if (!wall)
        return NULL;
    wall->texture = sfTexture_create(window_data->width, window_data->height);
    wall->sprite = sfSprite_create();
    if (!wall->texture || !wall->sprite || !init_pixels(wall, size)) {
        free_wall(wall);
        return NULL;
    }
    sfSprite_setTexture(wall->sprite, wall->texture, sfTrue);
    return wall;
}

game_t *init_game(window_t *window_data)
{
    game_t *game = calloc(1, sizeof(game_t));

    if (!game)
        return NULL;
    for (int i = 0; i < 2; i++)
        game->clock[i] = sfClock_create();
    game->wall = init_wall(window_data);
    if (!game->clock[0] || !game->clock[1] || !game->wall) {
        free_game_partial(game);
        return NULL;
    }
    return game;
}
