/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The free_env.c
*/
/**
 * @file free_env.c
 * @brief The free_env.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/shell.h"
#include <stdlib.h>

void free_env(env_t **my_env)
{
    env_t *tmp = *my_env;
    env_t *next;

    if (!my_env || !*my_env)
        return;
    while (tmp) {
        next = tmp->next;
        free(tmp->data);
        free(tmp);
        tmp = next;
    }
    *my_env = NULL;
}
