/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The destroy_sprite.c
*/
/**
 * @file destroy_sprite.c
 * @brief The destroy_sprite.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

static void destroy_sprite1(manage_sprite_t *manage_sprite)
{
    sfSprite_destroy(manage_sprite->visor.sprite);
    sfTexture_destroy(manage_sprite->visor.texture);
    sfSprite_destroy(manage_sprite->background.sprite);
    sfTexture_destroy(manage_sprite->background.texture);
    sfClock_destroy(manage_sprite->clock);
    sfFont_destroy(manage_sprite->font);
    sfText_destroy(manage_sprite->score);
    sfText_destroy(manage_sprite->score_nb);
    sfSprite_destroy(manage_sprite->bg_score.sprite);
    sfTexture_destroy(manage_sprite->bg_score.texture);
    sfSprite_destroy(manage_sprite->heart1.sprite);
    sfTexture_destroy(manage_sprite->heart1.texture);
    sfSprite_destroy(manage_sprite->heart2.sprite);
    sfTexture_destroy(manage_sprite->heart2.texture);
    sfSprite_destroy(manage_sprite->heart3.sprite);
    sfTexture_destroy(manage_sprite->heart3.texture);
    sfSprite_destroy(manage_sprite->heart4.sprite);
    sfTexture_destroy(manage_sprite->heart4.texture);
}

static void destroy_sprite2(manage_sprite_t *manage_sprite)
{
    sfSprite_destroy(manage_sprite->heart5.sprite);
    sfTexture_destroy(manage_sprite->heart5.texture);
    sfSprite_destroy(manage_sprite->bg_heart.sprite);
    sfTexture_destroy(manage_sprite->bg_heart.texture);
    free(manage_sprite);
}

void destroy_hunter(manage_sprite_t *manage_sprite, bool_t *bool)
{
    destroy_sprite1(manage_sprite);
    destroy_sprite2(manage_sprite);
    destroy_bird(bool->bird_right);
    destroy_ammo(bool->mun);
}
