/*
** EPITECH PROJECT, 2026
** main
** File description:
** main
*/

#include "../../include/wolf3d.h"

static char *create_heal_hint(wolf_t *wolf)
{
    const char *key = key_to_string(wolf->settings->key_bindings[CTRL_HEAL]);
    int len = snprintf(NULL, 0, "Press %s to use heal", key) + 1;
    char *hint = malloc(sizeof(char) * len);

    if (!hint)
        return NULL;
    snprintf(hint, len, "Press %s to use heal", key);
    return hint;
}

static void draw_heal_hint(wolf_t *wolf)
{
    sfText *text = sfText_create();
    char *hint = create_heal_hint(wolf);

    if (!text || !hint) {
        if (text)
            sfText_destroy(text);
        free(hint);
        return;
    }
    sfText_setFont(text, wolf->data->font);
    sfText_setString(text, hint);
    sfText_setPosition(text, (sfVector2f){wolf->window_data->width / 2.5,
            wolf->window_data->height / 2});
    sfRenderWindow_drawText(wolf->window_data->window, text, NULL);
    free(hint);
    sfText_destroy(text);
}

static sfBool pick_heal(wolf_t *wolf, player_t *player, player_t *heal)
{
    if (!isactiondown(wolf->settings, CTRL_HEAL))
        return sfFalse;
    player->hp += 25;
    if (player->hp > player->max_hp)
        player->hp = player->max_hp;
    heal->alive = sfFalse;
    if (network_is_host(wolf))
        network_send_entity_state(wolf, HEAL_T, heal->net_id, heal);
    else
        network_send_heal_pickup(wolf, heal->net_id);
    return sfTrue;
}

static sfBool is_in_range(wolf_t *wolf, player_t *player, player_t *heal)
{
    float dx = player->x - heal->x;
    float dy = player->y - heal->y;

    if (sqrtf(dx * dx + dy * dy) > 0.6f)
        return sfFalse;
    draw_heal_hint(wolf);
    return pick_heal(wolf, player, heal);
}

void use_heal(wolf_t *wolf, player_t *player)
{
    player_t *heal = NULL;

    for (list_t *curr = wolf->list[GAME][HEAL]; curr; curr = curr->next) {
        heal = (player_t *)curr->data;
        if (heal->alive == sfFalse)
            continue;
        if (is_in_range(wolf, player, heal))
            return;
    }
}
