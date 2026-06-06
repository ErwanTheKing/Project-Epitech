/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Load saved inventory item stats
*/

#include "../../include/wolf3d.h"

static void apply_item_data(inv_t *inv, int index, weapon_save_t *save)
{
    weapon_t *weapon = NULL;

    if (save->type < GUN || save->type > BANDAGE)
        return;
    weapon = (weapon_t *)inv->item[index].data;
    if (!weapon)
        return;
    weapon->current_ammo = save->ammo;
    weapon->max_ammo = save->max_ammo;
    weapon->damage = save->damage;
    weapon->attack_speed = save->attack_speed;
}

static int read_item_line(FILE *file, inv_t *inv)
{
    int index = 0;
    weapon_save_t save = {0};

    if (fscanf(file, " item %d %d %d %d %d %f\n", &index, &save.type,
            &save.ammo, &save.max_ammo, &save.damage,
            &save.attack_speed) != 6)
        return -1;
    if (index < 0 || index >= 8)
        return -1;
    apply_item_data(inv, index, &save);
    return 0;
}

int save_read_inventory_items(FILE *file, inv_t *inv)
{
    int count = 0;
    long pos = ftell(file);

    if (fscanf(file, " items %d\n", &count) != 1) {
        fseek(file, pos, SEEK_SET);
        return 0;
    }
    for (int i = 0; i < count; i++)
        if (read_item_line(file, inv) < 0)
            return -1;
    return 0;
}
