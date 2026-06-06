/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Save/load name input
*/

#include "../../include/wolf3d.h"

static int is_name_char(uint32_t c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') || c == '_' || c == '-');
}

void start_save_input(wolf_t *wolf, save_input_mode_t mode)
{
    memset(&wolf->save_input, 0, sizeof(wolf->save_input));
    wolf->save_input.mode = mode;
    if ((mode == SAVE_INPUT_SAVE || mode == SAVE_INPUT_LOAD) &&
        (wolf->connected || wolf->net.player_id != MAX_PLAYERS)) {
        snprintf(wolf->save_input.status, sizeof(wolf->save_input.status),
            "Sauvegardes disponibles seulement en solo");
        wolf->save_input.mode = SAVE_INPUT_NONE;
    }
}

static void confirm_save_input(wolf_t *wolf)
{
    int result = -1;

    if (wolf->save_input.mode == SAVE_INPUT_SAVE && wolf->save_input.len > 0)
        result = save_game(wolf, wolf->save_input.name);
    if (wolf->save_input.mode == SAVE_INPUT_LOAD)
        result = load_game(wolf, wolf->save_input.name);
    if (result == 0) {
        if (wolf->save_input.mode == SAVE_INPUT_SAVE)
            snprintf(wolf->save_input.status, sizeof(wolf->save_input.status),
                "Sauvegarde terminee");
        else
            wolf->save_input.status[0] = '\0';
        wolf->save_input.mode = SAVE_INPUT_NONE;
        return;
    }
    snprintf(wolf->save_input.status, sizeof(wolf->save_input.status),
        wolf->save_input.mode == SAVE_INPUT_SAVE ?
        "Nom invalide ou sauvegarde impossible" : "Sauvegarde introuvable");
}

static void handle_text(wolf_t *wolf, sfEvent event)
{
    uint32_t c;

    if (event.type != sfEvtTextEntered)
        return;
    c = event.text.unicode;
    if (!is_name_char(c) || wolf->save_input.len >= SAVE_NAME_MAX)
        return;
    wolf->save_input.name[wolf->save_input.len] = (char)c;
    wolf->save_input.len++;
    wolf->save_input.name[wolf->save_input.len] = '\0';
    wolf->save_input.status[0] = '\0';
}

static void handle_keys(wolf_t *wolf, sfEvent event)
{
    if (event.type != sfEvtKeyPressed)
        return;
    if (event.key.code == sfKeyEscape) {
        wolf->save_input.mode = SAVE_INPUT_NONE;
        return;
    }
    if (event.key.code == sfKeyBackspace && wolf->save_input.len > 0) {
        wolf->save_input.len--;
        wolf->save_input.name[wolf->save_input.len] = '\0';
        wolf->save_input.status[0] = '\0';
    }
    if (event.key.code == sfKeyEnter || event.key.code == sfKeyReturn)
        confirm_save_input(wolf);
}

sfBool handle_save_input(wolf_t *wolf, sfEvent event)
{
    if (wolf->save_input.mode == SAVE_INPUT_NONE)
        return sfFalse;
    handle_text(wolf, event);
    handle_keys(wolf, event);
    return sfTrue;
}
