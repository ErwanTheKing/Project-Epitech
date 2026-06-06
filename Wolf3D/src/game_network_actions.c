/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** network action packets
*/

#include "../include/wolf3d.h"

void network_send_player_damage(wolf_t *wolf, uint32_t target_id, int damage)
{
    network_packet_t pkt;

    if (!network_is_host(wolf))
        return;
    memset(&pkt, 0, sizeof(pkt));
    pkt.type = PKT_PLAYER_DAMAGE;
    pkt.player_id = wolf->net.player_id;
    pkt.data[0] = (uint8_t)target_id;
    memcpy(&pkt.data[4], &damage, sizeof(damage));
    client_send_packet(&wolf->net, &pkt);
}

void network_send_heal_pickup(wolf_t *wolf, int entity_id)
{
    network_packet_t pkt;

    if (!wolf->connected || network_is_host(wolf))
        return;
    memset(&pkt, 0, sizeof(pkt));
    pkt.type = PKT_ENTITY_DAMAGE;
    pkt.timestamp = entity_id;
    pkt.data[0] = (uint8_t)HEAL_T;
    client_send_packet(&wolf->net, &pkt);
}
