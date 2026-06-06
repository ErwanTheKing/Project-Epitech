/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Inventory controller selection helpers
*/

#include "../../include/wolf3d.h"

static int selected_slot(player_t *player, inv_t *inv)
{
    for (int i = 0; i < 8; i++)
        if (inv->slot[i].selected)
            return i;
    for (int i = 0; i < 8; i++)
        if (inv->slot[i].item.data == player->weapon)
            return i;
    return 0;
}

static void select_inventory_slot(inv_t *inv, int index)
{
    if (index < 0)
        index = 7;
    if (index > 7)
        index = 0;
    for (int i = 0; i < 8; i++)
        inv->slot[i].selected = sfFalse;
    inv->slot[index].selected = sfTrue;
}

void move_inventory_slot(wolf_t *wolf, sfEvent event, inv_t *inv)
{
    int index = selected_slot(wolf->player, inv);

    if (joystick_menu_left(event) || joystick_slot_previous(wolf->settings,
            event))
        select_inventory_slot(inv, index - 1);
    if (joystick_menu_right(event) || joystick_slot_next(wolf->settings,
            event))
        select_inventory_slot(inv, index + 1);
    if (joystick_menu_up(event))
        select_inventory_slot(inv, index - 4);
    if (joystick_menu_down(event))
        select_inventory_slot(inv, index + 4);
}

void use_moved_inventory_slot(wolf_t *wolf, sfEvent event, inv_t *inv)
{
    int index = selected_slot(wolf->player, inv);
    int direction = 0;

    if (joystick_slot_previous(wolf->settings, event))
        direction = -1;
    if (joystick_slot_next(wolf->settings, event))
        direction = 1;
    if (direction == 0)
        return;
    for (int i = 0; i < 8; i++) {
        index = (index + direction + 8) % 8;
        if (!inv->slot[index].item.data)
            continue;
        select_inventory_slot(inv, index);
        return use_inventory_item(wolf->player, &inv->slot[index]);
    }
}
