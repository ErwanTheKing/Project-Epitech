/*
** EPITECH PROJECT, 2026
** stage
** File description:
** card action
*/

#include "../include/wolf3d.h"

static void render_card_scene(wolf_t *wolf, player_t *player, sfEvent event)
{
    (void)event;
    cast_all_rays(wolf, wolf->window_data, player, wolf->game);
    draw_other_entities(wolf, player);
    render_pixels(wolf, wolf->game, wolf->window_data);
}

static sfBool is_local_card_ready(wolf_t *wolf)
{
    if (!wolf->connected || wolf->net.player_id == MAX_PLAYERS)
        return sfFalse;
    return wolf->card_ready[wolf->net.player_id] ? sfTrue : sfFalse;
}

static void draw_card_waiting(wolf_t *wolf)
{
    sfText *text = sfText_create();
    sfFloatRect bounds;

    if (!text)
        return;
    sfText_setFont(text, wolf->data->font);
    sfText_setString(text, "WAITING FOR PLAYERS");
    sfText_setCharacterSize(text, wolf->window_data->height / 24);
    bounds = sfText_getLocalBounds(text);
    sfText_setOrigin(text, (sfVector2f){bounds.left + bounds.width / 2.0f,
            bounds.top + bounds.height / 2.0f});
    sfText_setPosition(text, (sfVector2f){wolf->window_data->width / 2.0f,
            wolf->window_data->height * 0.82f});
    sfRenderWindow_drawText(wolf->window_data->window, text, NULL);
    sfText_destroy(text);
}

void card_action(wolf_t *wolf, player_t *player, sfEvent event)
{
    intermission_t *inter = &wolf->game->inter;

    render_card_scene(wolf, player, event);
    rise_card(wolf, inter);
    draw_card(wolf, inter);
    if (is_local_card_ready(wolf))
        return draw_card_waiting(wolf);
    if (inter->done)
        handle_card_input(wolf, inter, event);
}
