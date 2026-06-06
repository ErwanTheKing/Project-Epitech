/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The env.c
*/
/**
 * @file env.c
 * @brief The env.c
 * @author Erwan Lo Presti
 */

#include <stdlib.h>
#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/shell.h"

static void add_node(env_t **my_env, char *env)
{
    env_t *node;
    env_t *tmp;

    if (!env)
        return;
    node = malloc(sizeof(*node));
    if (!node)
        return;
    node->data = my_strdup(env, 0);
    if (!node->data) {
        free(node);
        return;
    }
    node->next = NULL;
    if (!*my_env) {
        *my_env = node;
        return;
    }
    for (tmp = *my_env; tmp->next; tmp = tmp->next);
    tmp->next = node;
}

env_t *create_env(char **env)
{
    env_t *my_env = NULL;

    if (!env)
        return NULL;
    for (int i = 0; env[i]; i++)
        add_node(&my_env, env[i]);
    return my_env;
}
