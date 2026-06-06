/*
** EPITECH PROJECT, 2025
** organized
** File description:
** The add.c
*/
/**
 * @file add.c
 * @brief The add.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

hardware_t *add_hardware(char **args, infos_t *org, int type, int name)
{
    hardware_t *infos = malloc(sizeof(hardware_t));

    if (!infos)
        return NULL;
    infos->type = my_strdup(args[type]);
    infos->name = my_strdup(args[name]);
    infos->id = org->id;
    org->id++;
    return infos;
}

static void write_message(linked_list_t *new)
{
    hardware_t *infos = new->data;
    char *id = NULL;

    if (new->data) {
        id = my_nbr_to_str(infos->id);
        write(1, infos->type, my_strlen(infos->type));
        write(1, " n°", 4);
        write(1, id, my_strlen(id));
        write(1, " - \"", 4);
        write(1, infos->name, my_strlen(infos->name));
        write(1, "\" added.\n", 9);
    }
    free(id);
}

static int verif_type(char **args, int type)
{
    char *l_type[6] = {"ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE",
        NULL};
    int good_type = 0;
    char *str = my_strdup(args[type]);

    for (int i = 0; l_type[i] != NULL; i++) {
        if (my_strcmp(my_strupcase(str), l_type[i]) == 0) {
            good_type = 1;
            break;
        }
    }
    if (good_type == 0) {
        write(2, "The type is not good\n", 21);
        free(str);
        return ERROR;
    }
    free(str);
    return SUCCESS;
}

int add(void *data, char **args)
{
    linked_list_t *new = NULL;
    int type = 0;
    int name = 1;

    if (args[0] == NULL || args[1] == NULL)
        return ERROR;
    while (args[type] != NULL && args[name] != NULL) {
        new = malloc(sizeof(linked_list_t));
        if (!new)
            return ERROR;
        if (verif_type(args, type) == SUCCESS) {
            new->data = add_hardware(args, data, type, name);
            write_message(new);
            new->next = *(linked_list_t **)data;
            *(linked_list_t **)data = new;
        }
        type += 2;
        name += 2;
    }
    return SUCCESS;
}
