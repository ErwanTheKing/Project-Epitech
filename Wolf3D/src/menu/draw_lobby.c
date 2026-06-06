/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** draw_lobby
*/

#include "../../include/wolf3d.h"

static sfText *new_centered_text(wolf_t *wolf,
    const char *str, float y, unsigned int size)
{
    sfText *t = sfText_create();
    sfFloatRect bounds;

    if (!t)
        return NULL;
    sfText_setFont(t, wolf->data->font);
    sfText_setString(t, str);
    sfText_setCharacterSize(t, size);
    sfText_setColor(t, sfWhite);
    sfText_setOutlineColor(t, sfBlack);
    sfText_setOutlineThickness(t, 1);
    bounds = sfText_getGlobalBounds(t);
    sfText_setPosition(t,
        (sfVector2f){(wolf->window_data->width - bounds.width) / 2.f, y});
    return t;
}

static void draw_and_free(wolf_t *wolf, sfText *t)
{
    if (!t)
        return;
    sfRenderWindow_drawText(wolf->window_data->window, t, NULL);
    sfText_destroy(t);
}

static void draw_lobby_ip_error(wolf_t *wolf, float cy)
{
    sfText *t = new_centered_text(wolf,
        "Connexion echouee - verifiez l'IP", cy, 30);

    if (t)
        sfText_setColor(t, sfRed);
    draw_and_free(wolf, t);
}

static float draw_ip_input(wolf_t *wolf, float cy)
{
    sfText *t;
    char ip_display[18];

    draw_and_free(wolf,
        new_centered_text(wolf, "Entrez l'IP du serveur :", cy, 36));
    cy += 80;
    snprintf(ip_display, sizeof(ip_display), "%.*s_",
        wolf->lobby.ip_len, wolf->lobby.ip);
    t = new_centered_text(wolf, ip_display, cy, 48);
    if (t)
        sfText_setColor(t, sfYellow);
    draw_and_free(wolf, t);
    if (!wolf->lobby.connect_error)
        return cy;
    cy += 90;
    draw_lobby_ip_error(wolf, cy);
    return cy;
}

static void draw_lobby_ip_phase(wolf_t *wolf)
{
    float cy = wolf->window_data->height * 0.25f;

    draw_and_free(wolf, new_centered_text(wolf,
            "MULTIJOUEUR", cy, 60));
    cy += 140;
    cy = draw_ip_input(wolf, cy);
    cy += 110;
    draw_and_free(wolf, new_centered_text(wolf,
            "ENTREE pour confirmer  /  ECHAP pour retour", cy, 26));
}

static float draw_player_list(wolf_t *wolf, float cy)
{
    char buf[64];

    for (int i = 0; i < wolf->lobby.nb_connected; i++) {
        snprintf(buf, sizeof(buf), "Joueur %d%s", i,
            (i == (int)wolf->net.player_id) ? "  (vous)" : "");
        draw_and_free(wolf, new_centered_text(wolf, buf, cy, 30));
        cy += 55;
    }
    return cy;
}

static void draw_lobby_action_line(wolf_t *wolf, const char *msg,
    float cy, const sfColor *color)
{
    sfText *t;

    t = new_centered_text(wolf, msg, cy, 34);
    if (t)
        sfText_setColor(t, *color);
    draw_and_free(wolf, t);
}

static void draw_lobby_actions(wolf_t *wolf, float cy)
{
    if (wolf->lobby.is_host)
        draw_lobby_action_line(wolf, "ENTREE pour lancer la partie",
            cy, &sfGreen);
    else
        draw_lobby_action_line(wolf,
            "En attente que l'hote lance la partie...",
            cy, &(sfColor){160, 160, 160, 255});
    cy += 70;
    draw_lobby_action_line(wolf, "ECHAP pour retour",
        cy, &(sfColor){160, 160, 160, 255});
}

static void draw_lobby_wait_phase(wolf_t *wolf)
{
    char buf[64];
    float cy = wolf->window_data->height * 0.15f;

    draw_and_free(wolf, new_centered_text(wolf, "LOBBY", cy, 60));
    cy += 130;
    snprintf(buf, sizeof(buf), "Joueurs connectes : %d / %d",
        wolf->lobby.nb_connected, MAX_PLAYERS);
    draw_and_free(wolf, new_centered_text(wolf, buf, cy, 36));
    cy += 80;
    cy = draw_player_list(wolf, cy);
    cy += 30;
    draw_lobby_actions(wolf, cy);
}

void draw_lobby(wolf_t *wolf)
{
    if (wolf->lobby.phase == 0)
        draw_lobby_ip_phase(wolf);
    else
        draw_lobby_wait_phase(wolf);
}
