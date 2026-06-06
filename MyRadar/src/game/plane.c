/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** The plane.c
*/
/**
 * @file plane.c
 * @brief The plane.c
 * @author Erwan Lo Presti
 */

#include "../../include/includes.h"

static void create_hitbox(infos_plane_t *infos_plane)
{
    infos_plane->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(infos_plane->hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(infos_plane->hitbox, (sfVector2f){25, 20});
    sfRectangleShape_setFillColor(infos_plane->hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(infos_plane->hitbox, 1);
    sfRectangleShape_setOutlineColor(infos_plane->hitbox, sfRed);
    sfRectangleShape_setPosition(infos_plane->hitbox,
        (sfVector2f){infos_plane->dep_x + 50, infos_plane->dep_y + 100});
}

static int fill_infos(infos_plane_t *infos_plane, char **array)
{
    if (array[0] == NULL || array[1] == NULL || array[2] == NULL
        || array[3] == NULL || array[4] == NULL || array[5] == NULL
        || array[6] == NULL)
        return FAILURE;
    infos_plane->dep_x = my_getnbr(array[1]);
    infos_plane->dep_y = my_getnbr(array[2]);
    infos_plane->arr_x = my_getnbr(array[3]);
    infos_plane->arr_y = my_getnbr(array[4]);
    infos_plane->speed = my_getnbr(array[5]);
    infos_plane->time_dep = my_getnbr(array[6]);
    return SUCCESS;
}

static int create_sprite(infos_plane_t *infos_plane)
{
    infos_plane->design.texture = sfTexture_createFromFile(BUS, NULL);
    if (!infos_plane->design.texture)
        return FAILURE;
    infos_plane->design.sprite = sfSprite_create();
    sfSprite_setTexture(infos_plane->design.sprite,
        infos_plane->design.texture, sfTrue);
    sfSprite_setPosition(infos_plane->design.sprite,
        (sfVector2f){infos_plane->dep_x + 30, infos_plane->dep_y + 50});
    return SUCCESS;
}

int add_plane(plane_t **plane, char *buffer)
{
    plane_t *new_plane = malloc(sizeof(plane_t));
    infos_plane_t *infos_plane = NULL;
    char **array = my_str_to_word_array(buffer, " \t");

    if (!new_plane || !array)
        return FAILURE;
    new_plane->data = malloc(sizeof(infos_plane_t));
    if (!new_plane->data)
        return FAILURE;
    infos_plane = new_plane->data;
    infos_plane->arr = sfFalse;
    if (fill_infos(infos_plane, array) == FAILURE)
        return FAILURE;
    if (create_sprite(infos_plane) == FAILURE)
        return FAILURE;
    create_hitbox(infos_plane);
    new_plane->next = *plane;
    *plane = new_plane;
    free_array(array);
    return SUCCESS;
}

void del_plane(plane_t **plane)
{
    infos_plane_t *infos_plane = NULL;

    for (; *plane != NULL; *plane = (*plane)->next) {
        infos_plane = (*plane)->data;
        sfSprite_destroy(infos_plane->design.sprite);
        sfTexture_destroy(infos_plane->design.texture);
        sfRectangleShape_destroy(infos_plane->hitbox);
        free(infos_plane);
    }
}

static void draw_bus(main_radar_t *radar, infos_plane_t *infos_plane)
{
    if (infos_plane->arr == sfFalse
        && infos_plane->time_dep <= radar->last_clock.seconds) {
        sfRenderWindow_drawSprite(radar->window,
            infos_plane->design.sprite, NULL);
    }
}

static void draw_hitbox(main_radar_t *radar, infos_plane_t *infos_plane)
{
    if (infos_plane->arr == sfFalse
        && infos_plane->time_dep <= radar->last_clock.seconds) {
        sfRenderWindow_drawRectangleShape(radar->window,
            infos_plane->hitbox, NULL);
    }
}

void draw_plane(main_radar_t *radar)
{
    infos_plane_t *infos_plane = NULL;

    for (plane_t *tmp = radar->plane; tmp != NULL; tmp = tmp->next) {
        infos_plane = tmp->data;
        move_plane(infos_plane, radar);
        if (radar->disp_sprite == sfTrue) {
            draw_bus(radar, infos_plane);
        }
        if (radar->disp_hitbox == sfTrue) {
            draw_hitbox(radar, infos_plane);
        }
    }
}

void move_plane(infos_plane_t *infos_plane, main_radar_t *radar)
{
    sfVector2f pos = sfSprite_getPosition(infos_plane->design.sprite);
    sfVector2f target = (sfVector2f){infos_plane->arr_x + 30,
        infos_plane->arr_y + 50};
    sfVector2f d = (sfVector2f){target.x - pos.x, target.y - pos.y};
    float dist = sqrtf(d.x * d.x + d.y * d.y);
    float step = infos_plane->speed * radar->clock.seconds;

    if (infos_plane->time_dep <= radar->last_clock.seconds) {
        if (dist <= step) {
            sfSprite_setPosition(infos_plane->design.sprite, target);
            infos_plane->arr = sfTrue;
        } else {
            d.x /= dist;
            d.y /= dist;
            sfSprite_move(infos_plane->design.sprite, (sfVector2f){d.x * step,
                    d.y * step});
        }
        pos = sfSprite_getPosition(infos_plane->design.sprite);
        sfRectangleShape_setPosition(infos_plane->hitbox,
            (sfVector2f){pos.x + 28, pos.y + 20});
    }
}
