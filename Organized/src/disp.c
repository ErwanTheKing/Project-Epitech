/*
** EPITECH PROJECT, 2025
** organized
** File description:
** The disp.c
*/
/**
 * @file disp.c
 * @brief The disp.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

int disp(void *data)
{
    hardware_t *infos = NULL;
    char *id = NULL;

    for (linked_list_t *tmp = *(linked_list_t **)data; tmp->next != NULL;
        tmp = tmp->next) {
        infos = tmp->data;
        id = my_nbr_to_str(infos->id);
        write(1, infos->type, my_strlen(infos->type));
        write(1, " n°", 4);
        write(1, id, my_strlen(id));
        write(1, " - \"", 4);
        write(1, infos->name, my_strlen(infos->name));
        write(1, "\"\n", 2);
        free(id);
    }
    return SUCCESS;
}
