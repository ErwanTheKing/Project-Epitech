/*
** EPITECH PROJECT, 2026
** stage
** File description:
** reset network notifications
*/

#include "../include/wolf3d.h"
#include <time.h>

void notify_game_reset(wolf_t *wolf)
{
    network_packet_t pkt;

    if (!wolf->connected || wolf->net.player_id == MAX_PLAYERS)
        return;
    if (wolf->map_seed == 0)
        wolf->map_seed = (uint32_t)time(NULL);
    memset(&pkt, 0, sizeof(pkt));
    pkt.type = PKT_GAME_STATE;
    pkt.timestamp = wolf->map_seed;
    pkt.data[0] = 'R';
    client_send_packet(&wolf->net, &pkt);
}

void notify_next_round(wolf_t *wolf)
{
    network_packet_t pkt;

    if (!wolf->connected || wolf->net.player_id == MAX_PLAYERS)
        return;
    if (wolf->map_seed == 0)
        wolf->map_seed = (uint32_t)time(NULL);
    memset(&pkt, 0, sizeof(pkt));
    pkt.type = PKT_GAME_STATE;
    pkt.timestamp = wolf->map_seed;
    pkt.data[0] = 'N';
    client_send_packet(&wolf->net, &pkt);
}

void notify_game_card(wolf_t *wolf)
{
    network_packet_t pkt;

    if (!wolf->connected || wolf->net.player_id == MAX_PLAYERS)
        return;
    memset(&pkt, 0, sizeof(pkt));
    pkt.type = PKT_GAME_STATE;
    pkt.data[0] = 'C';
    client_send_packet(&wolf->net, &pkt);
}

void notify_card_ready(wolf_t *wolf)
{
    network_packet_t pkt;

    if (!wolf->connected || wolf->net.player_id == MAX_PLAYERS)
        return;
    memset(&pkt, 0, sizeof(pkt));
    pkt.type = PKT_GAME_STATE;
    pkt.player_id = wolf->net.player_id;
    pkt.data[0] = 'K';
    client_send_packet(&wolf->net, &pkt);
}

void notify_player_dead(wolf_t *wolf)
{
    network_packet_t pkt;

    if (!wolf->connected || wolf->net.player_id == MAX_PLAYERS)
        return;
    memset(&pkt, 0, sizeof(pkt));
    pkt.type = PKT_GAME_STATE;
    pkt.data[0] = 'D';
    client_send_packet(&wolf->net, &pkt);
}
