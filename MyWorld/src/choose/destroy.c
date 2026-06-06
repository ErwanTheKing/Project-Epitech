/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The destroy.c
*/
/**
 * @file destroy.c
 * @brief The destroy.c
 * @author Erwan Lo Presti
 */

#include <stdlib.h>

#include "../../lib/my/headers/myworld.h"

static void texture(choose_t *choose)
{
    sfTexture_destroy(choose->background.texture);
    sfTexture_destroy(choose->back.texture);
    sfTexture_destroy(choose->create.texture);
    sfTexture_destroy(choose->load.texture);
}

static void sprite(choose_t *choose)
{
    sfSprite_destroy(choose->background.sprite);
    sfSprite_destroy(choose->back.sprite);
    sfSprite_destroy(choose->create.sprite);
    sfSprite_destroy(choose->load.sprite);
}

static void text(choose_t *choose)
{
    sfText_destroy(choose->back_t);
    sfText_destroy(choose->create_t);
    sfText_destroy(choose->load_t);
    sfText_destroy(choose->small_t);
    sfText_destroy(choose->medium_t);
    sfText_destroy(choose->large_t);
    sfText_destroy(choose->custom_t);
    sfText_destroy(choose->x_t);
}

static void circle(choose_t *choose)
{
    sfCircleShape_destroy(choose->small);
    sfCircleShape_destroy(choose->medium);
    sfCircleShape_destroy(choose->large);
    sfCircleShape_destroy(choose->custom);
    sfCircleShape_destroy(choose->selected);
}

static void textbox_d(textbox_t *box)
{
    sfRectangleShape_destroy(box->rectangle);
    sfFont_destroy(box->font);
    sfText_destroy(box->text);
    free(box);
}

static void maps(map_entry_t *maps, choose_t *choose)
{
    for (int i = 0; i < choose->len; i++) {
        sfFont_destroy(maps[i].font);
        sfText_destroy(maps[i].text);
        sfRectangleShape_destroy(maps[i].rectangle);
        free(maps[i].fullname);
        free(maps[i].name);
    }
}

void destroy_choose(choose_t *choose)
{
    texture(choose);
    sprite(choose);
    text(choose);
    circle(choose);
    textbox_d(choose->size_x);
    textbox_d(choose->size_y);
    textbox_d(choose->name);
    maps(choose->maps, choose);
}
