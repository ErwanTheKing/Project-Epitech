/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The setenv.c
*/
/**
 * @file setenv.c
 * @brief The setenv.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/shell.h"

static int str_alphanum(char *var)
{
    int total = 0;

    for (int i = 0; var[i]; i++) {
        if (var[i] >= 'A' && var[i] <= 'Z')
            total++;
        if (var[i] >= 'a' && var[i] <= 'z')
            total++;
        if (var[i] >= '0' && var[i] <= '9')
            total++;
        if (var[i] == '_')
            total++;
    }
    return total == my_strlen(var) ? SUCCESS : FAILURE;
}

static int char_alphanum(char var)
{
    int total = 0;

    if (var >= 'A' && var <= 'Z')
        total++;
    if (var >= 'a' && var <= 'z')
        total++;
    if (var == '_')
        total++;
    return total == 1 ? SUCCESS : FAILURE;
}

static char *add_data(char *variable, char *value)
{
    int len_var = my_strlen(variable);
    int len_val = value ? my_strlen(value) : 0;
    int total = len_var + len_val + 1;
    char *str = malloc(sizeof(char) * total + 1);

    if (!str)
        return NULL;
    for (int i = 0; i < len_var; i++)
        str[i] = variable[i];
    str[len_var] = '=';
    for (int i = 0; i < len_val; i++)
        str[len_var + 1 + i] = value[i];
    str[total] = '\0';
    return str;
}

static int update_node(env_t *env, char *variable, char *value)
{
    size_t len = my_strlen(variable);
    char *new_data;

    for (; env; env = env->next) {
        if (my_strncmp(env->data, variable, len - 1) != 0
            || env->data[len] != '=')
            continue;
        new_data = add_data(variable, value);
        if (!new_data)
            return FAILURE;
        free(env->data);
        env->data = new_data;
        return SUCCESS;
    }
    return FAILURE;
}

static int push_back_node(env_t **env, char *variable, char *value)
{
    env_t *node = malloc(sizeof(env_t));
    env_t *tmp = NULL;

    if (!node)
        return FAILURE;
    node->data = add_data(variable, value);
    if (!node->data) {
        free(node);
        return FAILURE;
    }
    node->next = NULL;
    if (!*env) {
        *env = node;
        return SUCCESS;
    }
    for (tmp = *env; tmp->next; tmp = tmp->next);
    tmp->next = node;
    return SUCCESS;
}

static int add_node(env_t **env, char *variable, char *value)
{
    if (!env)
        return FAILURE;
    if (*env && update_node(*env, variable, value) == SUCCESS)
        return SUCCESS;
    return push_back_node(env, variable, value);
}

int my_setenv(env_t **my_env, char *variable, char *value, shell_t *my_shell)
{
    if (!variable)
        return FAILURE;
    if (char_alphanum(variable[0]) == FAILURE) {
        write(1, "setenv: Variable name must begin with a letter.\n", 48);
        my_shell->return_va = 1;
        return FAILURE;
    }
    if (str_alphanum(variable) == FAILURE) {
        write(1,
            "setenv: Variable name must contain alphanumeric characters.\n",
            60);
        my_shell->return_va = 1;
        return FAILURE;
    }
    my_shell->return_va = 0;
    return add_node(my_env, variable, value);
}
