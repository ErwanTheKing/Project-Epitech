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

static int fill_infos(infos_tower_t *infos_tower, char **array)
{
    if (array[0] == NULL || array[1] == NULL || array[2] == NULL
        || array[3] == NULL)
        return FAILURE;
    infos_tower->x = my_getnbr(array[1]);
    infos_tower->y = my_getnbr(array[2]);
    infos_tower->radius = my_getnbr(array[3]);
    return SUCCESS;
}

static int create_sprite(infos_tower_t *infos_tower)
{
    infos_tower->design.texture = sfTexture_createFromFile(TOWER, NULL);
    if (!infos_tower->design.texture)
        return FAILURE;
    infos_tower->design.sprite = sfSprite_create();
    sfSprite_setTexture(infos_tower->design.sprite,
        infos_tower->design.texture, sfTrue);
    sfSprite_setPosition(infos_tower->design.sprite,
        (sfVector2f){infos_tower->x, infos_tower->y});
    return SUCCESS;
}

static void create_area(infos_tower_t *infos_tower)
{
    infos_tower->area = sfCircleShape_create();
    sfCircleShape_setRadius(infos_tower->area, infos_tower->radius);
    sfCircleShape_setOutlineThickness(infos_tower->area, 5);
    sfCircleShape_setOutlineColor(infos_tower->area, sfBlue);
    sfCircleShape_setOrigin(infos_tower->area,
        (sfVector2f){infos_tower->radius, infos_tower->radius});
    sfCircleShape_setPosition(infos_tower->area,
        (sfVector2f){infos_tower->x + 50, infos_tower->y + 70});
    sfCircleShape_setFillColor(infos_tower->area, sfTransparent);
}

int add_tower(tower_t **tower, char *buffer)
{
    tower_t *new_tower = malloc(sizeof(tower_t));
    infos_tower_t *infos_tower = NULL;
    char **array = my_str_to_word_array(buffer, " \t");

    if (!new_tower || !array)
        return FAILURE;
    new_tower->data = malloc(sizeof(infos_tower_t));
    if (!new_tower->data)
        return FAILURE;
    infos_tower = new_tower->data;
    if (fill_infos(infos_tower, array) == FAILURE)
        return FAILURE;
    if (create_sprite(infos_tower) == FAILURE)
        return FAILURE;
    create_area(infos_tower);
    new_tower->next = *tower;
    *tower = new_tower;
    free_array(array);
    return SUCCESS;
}

void del_tower(tower_t **tower)
{
    struct infos_tower_s *infos_tower = NULL;

    for (; *tower != NULL; *tower = (*tower)->next) {
        infos_tower = (*tower)->data;
        sfSprite_destroy(infos_tower->design.sprite);
        sfTexture_destroy(infos_tower->design.texture);
        sfCircleShape_destroy(infos_tower->area);
        free(infos_tower);
    }
}

void draw_tower(main_radar_t *radar)
{
    infos_tower_t *infos_tower = NULL;

    for (tower_t *tmp = radar->tower; tmp != NULL; tmp = tmp->next){
        infos_tower = tmp->data;
        if (radar->disp_sprite == sfTrue)
            sfRenderWindow_drawSprite(radar->window,
                infos_tower->design.sprite, NULL);
        if (radar->disp_hitbox == sfTrue)
            sfRenderWindow_drawCircleShape(radar->window,
                infos_tower->area, NULL);
    }
}
