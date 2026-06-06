/*
** EPITECH PROJECT, 2026
** init
** File description:
** player
*/

#include "../../include/wolf3d.h"

void push_front(list_t **list, void *data)
{
    list_t *new_node = NULL;

    if (!list || !data)
        return;
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return;
    new_node->data = data;
    new_node->next = *list;
    *list = new_node;
}

void create_cursor(window_t *win, crosshair_t *ch)
{
    sfVector2f pos = {win->width / 2, win->height / 2};

    ch->cursor = create_entity("cursor", "assets/crosshair.png",
        &pos, &(sfVector2f){0.2, 0.2});
    ch->pos = pos;
}

window_t *init_window_data(wolf_t *wolf)
{
    window_t *window = malloc(sizeof(window_t));
    sfVideoMode resolution = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    uint32_t style = sfDefaultStyle;
    int has_settings = wolf && wolf->settings;

    if (!window)
        return NULL;
    if (has_settings)
        resolution = wolf->settings->resolution;
    style = has_settings ? sfClose : sfDefaultStyle;
    window->width = has_settings ? wolf->settings->resolution.width
        : WINDOW_WIDTH;
    window->height = has_settings ? wolf->settings->resolution.height
        : WINDOW_HEIGHT;
    window->window = sfRenderWindow_create(resolution, "Wolf3D", style, NULL);
    if (!window->window) {
        free(window);
        return NULL;
    }
    return window;
}

data_t *init_wolf_data(void)
{
    data_t *data = calloc(1, sizeof(data_t));

    if (!data)
        return NULL;
    data->font = sfFont_createFromFile("assets/font.ttf");
    if (!data->font) {
        free(data);
        return NULL;
    }
    return data;
}

static int init_wolf_player_data(wolf_t *wolf)
{
    if (!wolf)
        return -1;
    wolf->window_data = init_window_data(wolf);
    wolf->data = init_wolf_data();
    if (!wolf->window_data || !wolf->data)
        return -1;
    wolf->player = init_player(wolf->window_data, PLAYER,
        &(sfVector2f){1.5, 1.5});
    if (!wolf->player)
        return -1;
    return 0;
}

static void init_settings(wolf_t *wolf)
{
    init_settings_entities(wolf, wolf->window_data);
    init_settings_buttons(wolf, wolf->window_data);
    init_graphics(wolf, wolf->window_data);
    init_audio(wolf, wolf->window_data);
    init_gameplay(wolf, wolf->window_data);
    init_controls(wolf, wolf->window_data);
    init_controller_controls(wolf, wolf->window_data);
    init_graphics_params(wolf->settings, wolf);
}

static int init_wolf_game_data(wolf_t *wolf)
{
    init_menu_entities(wolf, wolf->window_data);
    init_menu_text(wolf, wolf->window_data);
    init_settings(wolf);
    init_pause_entities(wolf, wolf->window_data);
    init_pause_buttons(wolf, wolf->window_data);
    wolf->game = init_game(wolf->window_data);
    if (!wolf->game)
        return -1;
    create_cursor(wolf->window_data, &wolf->game->crosshair);
    wolf->game->wall->pixel = malloc(wolf->window_data->height *
        wolf->window_data->width * 4);
    wolf->game->zbuffer = malloc(wolf->window_data->width * sizeof(float));
    if (!wolf->game->wall->pixel || !wolf->game->zbuffer)
        return -1;
    init_hud(&wolf->game->hud, wolf->data->font);
    return 0;
}

static void init_state(wolf_t *wolf)
{
    wolf->state = MENU;
    wolf->return_state = MENU;
    wolf->menu_state = NEWGAME;
    wolf->settings_state = GRAPHICS;
    memset(&wolf->save_input, 0, sizeof(wolf->save_input));
    wolf->rebinding_control_action = -1;
    wolf->ignore_shot_until_release = sfFalse;
    wolf->flashlight_on = sfFalse;
    wolf->brightness_shader = NULL;
    wolf->brightness_shader_ready = sfFalse;
    wolf->fps_clock = NULL;
    wolf->fps_text = NULL;
    wolf->fps_frame_count = 0;
    wolf->fps_current = 0;
}

static int init_wolf_settings(wolf_t *wolf)
{
    memset(wolf->list, 0, sizeof(wolf->list));
    wolf->settings = init_settings_params();
    wolf->tmp_settings = init_settings_params();
    if (!wolf->settings || !wolf->tmp_settings)
        return -1;
    init_state(wolf);
    return 0;
}

wolf_t *init_wolf(void)
{
    wolf_t *wolf = calloc(1, sizeof(wolf_t));

    if (!wolf)
        return NULL;
    if (init_wolf_settings(wolf) < 0) {
        free_wolf(wolf);
        return NULL;
    }
    wolf->net.player_id = MAX_PLAYERS;
    if (init_wolf_player_data(wolf) < 0)
        return free_wolf(wolf), NULL;
    wolf->state = MENU;
    wolf->stage = 0;
    if (init_wolf_game_data(wolf) < 0 ||
        !create_inv(wolf->data, wolf->window_data, &wolf->game->inv) ||
        !init_sound_effect(wolf))
        return free_wolf(wolf), NULL;
    return wolf;
}
