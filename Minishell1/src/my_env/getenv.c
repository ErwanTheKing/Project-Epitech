/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The getenv.c
*/
/**
 * @file getenv.c
 * @brief The getenv.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/shell.h"

char *my_getenv(env_t *my_env, char *var)
{
    char *val = NULL;
    env_t *tmp = NULL;
    int len = my_strlen(var);
    char **array = NULL;

    if (!my_env || !var)
        return NULL;
    for (tmp = my_env; tmp; tmp = tmp->next) {
        if (my_strncmp(tmp->data, var, len - 1) == 0 && tmp->data[len] == '='
            && tmp->data[len + 1] != '\0') {
            array = my_str_to_word_array(tmp->data, "=");
            val = my_strdup(array[1], 0);
            free_array(array);
            return val;
        }
    }
    return NULL;
}
