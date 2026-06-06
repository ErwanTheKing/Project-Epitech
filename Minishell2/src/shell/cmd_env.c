/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The command.c
*/
/**
 * @file command.c
 * @brief The command.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../../lib/my/headers/shell.h"
#include "../../lib/my/headers/my.h"
#include <stdlib.h>
#include <unistd.h>

static int len_word_array(char **array)
{
    int len = 0;

    if (!array)
        return 0;
    for (; array[len] != NULL; len++);
    return len;
}

static int exec_disp_env(shell_t *my_shell, char *line)
{
    if (my_strcmp(line, "env") == 0) {
        display_env(my_shell->my_env);
        my_shell->return_va = 0;
        return SUCCESS;
    }
    my_shell->return_va = 0;
    return FAILURE;
}

static int exec_setenv(shell_t *my_shell, char *line)
{
    char **array = my_str_to_word_array(line, " \t");
    int len = len_word_array(array);

    if (my_strncmp(line, "setenv", 5) == 0) {
        if (len == 1) {
            display_env(my_shell->my_env);
            my_shell->return_va = 0;
        }
        if (len > 3) {
            write(1, "setenv: Too many arguments.\n", 28);
            my_shell->return_va = 1;
        }
        if (len == 3 || len == 2) {
            my_setenv(&my_shell->my_env, array[1], array[2], my_shell);
        }
        free_array(array);
        return SUCCESS;
    }
    free_array(array);
    return FAILURE;
}

static int exec_unsetenv(shell_t *my_shell, char *line)
{
    char **array = my_str_to_word_array(line, " \t");

    if (my_strncmp(line, "unsetenv", 7) == 0) {
        for (int i = 1; array[i]; i++)
            my_unsetenv(&my_shell->my_env, array[i]);
        free_array(array);
        my_shell->return_va = 0;
        return SUCCESS;
    }
    free_array(array);
    my_shell->return_va = 0;
    return FAILURE;
}

int exec_env(shell_t *my_shell, char *line)
{
    if (exec_disp_env(my_shell, line) == SUCCESS)
        return SUCCESS;
    if (exec_setenv(my_shell, line) == SUCCESS)
        return SUCCESS;
    if (exec_unsetenv(my_shell, line) == SUCCESS)
        return SUCCESS;
    return FAILURE;
}
