/*
** EPITECH PROJECT, 2026
** G-ING-200-NCE-2-1-myworld-1
** File description:
** The settings_event.c
*/
/**
 * @file settings_event.c
 * @brief The settings_event.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <string.h>

#include "../../lib/my/headers/myworld.h"

static void exec_write_num(world_t *world, textbox_t *box)
{
    if (world->event.text.unicode == 8 &&
        strlen(box->input) > 0) {
        box->input[strlen(box->input) - 1] = '\0';
    } else if (world->event.text.unicode >= '0' &&
        world->event.text.unicode <= '9' &&
        strlen(box->input) < 3) {
        box->length = strlen(box->input);
        box->input[box->length] = (char)world->event.text.unicode;
        box->input[box->length + 1] = '\0';
    }
}

static void exec_write(world_t *world, textbox_t *box)
{
    if (world->event.text.unicode == 8 &&
        strlen(box->input) > 0) {
        box->input[strlen(box->input) - 1] = '\0';
    } else if (((world->event.text.unicode >= 'a' &&
                world->event.text.unicode <= 'z') ||
            (world->event.text.unicode >= 'A' &&
                world->event.text.unicode <= 'Z')) &&
        strlen(box->input) < 20) {
        box->length = strlen(box->input);
        box->input[box->length] = (char)world->event.text.unicode;
        box->input[box->length + 1] = '\0';
    }
}

static void write_in_box_num(world_t *world, textbox_t *box, float x, float y)
{
    sfFloatRect size;

    if (box->selected == 1) {
        sfRectangleShape_setOutlineColor(box->rectangle, sfYellow);
        if (world->event.type == sfEvtTextEntered) {
            exec_write_num(world, box);
            sfText_setString(box->text, box->input);
            size = sfText_getLocalBounds(box->text);
            sfText_setOrigin(box->text,
                (sfVector2f){
                    size.left + size.width / 2.f,
                    size.top + size.height / 2.f});
            sfText_setPosition(box->text,
                (sfVector2f){world->mode.width / x,
                    world->mode.height / y});
        }
    } else {
        sfRectangleShape_setOutlineColor(box->rectangle,
            sfColor_fromRGB(165, 253, 254));
    }
}

static void write_in_box(world_t *world, textbox_t *box, float x, float y)
{
    sfFloatRect size;

    if (box->selected == 1) {
        sfRectangleShape_setOutlineColor(box->rectangle, sfYellow);
        if (world->event.type == sfEvtTextEntered) {
            exec_write(world, box);
            sfText_setString(box->text, box->input);
            size = sfText_getLocalBounds(box->text);
            sfText_setOrigin(box->text,
                (sfVector2f){
                    size.left + size.width / 2.f,
                    size.top + size.height / 2.f});
            sfText_setPosition(box->text,
                (sfVector2f){world->mode.width / x,
                    world->mode.height / y});
        }
    } else {
        sfRectangleShape_setOutlineColor(box->rectangle,
            sfColor_fromRGB(165, 253, 254));
    }
}

static void handle_maps(world_t *world)
{
    int max_up_down = world->choose.len - world->choose.count_map;

    if (max_up_down < 0)
        max_up_down = 0;
    if (world->event.type == sfEvtKeyPressed &&
        world->event.key.code == sfKeyDown) {
        if (world->choose.up_down < max_up_down)
            world->choose.up_down++;
    }
    if (world->event.type == sfEvtKeyPressed &&
        world->event.key.code == sfKeyUp) {
        if (world->choose.up_down > 0)
            world->choose.up_down--;
    }
}

static void exec_button(world_t *world)
{
    if (world->event.type == sfEvtKeyPressed
        && sfKeyboard_isKeyPressed(sfKeyEscape)) {
        world->st_game = MAIN;
    }
    if (world->event.type == sfEvtMouseButtonPressed
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        click_back_c(world);
        click_size(world);
        click_create(world);
        if (world->choose.size == SIZE0) {
            click_box(world, world->choose.size_x);
            click_box(world, world->choose.size_y);
        }
        click_box(world, world->choose.name);
        click_load_map(world->choose.maps, world);
        click_load(world);
    }
    write_in_box_num(world, world->choose.size_x, 2.9, 1.65);
    write_in_box_num(world, world->choose.size_y, 2.5, 1.65);
    write_in_box(world, world->choose.name, 2.8, 2.75);
}

void event_choose(world_t *world)
{
    handle_maps(world);
    exec_button(world);
}
