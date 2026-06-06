/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Load game state
*/

#include "../../include/wolf3d.h"

static int read_last_name(char *name, size_t size)
{
    FILE *file = fopen("saves/last.txt", "r");

    if (!file)
        return -1;
    if (!fgets(name, size, file)) {
        fclose(file);
        return -1;
    }
    name[strcspn(name, "\n")] = '\0';
    fclose(file);
    return name[0] == '\0' ? -1 : 0;
}

static int build_load_path(char *path, size_t size, const char *name)
{
    char last_name[SAVE_NAME_MAX + 1];
    const char *save_name = name;
    int written = 0;

    if (!save_name || save_name[0] == '\0') {
        if (read_last_name(last_name, sizeof(last_name)) < 0)
            return -1;
        save_name = last_name;
    }
    written = snprintf(path, size, "saves/%s.sav", save_name);
    if (written < 0 || (size_t)written >= size)
        return -1;
    return 0;
}

static weapon_t *find_inventory_weapon(inv_t *inv, wp_type_t type)
{
    for (int i = 0; i < 8; i++) {
        if (inv->slot[i].item.data && inv->slot[i].item.type == type)
            return (weapon_t *)inv->slot[i].item.data;
    }
    if (type >= GUN && type <= BANDAGE)
        return (weapon_t *)inv->item[type].data;
    return NULL;
}

static void apply_weapon_data(weapon_t *weapon, weapon_save_t *save)
{
    if (!weapon)
        return;
    weapon->current_ammo = save->ammo;
    weapon->max_ammo = save->max_ammo;
    weapon->damage = save->damage;
    weapon->attack_speed = save->attack_speed;
    weapon->reloading = 0;
    weapon->current_frame = 0;
    weapon->rect.left = 0;
    if (weapon->entity)
        sfSprite_setTextureRect(weapon->entity->sprite, weapon->rect);
}

static int read_player(FILE *file, player_t *player)
{
    int alive = 0;

    if (fscanf(file, " player %f %f %f %f %d %d %f %f %d\n",
            &player->x, &player->y, &player->z, &player->angle,
            &player->hp, &player->max_hp, &player->speed,
            &player->stamina, &alive) != 9)
        return -1;
    player->alive = alive ? sfTrue : sfFalse;
    player->running = sfFalse;
    player->took_damage = sfFalse;
    return 0;
}

static int read_inventory(FILE *file, inv_t *inv)
{
    int index = 0;
    weapon_save_t save = {0};

    for (int i = 0; i < 8; i++) {
        if (fscanf(file, " slot %d %d %d %d %d %f\n", &index, &save.type,
                &save.ammo, &save.max_ammo, &save.damage,
                &save.attack_speed) != 6)
            return -1;
        if (index < 0 || index >= 8)
            return -1;
        inv->slot[index].item.data = NULL;
        inv->slot[index].selected = sfFalse;
        if (save.type < GUN || save.type > BANDAGE)
            continue;
        inv->slot[index].item = inv->item[save.type];
        apply_weapon_data((weapon_t *)inv->slot[index].item.data, &save);
    }
    return 0;
}

static int read_map(FILE *file, wall_t *wall)
{
    char label[4];
    int *flat = (int *)wall->map;

    if (fscanf(file, " %3s\n", label) != 1 || strcmp(label, "map") != 0)
        return -1;
    for (int i = 0; i < MAP_AREA; i++)
        if (fscanf(file, "%d", &flat[i]) != 1)
            return -1;
    return 0;
}

static void reset_loaded_game(wolf_t *wolf)
{
    sfMouse_setPositionRenderWindow((sfVector2i){wolf->window_data->width / 2,
            wolf->window_data->height / 2}, wolf->window_data->window);
    sfRenderWindow_setMouseCursorVisible(wolf->window_data->window, sfFalse);
    wolf->game->has_shot = 0;
    wolf->game->inv.open = sfFalse;
    wolf->game->state = STAGE;
    sfClock_restart(wolf->game->clock[GLOBAL]);
    sfClock_restart(wolf->game->clock[MOVE_CLOCK]);
    wolf->ignore_shot_until_release = sfTrue;
    wolf->score = 0;
    wolf->state = GAME;
}

static int read_save_file(FILE *file, wolf_t *wolf, weapon_save_t *save)
{
    char header[16];
    int version = 0;

    if (fscanf(file, "%15s %d\n", header, &version) != 2)
        return -1;
    if (strcmp(header, "wolf3d_save") != 0 || version != 1)
        return -1;
    if (read_player(file, wolf->player) < 0)
        return -1;
    if (fscanf(file, " weapon %d %d %d %d %f\n", &save->type, &save->ammo,
            &save->max_ammo, &save->damage, &save->attack_speed) != 5)
        return -1;
    if (save_read_inventory_items(file, &wolf->game->inv) < 0)
        return -1;
    if (read_inventory(file, &wolf->game->inv) < 0)
        return -1;
    if (read_map(file, wolf->game->wall) < 0)
        return -1;
    return save_read_entities(file, wolf);
}

int load_game(wolf_t *wolf, const char *name)
{
    FILE *file = NULL;
    char path[SAVE_PATH_MAX];
    weapon_save_t save = {0};

    if (wolf->connected || wolf->net.player_id != MAX_PLAYERS ||
        build_load_path(path, sizeof(path), name) < 0)
        return -1;
    file = fopen(path, "r");
    if (!file)
        return -1;
    if (read_save_file(file, wolf, &save) < 0) {
        fclose(file);
        return -1;
    }
    fclose(file);
    wolf->player->weapon = find_inventory_weapon(&wolf->game->inv, save.type);
    apply_weapon_data(wolf->player->weapon, &save);
    reset_loaded_game(wolf);
    return 0;
}
