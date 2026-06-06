/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** wolf3d
*/

#ifndef WOLF_H
    #define WOLF_H

    #include "constants.h"
    #include "types.h"
    #include "init.h"
    #include "player.h"
    #include "weapon.h"
    #include "render.h"
    #include "menu.h"
    #include "entity.h"
    #include "settings.h"
    #include "ui.h"
    #include "utils.h"
    #include "stage.h"
    #include "save.h"
    #include "stage_card.h"
int program(sfRenderWindow *window, sfEvent event, wolf_t *wolf);
void network_update(wolf_t *wolf, sfClock *send_clock);
int network_is_host(wolf_t *wolf);
player_t *network_get_entity_by_id(wolf_t *wolf, p_type_t type, int net_id);
player_t *network_get_or_create_entity(wolf_t *wolf, p_type_t type,
    int net_id, sfVector2f *pos);
void network_send_entity_state(wolf_t *wolf, p_type_t type,
    int entity_index, player_t *entity);
void network_send_player_damage(wolf_t *wolf, uint32_t target_id, int damage);
void network_send_heal_pickup(wolf_t *wolf, int entity_id);
void network_send_entity_states(wolf_t *wolf);
void network_handle_start_packet(wolf_t *wolf, network_packet_t *pkt);
void network_handle_state_packet(wolf_t *wolf, network_packet_t *pkt);

#endif
