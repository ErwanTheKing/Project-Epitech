/*
** EPITECH PROJECT, 2026
** G-PSU-200-NCE-2-1-minishell2-6
** File description:
** The pipes.c
*/
/**
 * @file pipes.c
 * @brief The pipes.c
 * @author Erwan Lo Presti
 */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/shell.h"

int nbr_cmd(char *line)
{
    int nbr = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '|')
            nbr++;
    }
    return nbr + 1;
}

static void child_pipe(shell_t *my_shell, pipe_data_t *data, char **array)
{
    char *sub[2] = {array[data->i], NULL};
    char *str = NULL;

    my_shell->in_pipe = 1;
    if (data->prev_read != -1) {
        dup2(data->prev_read, STDIN_FILENO);
        close(data->prev_read);
    }
    if (data->i < data->nb_cmds - 1) {
        dup2(data->fd[1], STDOUT_FILENO);
        close(data->fd[0]);
        close(data->fd[1]);
    }
    str = clear_str(array[data->i]);
    choose_redirection(my_shell, sub);
    exec_cmd(my_shell, str);
    free(str);
    exit(my_shell->return_va);
}

int func_pipe(char *lines, shell_t *my_shell, char **array)
{
    pipe_data_t data = {-1, NULL, 0, nbr_cmd(lines)};
    int fd[2];

    data.fd = fd;
    for (int i = 0; i < data.nb_cmds; i++) {
        data.i = i;
        if (i < data.nb_cmds - 1)
            pipe(fd);
        if (fork() == 0)
            child_pipe(my_shell, &data, array);
        if (data.prev_read != -1)
            close(data.prev_read);
        if (i < data.nb_cmds - 1) {
            close(fd[1]);
            data.prev_read = fd[0];
        }
    }
    for (int i = 0; i < data.nb_cmds; i++)
        wait(NULL);
    return SUCCESS;
}
