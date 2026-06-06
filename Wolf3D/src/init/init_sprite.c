/*
** EPITECH PROJECT, 2026
** init
** File description:
** player
*/

#include "../../include/wolf3d.h"

entity_t *get_entity(list_t *list, char *name)
{
    entity_t *entity = NULL;

    for (list_t *curr = list; curr; curr = curr->next) {
        entity = (entity_t *)curr->data;
        if (!entity || !entity->name)
            continue;
        if (strcmp(entity->name, name) != 0)
            continue;
        return entity;
    }
    return NULL;
}

static entity_t *create_entity_base(char *name, const char *texture_path)
{
    entity_t *entity = calloc(1, sizeof(entity_t));

    if (!entity)
        return NULL;
    entity->name = name;
    entity->texture = sfTexture_createFromFile(texture_path, NULL);
    if (!entity->texture) {
        free(entity);
        return NULL;
    }
    entity->sprite = sfSprite_create();
    if (!entity->sprite) {
        sfTexture_destroy(entity->texture);
        free(entity);
        return NULL;
    }
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    return entity;
}

entity_t *create_entity(char *name,
    const char *texture_path, sfVector2f *pos, sfVector2f *scale)
{
    entity_t *entity = create_entity_base(name, texture_path);
    sfVector2u size;

    if (!entity)
        return NULL;
    size = sfTexture_getSize(entity->texture);
    sfSprite_setOrigin(entity->sprite, (sfVector2f){size.x / 2, size.y / 2});
    sfSprite_setPosition(entity->sprite, *pos);
    sfSprite_setScale(entity->sprite, *scale);
    return entity;
}

static void init_menu_sprites(wolf_t *wolf, window_t *window)
{
    sfVector2f center = {window->width / 2, window->height / 2};
    sfVector2f scale = {1, 1};
    entity_t *cloud = NULL;

    push_front(&wolf->list[MENU][SPRITE], create_entity("background",
            "assets/BG_main_menu.png", &center, &scale));
    push_front(&wolf->list[MENU][SPRITE], create_entity("cloud",
            "assets/BG_cloud.png",
            &(sfVector2f){0, window->height / 4}, &scale));
    cloud = get_entity(wolf->list[MENU][SPRITE], "cloud");
    if (cloud)
        cloud->clock = sfClock_create();
    push_front(&wolf->list[NEWGAME_MENU][SPRITE], create_entity("ng_background",
            "assets/BG_main_menu.png", &center, &scale));
    push_front(&wolf->list[NEWGAME_MENU][SPRITE], create_entity("cloud",
            "assets/BG_cloud.png",
            &(sfVector2f){0, window->height / 4}, &scale));
    push_front(&wolf->list[LOBBY][SPRITE], create_entity("lobby_background",
            "assets/BG_main_menu.png", &center, &scale));
}

static rect_t *create_dark_background(window_t *window)
{
    rect_t *rect = malloc(sizeof(rect_t));

    if (!rect)
        return NULL;
    rect->name = "game_over_background";
    rect->state = -1;
    rect->texture = NULL;
    rect->click_texture = NULL;
    rect->type = TYPE_MENU;
    rect->always_display = sfTrue;
    rect->rect = sfRectangleShape_create();
    if (!rect->rect) {
        free(rect);
        return NULL;
    }
    sfRectangleShape_setSize(rect->rect,
        (sfVector2f){window->width, window->height});
    sfRectangleShape_setFillColor(rect->rect, sfColor_fromRGB(8, 9, 12));
    return rect;
}

void init_menu_entities(wolf_t *wolf, window_t *window)
{
    rect_t *background = NULL;

    for (int i = 0; i < STATES; i++) {
        for (int j = 0; j < TO_DRAW; j++)
            wolf->list[i][j] = NULL;
    }
    init_menu_sprites(wolf, window);
    background = create_dark_background(window);
    if (background)
        push_front(&wolf->list[GAME_OVER][RECT], background);
}

void init_pause_entities(wolf_t *wolf, window_t *window)
{
    push_front(&wolf->list[PAUSE][SPRITE], create_entity("background",
            "assets/BG_main_menu.png",
            &(sfVector2f){window->width / 2, window->height / 2},
            &(sfVector2f){1, 1}));
    push_front(&wolf->list[PAUSE][SPRITE], create_entity("cloud",
            "assets/BG_cloud.png",
            &(sfVector2f){0, window->height / 4},
            &(sfVector2f){1, 1}));
}

void init_settings_entities(wolf_t *wolf, window_t *window)
{
    push_front(&wolf->list[SETTINGS][SPRITE], create_entity("menu",
            "assets/menu_settings.png",
            &(sfVector2f){window->width / 2, window->height / 2},
            &(sfVector2f){0.8, 0.8}));
    push_front(&wolf->list[SETTINGS][SPRITE], create_entity("background",
            "assets/BG_main_menu.png",
            &(sfVector2f){window->width / 2, window->height / 2},
            &(sfVector2f){1, 1}));
    push_front(&wolf->list[SETTINGS][SPRITE], create_entity("cloud",
            "assets/BG_cloud.png",
            &(sfVector2f){0, window->height / 4},
            &(sfVector2f){1, 1}));
}
