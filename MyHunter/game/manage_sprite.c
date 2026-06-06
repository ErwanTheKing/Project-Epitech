/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** The manage_sprite.c
*/
/**
 * @file manage_sprite.c
 * @brief The manage_sprite.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"
#include <stdio.h>

void chose_texture(bird_t *new)
{
    int random = rand() % 3;

    switch (random) {
        case 0:
            new->texture = sfTexture_createFromFile("asset/obj/SS_01.png",
                NULL);
            break;
        case 1:
            new->texture = sfTexture_createFromFile("asset/obj/SS_02.png",
                NULL);
            break;
        case 2:
            new->texture = sfTexture_createFromFile("asset/obj/SS_03.png",
                NULL);
            break;
    }
}

bird_t *create_bird(bird_t *head)
{
    bird_t *new = malloc(sizeof(bird_t));
    sfIntRect rect = {0, 0, 160, 150};

    if (!new)
        return head;
    chose_texture(new);
    if (!new->texture)
        return head;
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setScale(new->sprite,
        (sfVector2f){0.5f, 0.5f});
    sfSprite_setPosition(new->sprite,
        (sfVector2f){800, rand() % 450 + 50});
    sfSprite_setOrigin(new->sprite, (sfVector2f){80, 75});
    new->touch = sfFalse;
    new->currentFrame = 0;
    new->rect = rect;
    new->next = head;
    return new;
}

bird_t *add_bird(bird_t *head, manage_sprite_t *manage_sprite)
{
    sfTime a = sfClock_getElapsedTime(manage_sprite->clock);
    float test = sfTime_asSeconds(a);

    if ((int)test % 5 == 0)
        head = create_bird(head);
    return head;
}

void draw_bird(bird_t *head, sfRenderWindow *window)
{
    for (; head != NULL; head = head->next) {
        sfRenderWindow_drawSprite(window, head->sprite, NULL);
    }
}

void destroy_bird(bird_t *head)
{
    bird_t *tmp;

    while (head) {
        tmp = head->next;
        sfSprite_destroy(head->sprite);
        sfTexture_destroy(head->texture);
        free(head);
        head = tmp;
    }
}
