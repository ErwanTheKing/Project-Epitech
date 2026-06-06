/*
** EPITECH PROJECT, 2026
** ~/EpitechProjects/Wolf3d/src/settings
** File description:
** keys
*/

#include "wolf3d.h"

static const char *get_key_name(int id)
{
    const char *names[] = {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L",
        "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X",
        "Y", "Z", "NUM0", "NUM1", "NUM2", "NUM3", "NUM4", "NUM5",
        "NUM6", "NUM7", "NUM8", "NUM9", "ESCAPE", "LCTRL", "LSHIFT",
        "LALT", "LSYSTEM", "RCTRL", "RSHIFT", "RALT", "RSYSTEM",
        "MENU", "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA",
        "PERIOD", "QUOTE", "SLASH", "BACKSLASH", "TILDE", "EQUAL",
        "HYPHEN", "SPACE", "ENTER", "BACKSPACE", "TAB", "PAGEUP",
        "PAGEDOWN", "END", "HOME", "INSERT", "DELETE", "+", "-", "*",
        "/", "LEFT", "RIGHT", "UP", "DOWN", "NUMPAD0", "NUMPAD1",
        "NUMPAD2", "NUMPAD3", "NUMPAD4", "NUMPAD5", "NUMPAD6",
        "NUMPAD7", "NUMPAD8", "NUMPAD9", "F1", "F2", "F3", "F4",
        "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13",
        "F14", "F15", "PAUSE"
    };

    return names[id];
}

const char *key_to_string(sfKeyCode key)
{
    if (key >= 0 && key <= sfKeyPause)
        return get_key_name(key);
    return "UNKNOWN";
}

sfBool is_pause_key(settings_game_t *settings, sfEvent event)
{
    sfKeyCode pause_key = sfKeyEscape;

    if (event.type != sfEvtKeyPressed)
        return sfFalse;
    if (settings)
        pause_key = settings->key_bindings[CTRL_PAUSE];
    return event.key.code == sfKeyEscape || event.key.code == pause_key;
}
