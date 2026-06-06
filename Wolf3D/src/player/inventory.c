/*
** EPITECH PROJECT, 2026
** weapon
** File description:
** weapon
*/

#include "../../include/wolf3d.h"

static void manage_inventory(window_t *win, inv_t *inv)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win->window);
    sfFloatRect rect;

    for (int i = 0; i < 8; i++)
        inv->slot[i].selected = sfFalse;
    for (int i = 1; i < 9; i++) {
        rect = sfRectangleShape_getGlobalBounds(inv->rect[i]);
        if (!sfFloatRect_contains(&rect, pos.x, pos.y))
            continue;
        inv->slot[i - 1].selected = sfTrue;
    }
}

static void use_bandage(player_t *player, slot_t *slot)
{
    player->hp += 60;
    if (player->hp > player->max_hp)
        player->hp = player->max_hp;
    slot->item.data = NULL;
    slot->selected = sfFalse;
}

void use_inventory_item(player_t *player, slot_t *slot)
{
    if (!slot->item.data)
        return;
    if (slot->item.type == BANDAGE)
        return use_bandage(player, slot);
    player->weapon = (weapon_t *)slot->item.data;
    player->weapon->rect.left = 0;
    sfSprite_setTextureRect(player->weapon->entity->sprite,
        player->weapon->rect);
    slot->selected = sfFalse;
}

static void use_item_key(wolf_t *wolf, sfEvent event, player_t *player,
    inv_t *inv)
{
    for (int i = 0; i < 8; i++) {
        if (!isactionpressed(wolf->settings, CTRL_SLOT_1 + i, event))
            continue;
        return use_inventory_item(player, &inv->slot[i]);
    }
}

static void equip_item(wolf_t *wolf, player_t *player, inv_t *inv)
{
    if (!isactiondown(wolf->settings, CTRL_EQUIP))
        return;
    for (int i = 0; i < 8; i++) {
        if (!inv->slot[i].selected)
            continue;
        return use_inventory_item(player, &inv->slot[i]);
    }
}

void check_inventory(wolf_t *wolf, inv_t *inv)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        manage_inventory(wolf->window_data, inv);
    equip_item(wolf, wolf->player, inv);
    draw_selected_item(wolf, inv);
}

void draw_inventory_item(window_t *win, inv_t *inv, int i)
{
    sfVector2f pos;
    sfSprite *sprite;
    sfFloatRect bounds;
    sfVector2f origin;

    if (!inv->slot[i - 1].item.data)
        return;
    sprite = inv->slot[i - 1].item.entity->sprite;
    pos = sfRectangleShape_getPosition(inv->rect[i]);
    bounds = sfSprite_getLocalBounds(sprite);
    origin = (sfVector2f){bounds.width / 2, bounds.height / 2};
    sfSprite_setOrigin(sprite, origin);
    sfSprite_setPosition(sprite, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_drawSprite(win->window, sprite, NULL);
}

static void draw_equip_hint(wolf_t *wolf, inv_t *inv)
{
    char hint[64];
    window_t *win = wolf->window_data;

    snprintf(hint, sizeof(hint), "Press %s or slot keys to equip",
        key_to_string(wolf->settings->key_bindings[CTRL_EQUIP]));
    sfText_setString(inv->text, hint);
    sfText_setPosition(inv->text,
        (sfVector2f){win->width / 2, win->height / 1.63});
    sfRenderWindow_drawText(win->window, inv->text, NULL);
}

void draw_selected_item(wolf_t *wolf, inv_t *inv)
{
    char *str = NULL;
    window_t *win = wolf->window_data;

    for (int i = 0; i < 8; i++) {
        if (!inv->slot[i].selected)
            continue;
        str = inv->slot[i].item.name;
    }
    if (!str)
        return;
    sfText_setString(inv->text, str);
    sfText_setCharacterSize(inv->text, 30);
    sfText_setPosition(inv->text,
        (sfVector2f){win->width / 3.1, win->height / 1.63});
    sfRenderWindow_drawText(win->window, inv->text, NULL);
    draw_equip_hint(wolf, inv);
}

void open_inventory(wolf_t *wolf, sfEvent event, inv_t *inv)
{
    if (isactionpressed(wolf->settings, CTRL_INVENTORY, event)) {
        inv->open = !inv->open;
        sfRenderWindow_setMouseCursorVisible(wolf->window_data->window,
            inv->open ? sfTrue : sfFalse);
        sfMouse_setPositionRenderWindow((sfVector2i){wolf->window_data->width
                / 2, wolf->window_data->height / 2}, wolf->window_data->window);
        for (int i = 0; i < 8; i++)
            inv->slot[i].selected = sfFalse;
    }
    use_item_key(wolf, event, wolf->player, inv);
    if (!inv->open)
        use_moved_inventory_slot(wolf, event, inv);
    if (inv->open)
        move_inventory_slot(wolf, event, inv);
    if (inv->open)
        check_inventory(wolf, inv);
}
