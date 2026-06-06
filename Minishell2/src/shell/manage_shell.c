/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The init.c
*/
/**
 * @file init.c
 * @brief The init.c
 * @author Erwan Lo Presti
 */

#include <stdlib.h>
#include "../../lib/my/headers/shell.h"

shell_t *init(char **env)
{
    shell_t *my_shell = malloc(sizeof(shell_t));

    if (!my_shell)
        return NULL;
    my_shell->my_env = create_env(env);
    my_shell->return_va = 0;
    my_shell->host = my_getenv(my_shell->my_env, "HOST");
    my_shell->user = my_getenv(my_shell->my_env, "USER");
    my_shell->home = my_getenv(my_shell->my_env, "HOME");
    my_shell->old_path = NULL;
    my_shell->last_path = NULL;
    my_shell->rd_r = NONE;
    my_shell->file_r = NULL;
    my_shell->rd_l = NONE;
    my_shell->file_l = NULL;
    my_shell->in_pipe = -1;
    return my_shell;
}

void free_shell(shell_t *my_shell)
{
    if (my_shell) {
        if (my_shell->my_env)
            free_env(&my_shell->my_env);
        if (my_shell->host)
            free(my_shell->host);
        if (my_shell->user)
            free(my_shell->user);
        if (my_shell->home)
            free(my_shell->home);
        if (my_shell->old_path)
            free(my_shell->old_path);
        if (my_shell->last_path)
            free(my_shell->last_path);
        free(my_shell);
    }
}
