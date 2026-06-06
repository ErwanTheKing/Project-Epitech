/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** lobby
*/

#include "../../include/wolf3d.h"
#include <time.h>

void back_to_newgame_menu(wolf_t *wolf)
{
    if (wolf->connected) {
        client_close(&wolf->net);
        wolf->connected = 0;
    }
    memset(&wolf->lobby, 0, sizeof(wolf->lobby));
    wolf->net.player_id = MAX_PLAYERS;
    wolf->state = NEWGAME_MENU;
    wolf->menu_state = MULTI;
}

static void try_connect(wolf_t *wolf)
{
    wolf->lobby.ip[wolf->lobby.ip_len] = '\0';
    if (client_init(&wolf->net, wolf->lobby.ip, PORT) < 0) {
        wolf->lobby.connect_error = 1;
        return;
    }
    wolf->connected = 1;
    wolf->lobby.connect_error = 0;
    wolf->lobby.phase = 1;
}

static void handle_ip_text(wolf_t *wolf, sfEvent event)
{
    uint32_t c;

    if (event.type != sfEvtTextEntered)
        return;
    c = event.text.unicode;
    if (c < 32 || wolf->lobby.ip_len >= 15)
        return;
    if ((c >= '0' && c <= '9') || c == '.') {
        wolf->lobby.ip[wolf->lobby.ip_len] = (char)c;
        wolf->lobby.ip_len++;
    }
}

static void handle_ip_keys(wolf_t *wolf, sfEvent event)
{
    if (event.type != sfEvtKeyPressed)
        return;
    if (event.key.code == sfKeyBackspace && wolf->lobby.ip_len > 0) {
        wolf->lobby.ip_len--;
        wolf->lobby.connect_error = 0;
    }
    if (event.key.code == sfKeyReturn && wolf->lobby.ip_len > 0)
        try_connect(wolf);
}

static void handle_waiting_keys(wolf_t *wolf, sfEvent event)
{
    network_packet_t pkt;
    window_t *win = wolf->window_data;

    if (event.type != sfEvtKeyPressed || event.key.code != sfKeyReturn)
        return;
    if (!wolf->lobby.is_host)
        return;
    sfMouse_setPositionRenderWindow((sfVector2i){win->width / 2,
            win->height / 2}, win->window);
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    wolf->score = 0;
    wolf->stage = 0;
    wolf->map_seed = (uint32_t)time(NULL);
    reset_game_run_seed(wolf, wolf->map_seed);
    memset(&pkt, 0, sizeof(pkt));
    pkt.type = PKT_GAME_START;
    pkt.player_id = wolf->net.player_id;
    pkt.timestamp = wolf->map_seed;
    client_send_packet(&wolf->net, &pkt);
    wolf->state = GAME;
}

void manage_lobby(wolf_t *wolf, sfEvent event)
{
    if (wolf->lobby.phase == 0) {
        handle_ip_text(wolf, event);
        handle_ip_keys(wolf, event);
    } else {
        handle_waiting_keys(wolf, event);
    }
}
