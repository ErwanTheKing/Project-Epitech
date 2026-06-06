/*
** EPITECH PROJECT, 2026
** stage
** File description:
** stage
*/

#include "../include/wolf3d.h"
#include <time.h>

static sfColor get_color(int type, int rd)
{
    sfColor color[5] = {WHITE, BLUE, RED, PURPLE, GREEN};

    if (type != ITEM) {
        if (rd > 50)
            color[type].g += 15;
        if (rd > 30)
            color[type].g += 15;
        if (rd > 15)
            color[type].g += 15;
        if (rd > 3)
            color[type].g += 15;
    }
    return color[type];
}

void create_card(wolf_t *wolf, card_t *card, sfVector2f *pos,
    sfVector2f *size)
{
    sfColor c;
    sfFloatRect txt;
    int rd = rand() % 100 + 1;

    card->hoover = sfFalse;
    wolf->player->weapon = NULL;
    card->text = sfText_create();
    if (!card->text)
        return;
    sfText_setFont(card->text, wolf->data->font);
    create_bonus(card, rd, &wolf->game->inv);
    c = get_color(card->bonus, rd);
    txt = sfText_getGlobalBounds(card->text);
    card_setup_text(card, &txt);
    card->rect = create_rect(size, pos, &c);
    if (!card->rect) {
        sfText_destroy(card->text);
        card->text = NULL;
    }
}

static void destroy_card_set(intermission_t *inter)
{
    for (int i = 0; i < 3; i++) {
        if (inter->card[i].text)
            sfText_destroy(inter->card[i].text);
        if (inter->card[i].rect)
            sfRectangleShape_destroy(inter->card[i].rect);
    }
}

static void reset_card_state(wolf_t *wolf, intermission_t *inter)
{
    inter->done = sfFalse;
    inter->selected = sfFalse;
    inter->round = 0;
    sfClock_restart(inter->clock);
    sfRenderWindow_setMouseCursorVisible(wolf->window_data->window, sfTrue);
}

void init_card(wolf_t *wolf, intermission_t *inter)
{
    window_t *win = wolf->window_data;
    float card_w = win->width * CARD_W;
    float card_h = win->height * CARD_H;
    float gap = win->width * CARD_GAP;
    float start_x = (win->width) / 4;
    sfVector2f size = {card_w, card_h};

    if (inter->clock)
        sfClock_destroy(inter->clock);
    destroy_card_set(inter);
    inter->clock = sfClock_create();
    for (int i = 0; i < 3; i++) {
        create_card(wolf, &inter->card[i],
            &(sfVector2f){start_x + i * (card_w + gap), win->height}, &size);
    }
    reset_card_state(wolf, inter);
}

void recreate_card_set(wolf_t *wolf, window_t *win, intermission_t *inter)
{
    float card_w = win->width * CARD_W;
    float gap = win->width * CARD_GAP;
    float start_x = (win->width) / 4;
    sfVector2f size = {card_w, win->height * CARD_H};

    for (int j = 0; j < 3; j++) {
        if (inter->card[j].text)
            sfText_destroy(inter->card[j].text);
        if (inter->card[j].rect)
            sfRectangleShape_destroy(inter->card[j].rect);
        create_card(wolf, &inter->card[j], &(sfVector2f){start_x + j *
                (card_w + gap), win->height}, &size);
    }
}

static void draw_text_based_on_bonus(window_t *win,
    card_t *card, sfVector2f *pos)
{
    char *str[5] = {"Increase speed", "Reduce attack speed",
        "Increase Damage", "New Item", "Increase HP"};
    const char *tmp = sfText_getString(card->text);
    sfVector2f tmp_origin = sfText_getOrigin(card->text);
    sfFloatRect txt;

    sfText_setString(card->text, str[card->bonus]);
    txt = sfText_getLocalBounds(card->text);
    sfText_setOrigin(card->text, (sfVector2f){txt.left + txt.width / 2.0f,
            txt.top + txt.height / 2.0f});
    sfText_setPosition(card->text, *pos);
    sfRenderWindow_drawText(win->window, card->text, NULL);
    sfText_setString(card->text, tmp);
    sfText_setOrigin(card->text, tmp_origin);
}

void draw_card(wolf_t *wolf, intermission_t *inter)
{
    sfVector2f pos;

    for (int i = 0; i < 3; i++) {
        if (!inter->card[i].rect || !inter->card[i].text)
            continue;
        pos = sfRectangleShape_getPosition(inter->card[i].rect);
        sfRenderWindow_drawRectangleShape(wolf->window_data->window,
            inter->card[i].rect, NULL);
        draw_text_based_on_bonus(wolf->window_data, &inter->card[i], &pos);
        pos.y -= wolf->window_data->height / 4;
        sfText_setPosition(inter->card[i].text, pos);
        sfRenderWindow_drawText(wolf->window_data->window,
            inter->card[i].text, NULL);
    }
}

void rise_card(wolf_t *wolf, intermission_t *inter)
{
    window_t *win = wolf->window_data;
    float dt = sfTime_asSeconds(sfClock_restart(inter->clock));
    float step = CARD_SPEED * dt;
    int done = 0;
    sfVector2f pos;

    if (inter->done)
        return;
    for (int i = 0; i < 3; i++) {
        if (!inter->card[i].rect)
            continue;
        card_rise_single(win, &inter->card[i], step);
        pos = sfRectangleShape_getPosition(inter->card[i].rect);
        if (pos.y <= win->height / 2.0f)
            done++;
    }
    inter->done = (done == 3) ? sfTrue : sfFalse;
}
