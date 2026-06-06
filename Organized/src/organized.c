/*
** EPITECH PROJECT, 2025
** organized
** File description:
** organized
*/

#include "../include/includes.h"

int organized(void)
{
    infos_t *org = malloc(sizeof(infos_t));

    org->hardware = NULL;
    if (!org)
        return ERROR;
    org->id = 0;
    return workshop_shell(&org);
}
