/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The unsetenv.c
*/
/**
 * @file unsetenv.c
 * @brief The unsetenv.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <stdlib.h>

#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/shell.h"

static void delete_node(env_t **my_env, const char *variable)
{
    env_t *prev = NULL;
    env_t *cur = *my_env;
    int len = my_strlen(variable);

    while (cur) {
        if (my_strncmp(cur->data, variable, len - 1) != 0
            || cur->data[len] != '=') {
            prev = cur;
            cur = cur->next;
            continue;
        }
        if (prev)
            prev->next = cur->next;
        else
            *my_env = cur->next;
        free(cur->data);
        free(cur);
        return;
    }
}

int my_unsetenv(env_t **my_env, char *variable)
{
    if (!variable || !my_env)
        return FAILURE;
    delete_node(my_env, variable);
    return SUCCESS;
}
