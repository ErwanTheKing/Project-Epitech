/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The textbox.c
*/
/**
 * @file textbox.c
 * @brief The textbox.c
 * @author Erwan Lo Presti
 */

#include <stdlib.h>

#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/macros.h"
#include "../../lib/my/headers/myworld.h"

static void infos_rectangle(textbox_t *box, sfVector2f *pos, sfVector2f *size)
{
    box->rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(box->rectangle, *size);
    sfRectangleShape_setOutlineThickness(box->rectangle, 2);
    sfRectangleShape_setOutlineColor(box->rectangle,
        sfColor_fromRGB(165, 253, 254));
    sfRectangleShape_setFillColor(box->rectangle,
        sfColor_fromRGBA(0, 0, 0, 125));
    sfRectangleShape_setOrigin(box->rectangle,
        (sfVector2f){size->x / 2, size->y / 2});
    sfRectangleShape_setPosition(box->rectangle, *pos);
}

static void infos_text(textbox_t *box, sfVector2f *pos)
{
    sfFloatRect size;

    box->font = sfFont_createFromFile(FONT_SPECIAL);
    box->text = sfText_create();
    sfText_setFont(box->text, box->font);
    sfText_setColor(box->text, sfColor_fromRGB(165, 253, 254));
    sfText_setCharacterSize(box->text, 25);
    size = sfText_getGlobalBounds(box->text);
    sfText_setOrigin(box->text,
        (sfVector2f){ size.left + size.width / 2.f,
            size.top + size.height / 2.f});
    sfText_setPosition(box->text, *pos);
}

textbox_t *create_textbox(sfVector2f *pos, sfVector2f *size)
{
    textbox_t *box = malloc(sizeof(textbox_t));

    if (!box)
        return NULL;
    infos_rectangle(box, pos, size);
    infos_text(box, pos);
    box->length = 0;
    box->input[0] = '\0';
    box->selected = 0;
    return box;
}

static int size_box(choose_t *choose, world_t *world)
{
    sfVector2f posX = {world->mode.width / 2.9, world->mode.height / 1.65};
    sfVector2f posY = {world->mode.width / 2.5, world->mode.height / 1.65};
    sfVector2f sizeX = {60, 50};
    sfVector2f sizeY = {60, 50};

    choose->size_x = create_textbox(&posX, &sizeX);
    if (!choose->size_x)
        return FAILURE;
    choose->size_y = create_textbox(&posY, &sizeY);
    if (!choose->size_y)
        return FAILURE;
    return SUCCESS;
}

void get_size_custom(world_t *world, textbox_t *sizeX, textbox_t *sizeY)
{
    int x = atoi(sizeX->input);
    int y = atoi(sizeY->input);

    if (x > 250)
        x = 250;
    if (y > 250)
        y = 250;
    world->coords.x = x;
    world->coords.y = y;
}

int textbox(choose_t *choose, world_t *world)
{
    sfVector2f pos = {world->mode.width / 2.8, world->mode.height / 2.75};
    sfVector2f size = {350, 70};

    choose->name = create_textbox(&pos, &size);
    if (!choose->name)
        return FAILURE;
    if (size_box(choose, world) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
