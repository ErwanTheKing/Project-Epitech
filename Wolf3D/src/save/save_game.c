/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Save game state
*/

#include "../../include/wolf3d.h"
#include <sys/stat.h>

static int is_solo_game(wolf_t *wolf)
{
    return (!wolf->connected && wolf->net.player_id == MAX_PLAYERS);
}

static int build_save_path(char *path, size_t size, const char *name)
{
    int written = 0;

    if (!name || name[0] == '\0')
        return -1;
    written = snprintf(path, size, "saves/%s.sav", name);
    if (written < 0 || (size_t)written >= size)
        return -1;
    return 0;
}

static void save_last_name(const char *name)
{
    FILE *file = fopen("saves/last.txt", "w");

    if (!file)
        return;
    fprintf(file, "%s\n", name);
    fclose(file);
}

static void write_inventory_items(FILE *file, inv_t *inv)
{
    weapon_t *weapon = NULL;

    fprintf(file, "items 8\n");
    for (int i = 0; i < 8; i++) {
        if (!inv->item[i].data) {
            fprintf(file, "item %d -1 0 0 0 0\n", i);
            continue;
        }
        weapon = (weapon_t *)inv->item[i].data;
        fprintf(file, "item %d %d %d %d %d %.6f\n", i, inv->item[i].type,
            weapon->current_ammo, weapon->max_ammo, weapon->damage,
            weapon->attack_speed);
    }
}

static void write_inventory_slots(FILE *file, inv_t *inv)
{
    weapon_t *weapon = NULL;

    for (int i = 0; i < 8; i++) {
        if (!inv->slot[i].item.data) {
            fprintf(file, "slot %d -1 0 0 0 0\n", i);
            continue;
        }
        weapon = (weapon_t *)inv->slot[i].item.data;
        fprintf(file, "slot %d %d %d %d %d %.6f\n", i,
            inv->slot[i].item.type, weapon->current_ammo, weapon->max_ammo,
            weapon->damage, weapon->attack_speed);
    }
}

static void write_map(FILE *file, wall_t *wall)
{
    fprintf(file, "map\n");
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++)
            fprintf(file, "%d%c", wall->map[y][x],
                x + 1 == MAP_WIDTH ? '\n' : ' ');
    }
}

static void write_player(FILE *file, player_t *player)
{
    fprintf(file, "wolf3d_save 1\n");
    fprintf(file, "player %.6f %.6f %.6f %.6f %d %d %.6f %.6f %d\n",
        player->x, player->y, player->z, player->angle, player->hp,
        player->max_hp, player->speed, player->stamina, player->alive);
}

static void write_weapon(FILE *file, weapon_t *weapon)
{
    if (!weapon) {
        fprintf(file, "weapon -1 0 0 0 0.000000\n");
        return;
    }
    fprintf(file, "weapon %d %d %d %d %.6f\n", weapon->type,
        weapon->current_ammo, weapon->max_ammo, weapon->damage,
        weapon->attack_speed);
}

static void write_save_file(FILE *file, wolf_t *wolf)
{
    write_player(file, wolf->player);
    write_weapon(file, wolf->player->weapon);
    write_inventory_items(file, &wolf->game->inv);
    write_inventory_slots(file, &wolf->game->inv);
    write_map(file, wolf->game->wall);
    save_write_entities(file, wolf);
}

int save_game(wolf_t *wolf, const char *name)
{
    FILE *file = NULL;
    char path[SAVE_PATH_MAX];

    if (!is_solo_game(wolf) || build_save_path(path, sizeof(path), name) < 0)
        return -1;
    mkdir("saves", 0755);
    file = fopen(path, "w");
    if (!file)
        return -1;
    write_save_file(file, wolf);
    fclose(file);
    save_last_name(name);
    return 0;
}
