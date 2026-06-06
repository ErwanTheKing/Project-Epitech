/*
** EPITECH PROJECT, 2026
** stage
** File description:
** card helpers
*/

#ifndef STAGE_CARD_H
    #define STAGE_CARD_H

    #include "wolf3d.h"

void card_setup_text(card_t *card, const sfFloatRect *txt);
void card_rise_single(window_t *win, card_t *card, float step);

#endif
