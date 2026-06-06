/*
** EPITECH PROJECT, 2026
** weapon
** File description:
** weapon
*/

#include "../../../include/wolf3d.h"
#include <math.h>

void manage_shot(music_t *music, game_t *game, weapon_t *weapon)
{
    if ((sfMouse_isButtonPressed(sfMouseLeft) || joystick_shoot_down()) &&
        sfTime_asSeconds(
            sfClock_getElapsedTime(weapon->cd)) > weapon->attack_speed) {
        if (weapon->current_ammo <= 0)
            return;
        play_sound(music->sound[weapon->type]);
        game->has_shot = 1;
        sfClock_restart(weapon->cd);
        weapon->current_ammo -= 1;
    }
}

void use_weapon(music_t *music, game_t *game, weapon_t *weapon,
    settings_game_t *settings)
{
    if (!weapon)
        return;
    if (settings && !weapon->reloading &&
        isactiondown(settings, CTRL_RELOAD) &&
        sfTime_asSeconds(sfClock_getElapsedTime(weapon->cd)) >
        weapon->attack_speed && weapon->type == GUN) {
        weapon->reloading = 1;
        weapon->rect.left = 0;
        sfSprite_setTextureRect(weapon->entity->sprite, weapon->rect);
        sfClock_restart(weapon->cd);
    }
    if (weapon->reloading == 1)
        return;
    manage_shot(music, game, weapon);
}
