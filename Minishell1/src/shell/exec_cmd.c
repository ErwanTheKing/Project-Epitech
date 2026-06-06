/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The exec_cmd.c
*/
/**
 * @file exec_cmd.c
 * @brief The exec_cmd.c
 * @author Erwan Lo Presti
 */

#include <errno.h>
#include <stdio.h>
#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <asm-generic/errno-base.h>
#include "../../lib/my/headers/my.h"
#include <sys/wait.h>

void print_error(char *cmd)
{
    if (errno == ENOEXEC) {
        my_putstr(cmd);
        my_putstr(": Exec format error. Binary file not executable.\n");
        return;
    }
    if (errno == EACCES) {
        my_putstr(cmd);
        my_putstr(": Permission denied.\n");
        return;
    }
    if (errno == ENOENT) {
        my_putstr(cmd);
        my_putstr(": Command not found.\n");
        return;
    }
    perror(cmd);
}

static void check_status(int status, shell_t *my_shell)
{
    int sig_no = WTERMSIG(status);

    if (sig_no == SIGSEGV)
        my_putstr("Segmentation fault");
    if (sig_no == SIGFPE)
        my_putstr("Floating exception");
    if (WCOREDUMP(status))
        my_putstr(" (core dumped)");
    my_putchar('\n');
    my_shell->return_va = 128 + WTERMSIG(status);
}

static int check_pid(char **arg, int status, char *cmd, char **array)
{
    if (access(arg[0], X_OK) == 0) {
        status = execve(arg[0], arg, array);
        print_error(arg[0]);
    } else {
        status = execve(cmd, arg, array);
        print_error(cmd);
    }
    return status;
}

int in_fork(shell_t *my_shell, char *cmd, char **arg)
{
    pid_t pid = fork();
    int status = 0;
    char **array = array_env(my_shell->my_env);

    if (!array)
        return FAILURE;
    if (pid == 0) {
        status = check_pid(arg, status, cmd, array);
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            my_shell->return_va = WEXITSTATUS(status);
        if (WIFSIGNALED(status))
            check_status(status, my_shell);
    }
    free(array);
    free(cmd);
    return SUCCESS;
}

int exec_cmd(shell_t *my_shell, char *line)
{
    char *cmd = NULL;
    char **arg = my_str_to_word_array(line, " \n\t");

    if (!arg)
        return FAILURE;
    if (my_strcmp(arg[0], "cd") == 0) {
        manage_cd(my_shell, arg[1]);
        free_array(arg);
        return SUCCESS;
    }
    cmd = verif_cmd(line, my_shell);
    if (!cmd && access(arg[0], X_OK) != 0) {
        free_array(arg);
        return FAILURE;
    }
    if (in_fork(my_shell, cmd, arg) == FAILURE) {
        return FAILURE;
    }
    free_array(arg);
    return SUCCESS;
}
