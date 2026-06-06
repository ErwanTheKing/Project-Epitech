/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The cd.c
*/
/**
 * @file cd.c
 * @brief The cd.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include "../../lib/my/headers/shell.h"
#include <unistd.h>
#include <stdlib.h>
#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/my.h"

static void basic(char *arg, shell_t *my_shell)
{
    if (chdir(arg) != 0) {
        my_putstr(arg);
        my_putstr(": Not a directory.\n");
        my_shell->return_va = 1;
        return;
    }
    if (my_shell->last_path)
        free(my_shell->last_path);
    my_shell->last_path = my_strdup(my_shell->old_path, 0);
    my_shell->return_va = 0;
}

static void home(shell_t *my_shell)
{
    if (!my_shell->home)
        return;
    chdir(my_shell->home);
    if (my_shell->last_path)
        free(my_shell->last_path);
    my_shell->last_path = my_strdup(my_shell->old_path, 0);
    my_shell->return_va = 0;
}

static int old(shell_t *my_shell)
{
    if (my_shell->last_path == NULL) {
        my_putstr(": Not a directory.\n");
        my_shell->return_va = 1;
        return SUCCESS;
    }
    if (chdir(my_shell->last_path) != 0)
        my_putstr(": no such file or directory.\n");
    if (my_shell->last_path)
        free(my_shell->last_path);
    my_shell->last_path = my_strdup(my_shell->old_path, 0);
    return SUCCESS;
}

int manage_cd(shell_t *my_shell, char *arg)
{
    if (my_shell->old_path)
        free(my_shell->old_path);
    my_shell->old_path = getcwd(NULL, 0);
    if (!my_shell->old_path)
        return FAILURE;
    if (arg == NULL || my_strcmp(arg, "~") == 0) {
        home(my_shell);
        return SUCCESS;
    }
    if (my_strcmp(arg, "-") == 0) {
        old(my_shell);
        return SUCCESS;
    }
    basic(arg, my_shell);
    return SUCCESS;
}
