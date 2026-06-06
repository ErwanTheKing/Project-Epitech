/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The cmd.c
*/
/**
 * @file cmd.c
 * @brief The cmd.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/shell.h"
#include <stdlib.h>
#include <unistd.h>

static char *build_cmd(char *bin, char *path)
{
    int len_path = my_strlen(path);
    int len_bin = my_strlen(bin);
    char *cmd = malloc(sizeof(char) * (len_path + len_bin + 2));

    if (!cmd)
        return NULL;
    my_strcpy(cmd, path);
    cmd[len_path] = '/';
    my_strcpy(cmd + len_path + 1, bin);
    return cmd;
}

static char *get_cmd(char *bin, shell_t *my_shell)
{
    char *path = my_getenv(my_shell->my_env, "PATH");
    char **array = NULL;
    char *cmd = NULL;

    if (!path)
        return NULL;
    array = my_str_to_word_array(path, ":");
    for (int i = 0; array[i]; i++) {
        cmd = build_cmd(bin, array[i]);
        if (!cmd)
            return NULL;
        if (access(cmd, F_OK) == 0)
            break;
        free(cmd);
        cmd = NULL;
    }
    free(path);
    free_array(array);
    return cmd;
}

char *verif_cmd(char *line, shell_t *my_shell)
{
    char **arg = my_str_to_word_array(line, " \t\n");
    char *cmd = NULL;

    if (arg == NULL)
        return NULL;
    cmd = get_cmd(arg[0], my_shell);
    if (!cmd && access(arg[0], X_OK) != 0) {
        my_putstr(arg[0]);
        my_putstr(": Command not found.\n");
        my_shell->return_va = 1;
        return NULL;
    }
    free_array(arg);
    my_shell->return_va = 0;
    return cmd;
}
