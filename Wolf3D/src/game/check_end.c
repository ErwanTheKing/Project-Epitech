/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Check end of game when no more monsters/garbage
*/

#include "../../include/wolf3d.h"

static int count_alive_entities(list_t *list)
{
    int count = 0;
    player_t *entity;

    for (list_t *curr = list; curr; curr = curr->next) {
        entity = (player_t *)curr->data;
        if (entity && entity->alive)
            count++;
    }
    return count;
}

void check_game_finish(wolf_t *wolf)
{
    int count = count_alive_entities(wolf->list[GAME][MONSTER]) +
        count_alive_entities(wolf->list[GAME][GARBAGE]);

    if (wolf->connected && !network_is_host(wolf))
        return;
    if (count == 0) {
        wolf->stage++;
        printf("Stage complete! Next stage: %d (map %dx%d)\n",
            wolf->stage, (wolf->stage == 0) ? 24 : 6,
            (wolf->stage == 0) ? 24 : 6);
        fflush(stdout);
        wolf->game->state = CARD;
        wolf->state = GAME;
        memset(wolf->card_ready, 0, sizeof(wolf->card_ready));
        init_card(wolf, &wolf->game->inter);
        if (network_is_host(wolf))
            notify_game_card(wolf);
    }
}
