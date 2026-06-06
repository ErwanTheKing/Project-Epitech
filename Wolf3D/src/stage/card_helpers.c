/*
** EPITECH PROJECT, 2026
** stage
** File description:
** card helpers
*/

#include "../../include/wolf3d.h"
#include "stage_card.h"

void card_setup_text(card_t *card, const sfFloatRect *txt)
{
    sfText_setOutlineThickness(card->text, 3);
    sfText_setOrigin(card->text, (sfVector2f){txt->left + txt->width / 2.0f,
            txt->top + txt->height / 2.0f});
}

void card_rise_single(window_t *win, card_t *card, float step)
{
    sfVector2f pos;
    float target_y;

    if (!card->rect)
        return;
    pos = sfRectangleShape_getPosition(card->rect);
    target_y = win->height / 2.0f;
    if (pos.y <= target_y)
        return;
    pos.y -= step;
    if (pos.y < target_y)
        pos.y = target_y;
    sfRectangleShape_setPosition(card->rect, pos);
}
