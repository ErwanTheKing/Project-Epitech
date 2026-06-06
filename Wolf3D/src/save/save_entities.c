/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Save/load entities
*/

#include "../../include/wolf3d.h"

static int count_list(list_t *list)
{
    int count = 0;

    for (list_t *curr = list; curr; curr = curr->next)
        count++;
    return count;
}

static void write_entity(FILE *file, player_t *entity)
{
    fprintf(file, "entity %d %.6f %.6f %.6f %.6f %d %d %d %.6f %.6f\n",
        entity->type, entity->x, entity->y, entity->z, entity->angle,
        entity->hp, entity->max_hp, entity->alive, entity->path_target_x,
        entity->path_target_y);
}

void save_write_entities(FILE *file, wolf_t *wolf)
{
    int count = count_list(wolf->list[GAME][MONSTER]) +
        count_list(wolf->list[GAME][GARBAGE]) +
        count_list(wolf->list[GAME][HEAL]);

    fprintf(file, "entities %d\n", count);
    for (list_t *curr = wolf->list[GAME][MONSTER]; curr; curr = curr->next)
        write_entity(file, (player_t *)curr->data);
    for (list_t *curr = wolf->list[GAME][GARBAGE]; curr; curr = curr->next)
        write_entity(file, (player_t *)curr->data);
    for (list_t *curr = wolf->list[GAME][HEAL]; curr; curr = curr->next)
        write_entity(file, (player_t *)curr->data);
}

static void free_entity_list(list_t **list)
{
    list_t *next = NULL;
    player_t *player = NULL;

    for (list_t *curr = *list; curr; curr = next) {
        next = curr->next;
        player = (player_t *)curr->data;
        destroy_player(player);
        free(curr);
    }
    *list = NULL;
}

static void free_loaded_entity_list(wolf_t *wolf)
{
    free_entity_list(&wolf->list[GAME][MONSTER]);
    free_entity_list(&wolf->list[GAME][GARBAGE]);
    free_entity_list(&wolf->list[GAME][HEAL]);
}

static int read_entity_line(FILE *file, player_t *entity)
{
    int type = 0;
    int alive = 0;

    if (fscanf(file, " entity %d %f %f %f %f %d %d %d %f %f\n",
            &type, &entity->x, &entity->y, &entity->z, &entity->angle,
            &entity->hp, &entity->max_hp, &alive, &entity->path_target_x,
            &entity->path_target_y) != 10)
        return -1;
    entity->type = type;
    entity->alive = alive ? sfTrue : sfFalse;
    entity->running = sfFalse;
    return 0;
}

static int push_loaded_entity(wolf_t *wolf, FILE *file)
{
    player_t *entity = init_player(wolf->window_data, ENNEMY,
        &(sfVector2f){1.5f, 1.5f});

    if (!entity)
        return -1;
    if (read_entity_line(file, entity) < 0) {
        destroy_player(entity);
        return -1;
    }
    if (entity->type == GARBAGE_T)
        push_front(&wolf->list[GAME][GARBAGE], entity);
    else if (entity->type == HEAL_T)
        push_front(&wolf->list[GAME][HEAL], entity);
    else
        push_front(&wolf->list[GAME][MONSTER], entity);
    return 0;
}

int save_read_entities(FILE *file, wolf_t *wolf)
{
    int count = 0;

    if (fscanf(file, " entities %d\n", &count) != 1)
        return 0;
    free_loaded_entity_list(wolf);
    for (int i = 0; i < count; i++)
        if (push_loaded_entity(wolf, file) < 0) {
            free_loaded_entity_list(wolf);
            return -1;
        }
    return 0;
}
