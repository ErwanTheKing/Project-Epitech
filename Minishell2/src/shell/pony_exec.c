/*
** EPITECH PROJECT, 2026
** G-PSU-200-NCE-2-1-minishell2-6
** File description:
** The pony_exec.c
*/
/**
 * @file pony_exec.c
 * @brief The pony_exec.c
 * @author Erwan Lo Presti
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../lib/my/headers/defines.h"
#include "./../../lib/my/headers/shell.h"
#include <unistd.h>
#include <sys/wait.h>

int pony(shell_t *my_shell)
{
    char *args[] = {"ponysay", "HELLO", NULL};
    pid_t pid = fork();
    int status = 0;

    if (pid == 0) {
        status = execve("/snap/bin/ponysay", args, NULL);
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            my_shell->return_va = WEXITSTATUS(status);
    }
    return SUCCESS;
}
