/*
** EPITECH PROJECT, 2026
** init
** File description:
** player
*/

#include "../../include/wolf3d.h"
#include <math.h>

static void destroy_entity(entity_t *entity)
{
    if (!entity)
        return;
    if (entity->clock)
        sfClock_destroy(entity->clock);
    if (entity->sprite)
        sfSprite_destroy(entity->sprite);
    if (entity->texture)
        sfTexture_destroy(entity->texture);
    free(entity);
}

static void init_weapon_fields(weapon_t *weapon, const weapon_config_t *cfg)
{
    *weapon = (weapon_t){
        .type = cfg->type,
        .attack_speed = cfg->type == GUN ? 0.7 : 1.1,
        .current_ammo = cfg->max_ammo,
        .max_ammo = cfg->max_ammo,
        .damage = cfg->damage,
        .entity = cfg->entity,
        .rect = (sfIntRect){0, 0, 400, 600}
    };
}

static weapon_t *create_weapon(wp_type_t type, int damage,
    int max_ammo, entity_t *entity)
{
    weapon_t *weapon = calloc(1, sizeof(weapon_t));
    weapon_config_t cfg;

    if (!weapon || !entity) {
        destroy_entity(entity);
        free(weapon);
        return NULL;
    }
    cfg = (weapon_config_t){type, damage, max_ammo, entity};
    init_weapon_fields(weapon, &cfg);
    weapon->cd = sfClock_create();
    if (!weapon->cd) {
        destroy_entity(weapon->entity);
        free(weapon);
        return NULL;
    }
    return weapon;
}

weapon_t *init_weapon(wp_type_t type, int damage,
    int max_ammo, entity_t *entity)
{
    weapon_t *weapon = create_weapon(type, damage, max_ammo, entity);

    if (!weapon)
        return NULL;
    sfSprite_setTextureRect(entity->sprite, weapon->rect);
    sfSprite_setOrigin(entity->sprite, (sfVector2f){200, 600});
    return weapon;
}

static void init_player_data(player_t *player, p_type_t type, sfVector2f *pos)
{
    player->net_id = type * MAP_AREA + (int)pos->y * MAP_WIDTH + (int)pos->x;
    player->x = pos->x;
    player->y = pos->y;
    player->z = 0.0;
    player->angle = fmodf(0.0f, 2.0f * M_PI);
    if (player->angle < 0.0f)
        player->angle += 2.0f * M_PI;
    player->hp = 100;
    player->max_hp = 100;
    player->speed = 100;
    player->stamina = MAX_STAMINA;
    player->type = type;
    player->alive = sfTrue;
    player->weapon = NULL;
    player->ai_clock = sfClock_create();
    player->attack_clock = sfClock_create();
    player->damage_clock = sfClock_create();
    player->took_damage = sfFalse;
    player->path_target_x = pos->x;
    player->path_target_y = pos->y;
}

player_t *init_player(window_t *win, p_type_t type, sfVector2f *pos)
{
    player_t *player = calloc(1, sizeof(player_t));

    (void)win;
    if (!player)
        return NULL;
    init_player_data(player, type, pos);
    return player;
}

void destroy_player(player_t *player)
{
    if (!player)
        return;
    if (player->ai_clock)
        sfClock_destroy(player->ai_clock);
    if (player->attack_clock)
        sfClock_destroy(player->attack_clock);
    if (player->damage_clock)
        sfClock_destroy(player->damage_clock);
    free(player);
}
