/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The loop.c
*/
/**
 * @file loop.c
 * @brief The loop.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/shell.h"

int loop(shell_t *my_shell)
{
    char *line = NULL;

    while (my_strcmp(line, "exit") != 0) {
        if (line)
            free(line);
        line = read_getline(my_shell);
        if (line == NULL)
            break;
        if (my_strcmp(line, "exit") == 0)
            break;
        if (exec_env(my_shell, line) == FAILURE)
            verif_lines(line, my_shell);
    }
    if (line)
        free(line);
    write(1, "exit\n", 5);
    return my_shell->return_va;
}
