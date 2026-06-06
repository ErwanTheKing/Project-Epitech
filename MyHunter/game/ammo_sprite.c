/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The ammo_sprite.c
*/
/**
 * @file ammo_sprite.c
 * @brief The ammo_sprite.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

ammo_t *create_ammo(ammo_t *ammo, sfVector2f *pos)
{
    ammo_t *new = malloc(sizeof(ammo_t));

    if (!new)
        return ammo;
    new->texture = sfTexture_createFromFile("asset/obj/ammo.png", NULL);
    if (!new->texture)
        return ammo;
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setScale(new->sprite, (sfVector2f){0.06f, 0.06f});
    sfSprite_setPosition(new->sprite, *pos);
    new->next = ammo;
    return new;
}

ammo_t *add_ammo(ammo_t *ammo)
{
    ammo = create_ammo(ammo, &(sfVector2f){205, 500});
    ammo = create_ammo(ammo, &(sfVector2f){235, 500});
    ammo = create_ammo(ammo, &(sfVector2f){265, 500});
    ammo = create_ammo(ammo, &(sfVector2f){295, 500});
    ammo = create_ammo(ammo, &(sfVector2f){325, 500});
    ammo = create_ammo(ammo, &(sfVector2f){355, 500});
    ammo = create_ammo(ammo, &(sfVector2f){385, 500});
    ammo = create_ammo(ammo, &(sfVector2f){415, 500});
    ammo = create_ammo(ammo, &(sfVector2f){445, 500});
    ammo = create_ammo(ammo, &(sfVector2f){475, 500});
    return ammo;
}

void draw_ammo(sfRenderWindow *window, ammo_t *ammo, bool_t *bool)
{
    int j = bool->ammo;

    for (; j > 0; ammo = ammo->next) {
        sfRenderWindow_drawSprite(window, ammo->sprite, NULL);
        j--;
    }
}

void destroy_ammo(ammo_t *ammo)
{
    ammo_t *tmp;

    while (ammo) {
        tmp = ammo->next;
        if (ammo->sprite)
            sfSprite_destroy(ammo->sprite);
        if (ammo->texture) {
            sfTexture_destroy(ammo->texture);
            free(ammo);
        }
        ammo = tmp;
    }
}
