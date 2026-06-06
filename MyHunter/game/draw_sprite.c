/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The draw_sprite.c
*/
/**
 * @file draw_sprite.c
 * @brief The draw_sprite.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../include/includes.h"

static void execute_clock(bird_t *tmp)
{
    if (tmp->touch == sfFalse) {
        tmp->currentFrame++;
        if (tmp->currentFrame >= 8)
            tmp->currentFrame = 0;
        tmp->rect.left
        = tmp->currentFrame * tmp->rect.width;
        sfSprite_setTextureRect(tmp->sprite,
            tmp->rect);
    }
}

void dead(bool_t *bool, sfRenderWindow *window, music_t *music)
{
    if (bool->life <= 0 || bool->ammo <= 0) {
        if (my_getnbr(bool->highscore) < my_getnbr(bool->str_count)) {
            bool->fd = open("game/highscore.txt", O_TRUNC | O_RDWR);
            write(bool->fd, bool->str_count, my_strlen(bool->str_count));
            close(bool->fd);
        }
        loose_menu(window, bool, music);
    }
}

static void manage_mode(bird_t *tmp, bool_t *bool)
{
    if (tmp->pos.x <= -20) {
        if (bool->mode == 0)
            bool->life -= 1;
        if (bool->mode == 1 && bool->life > 1)
            bool->life -= 1;
        tmp->pos.x = 900;
        tmp->pos.y = rand() % 450 + 50;
    }
}

static void execute_movement(bool_t *bool)
{
    for (bird_t *tmp = bool->bird_right; tmp != NULL; tmp = tmp->next) {
        execute_clock(tmp);
        tmp->pos = sfSprite_getPosition(tmp->sprite);
        manage_mode(tmp, bool);
        if (tmp->pos.y > 600) {
            tmp->touch = sfFalse;
            sfSprite_setRotation(tmp->sprite, 0);
            tmp->pos.y = rand() % 450 + 50;
            tmp->pos.x = 900;
        }
        if (tmp->touch == sfTrue)
            tmp->pos.y += 30;
        else
            tmp->pos.x -= bool->speed;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        sfSprite_setTextureRect(tmp->sprite, tmp->rect);
    }
}

static void manage_params(bool_t *bool, manage_sprite_t *manage_sprite)
{
    if (bool->currentTime - bool->lastTime_bird >= 5.0f) {
        bool->bird_right = create_bird(bool->bird_right);
        bool->lastTime_bird = bool->currentTime;
    }
    if (bool->currentTime - bool->lastTime_speed >= 10.0f) {
        bool->speed += 1;
        bool->lastTime_speed = bool->currentTime;
    }
    if (manage_sprite->seconds - manage_sprite->seconds2 >= 25000) {
        execute_movement(bool);
        manage_sprite->last_Time = manage_sprite->Time;
    }
}

static void draw1(sfRenderWindow *window, manage_sprite_t *manage_sprite,
    bool_t *bool)
{
    bool->str_count = my_nbr_to_str(bool->count_point);
    manage_sprite->Time = sfClock_getElapsedTime(manage_sprite->clock);
    manage_sprite->seconds = sfTime_asMicroseconds(manage_sprite->Time);
    manage_sprite->seconds2 = sfTime_asMicroseconds(manage_sprite->last_Time);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, manage_sprite->background.sprite, NULL);
    draw_bird(bool->bird_right, window);
    bool->currentTime
    = sfTime_asSeconds(sfClock_getElapsedTime(manage_sprite->clock));
    manage_params(bool, manage_sprite);
}

static void draw_heart(bool_t *bool, sfRenderWindow *window,
    manage_sprite_t *manage_sprite)
{
    if (bool->life >= 5)
        sfRenderWindow_drawSprite(window, manage_sprite->heart5.sprite, NULL);
    if (bool->life >= 4)
        sfRenderWindow_drawSprite(window, manage_sprite->heart4.sprite, NULL);
    if (bool->life >= 3)
        sfRenderWindow_drawSprite(window, manage_sprite->heart3.sprite, NULL);
    if (bool->life >= 2)
        sfRenderWindow_drawSprite(window, manage_sprite->heart2.sprite, NULL);
    if (bool->life >= 1)
        sfRenderWindow_drawSprite(window, manage_sprite->heart1.sprite, NULL);
}

static void draw2(sfRenderWindow *window, manage_sprite_t *manage_sprite,
    bool_t *bool)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, pixelPos, NULL);

    sfRenderWindow_drawSprite(window, manage_sprite->bg_score.sprite, NULL);
    sfRenderWindow_drawText(window, manage_sprite->score, NULL);
    sfText_setString(manage_sprite->score_nb, bool->str_count);
    sfRenderWindow_drawText(window, manage_sprite->score_nb, NULL);
    sfRenderWindow_drawSprite(window, manage_sprite->bg_heart.sprite, NULL);
    draw_heart(bool, window, manage_sprite);
    draw_ammo(window, bool->mun, bool);
    sfSprite_setPosition(manage_sprite->visor.sprite, mouse);
    sfRenderWindow_drawSprite(window, manage_sprite->visor.sprite, NULL);
}

void execute_hunter(sfRenderWindow *window, manage_sprite_t *manage_sprite,
    bool_t *bool)
{
    draw1(window, manage_sprite, bool);
    draw2(window, manage_sprite, bool);
}
