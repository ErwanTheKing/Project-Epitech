/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The node to array.c
*/
/**
 * @file node to array.c
 * @brief The node to array.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/shell.h"
#include <stdlib.h>

static int len_word_node(env_t *my_env)
{
    int len = 0;

    for (env_t *tmp = my_env; tmp; tmp = tmp->next)
        len++;
    return len;
}

char **array_env(env_t *my_env)
{
    int len = len_word_node(my_env);
    char **array = malloc(sizeof(char *) * (len + 1));
    int i = 0;

    if (!array)
        return NULL;
    for (env_t *tmp = my_env; tmp; tmp = tmp->next) {
        array[i] = tmp->data;
        i++;
    }
    array[i] = NULL;
    return array;
}
