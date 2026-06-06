/*
** EPITECH PROJECT, 2026
** stage
** File description:
** stage
*/

#include "../include/wolf3d.h"
#include <time.h>

static int create_card_type(void)
{
    int type = rand() % 100 + 1;

    if (type > 70)
        return HP;
    if (type > 40)
        return DAMAGE;
    if (type > 25)
        return SPEED;
    if (type > 10)
        return AS;
    return ITEM;
}

static void apply_to_card(card_t *card, char *string, double bonus)
{
    card->efficiency = bonus;
    sfText_setString(card->text, string);
}

void set_bonus(card_t *card, float bonus[5], int rd)
{
    if (rd > 50)
        return apply_to_card(card, "COMMON", bonus[0]);
    if (rd > 30)
        return apply_to_card(card, "UNCOMMON", bonus[1]);
    if (rd > 15)
        return apply_to_card(card, "RARE", bonus[2]);
    if (rd > 3)
        return apply_to_card(card, "EPIC", bonus[3]);
    apply_to_card(card, "LEGENDARY", bonus[4]);
}

static sfBool is_shotgun_unlocked(inv_t *inv)
{
    weapon_t *wp = NULL;

    for (int i = 0; i < 8; i++) {
        if (!inv->slot[i].item.data)
            continue;
        wp = (weapon_t *)inv->slot[i].item.data;
        if (wp->type == SHOTGUN)
            return sfTrue;
    }
    return sfFalse;
}

void item_card(card_t *card, int rd, inv_t *inv)
{
    if (rd > 40 || is_shotgun_unlocked(inv)) {
        apply_to_card(card, "BANDAGE", BANDAGE);
        return;
    }
    apply_to_card(card, "SHOTGUN", SHOTGUN);
}

void create_bonus(card_t *card, int rd, inv_t *inv)
{
    card->bonus = create_card_type();
    switch (card->bonus) {
        case HP:
            set_bonus(card, (float[]){10, 15, 25, 35, 50}, rd);
            break;
        case DAMAGE:
            set_bonus(card, (float[]){2, 4, 6, 10, 14}, rd);
            break;
        case SPEED:
            set_bonus(card, (float[]){2, 4, 6, 8, 10}, rd);
            break;
        case AS:
            set_bonus(card, (float[]){0.03, 0.05, 0.08, 0.1, 0.12}, rd);
            break;
        case ITEM:
            item_card(card, rd, inv);
    }
}

static void apply_damage(inv_t *inv, card_t *card)
{
    weapon_t *weapon = NULL;

    for (int i = 0; i < 8; i++) {
        if (!inv->item[i].data || (inv->item[i].type != SHOTGUN &&
                inv->item[i].type != GUN))
            continue;
        weapon = (weapon_t *)inv->item[i].data;
        if (weapon->type == GUN)
            weapon->damage += card->efficiency / 2;
        if (weapon->type == SHOTGUN)
            weapon->damage += card->efficiency;
    }
}

static void add_item_to_slot(inv_t *inv, int type)
{
    for (int i = 0; i < 8; i++) {
        if (inv->slot[i].item.data)
            continue;
        inv->slot[i].item = inv->item[type];
        return;
    }
}

static void reduce_attack_speed(inv_t *inv, double efficiency)
{
    weapon_t *weapon = NULL;

    for (int i = 0; i < 8; i++) {
        if (!inv->slot[i].item.data)
            continue;
        weapon = (weapon_t *)inv->slot[i].item.data;
        if (weapon->type != GUN && weapon->type != SHOTGUN)
            continue;
        weapon->attack_speed -= (float)efficiency;
        if (weapon->attack_speed < MIN_ATTACK_SPEED)
            weapon->attack_speed = MIN_ATTACK_SPEED;
    }
}

void apply_card(wolf_t *wolf, player_t *p, card_t *card)
{
    switch (card->bonus) {
        case SPEED:
            p->speed += card->efficiency;
            break;
        case HP:
            p->max_hp += card->efficiency;
            p->hp += card->efficiency;
            break;
        case DAMAGE:
            apply_damage(&wolf->game->inv, card);
            break;
        case ITEM:
            add_item_to_slot(&wolf->game->inv, card->efficiency);
            break;
        case AS:
            reduce_attack_speed(&wolf->game->inv, card->efficiency);
            break;
        default:
            break;
    }
}
