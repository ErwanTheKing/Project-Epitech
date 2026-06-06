/*
** EPITECH PROJECT, 2026
** G-PSU-200-NCE-2-1-minishell2-6
** File description:
** The verif_builtin.c
*/
/**
 * @file verif_builtin.c
 * @brief The verif_builtin.c
 * @author Erwan Lo Presti
 */

#include <stdlib.h>

#include "../../lib/my/headers/shell.h"
#include "../../lib/my/headers/my.h"

int handle_builtin(char **array, shell_t *my_shell)
{
    char *str = clear_str(array[my_array_len(array) - 1]);

    exec_cmd(my_shell, str);
    free(str);
    free_array(array);
    return SUCCESS;
}

int is_builtin(char *str)
{
    int return_v = FAILURE;
    char **array = my_str_to_word_array(str, " \t");

    if (!array)
        return return_v;
    if (my_strcmp("cd", array[0]) == 0)
        return_v = SUCCESS;
    if (my_strcmp("setenv", array[0]) == 0)
        return_v = SUCCESS;
    if (my_strcmp("unsetenv", array[0]) == 0)
        return_v = SUCCESS;
    if (my_strcmp("env", array[0]) == 0)
        return_v = SUCCESS;
    free_array(array);
    return return_v;
}

int verif_builtin(char **array)
{
    int len = my_array_len(array);

    if (is_builtin(array[len - 1]) == SUCCESS)
        return SUCCESS;
    return FAILURE;
}
