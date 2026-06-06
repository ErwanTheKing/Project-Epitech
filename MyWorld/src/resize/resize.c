/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The resize.c
*/
/**
 * @file resize.c
 * @brief The resize.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/myworld.h"

void resize_textbox(textbox_t *box, sfVector2f *position, sfVector2f *size,
    unsigned int scale)
{
    resize_text(box->text, position, scale);
    sfRectangleShape_setSize(box->rectangle, *size);
    sfRectangleShape_setOrigin(box->rectangle, (sfVector2f){size->x / 2,
            size->y / 2});
    sfRectangleShape_setPosition(box->rectangle, *position);
}

void resize_sprite(sfSprite *sprite, sfVector2f *position, sfVector2f *scale)
{
    sfSprite_setScale(sprite, *scale);
    sfSprite_setPosition(sprite, *position);
}

void resize_text(sfText *text, sfVector2f *position, unsigned int scale)
{
    sfFloatRect bounds;

    sfText_setCharacterSize(text, scale);
    bounds = sfText_getLocalBounds(text);
    sfText_setOrigin(text,
        (sfVector2f){ bounds.left + bounds.width / 2.f,
            bounds.top + bounds.height / 2.f});
    sfText_setPosition(text, *position);
}

void resize_circle(sfCircleShape *circle, sfVector2f *position, float radius)
{
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setPosition(circle, *position);
}
