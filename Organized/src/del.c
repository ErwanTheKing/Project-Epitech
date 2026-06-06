/*
** EPITECH PROJECT, 2025
** organized
** File description:
** The del.c
*/
/**
 * @file del.c
 * @brief The del.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

static void write_message(hardware_t *infos)
{
    char *id = NULL;

    if (infos) {
        id = my_nbr_to_str(infos->id);
        write(1, infos->type, my_strlen(infos->type));
        write(1, " n°", 4);
        write(1, id, my_strlen(id));
        write(1, " - \"", 4);
        write(1, infos->name, my_strlen(infos->name));
        write(1, "\" deleted.\n", 11);
    }
    free(id);
}

static int first(linked_list_t *cur, linked_list_t **head, int find_id)
{
    hardware_t *infos = cur->data;

    if (infos->id == find_id) {
        *head = cur->next;
        free(cur);
        write_message(infos);
        return SUCCESS;
    }
    return ERROR;
}

static int not_first(linked_list_t *cur, linked_list_t *prev, int find_id)
{
    hardware_t *infos = NULL;

    while (cur != NULL) {
        infos = cur->data;
        if (infos != NULL && infos->id == find_id) {
            prev->next = cur->next;
            free(infos->name);
            free(infos->type);
            free(cur);
            write_message(infos);
            return SUCCESS;
        }
        cur = cur->next;
        prev = prev->next;
    }
    return ERROR;
}

static int search_id(void *data, char **args, int id)
{
    int find_id = my_getnbr(args[id]);
    linked_list_t *prev = *(linked_list_t **)data;
    linked_list_t *cur = prev;

    if (cur->data == NULL)
        return ERROR;
    if (first(cur, data, find_id) == SUCCESS)
        return SUCCESS;
    cur = cur->next;
    if (not_first(cur, prev, find_id) == SUCCESS)
        return SUCCESS;
    return ERROR;
}

int del(void *data, char **args)
{
    if (args[0] == NULL)
        return ERROR;
    for (int id = 0; args[id] != NULL; id++) {
        if (search_id(data, args, id) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}
