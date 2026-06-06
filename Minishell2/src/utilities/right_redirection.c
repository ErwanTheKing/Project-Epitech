/*
** EPITECH PROJECT, 2026
** G-PSU-200-NCE-2-1-minishell2-6
** File description:
** The right_redirection.c
*/
/**
 * @file right_redirection.c
 * @brief The right_redirection.c
 * @author Erwan Lo Presti
 */

#include <errno.h>
#include <stdio.h>

#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/shell.h"
#include "fcntl.h"
#include "../../lib/my/headers/defines.h"
#include <unistd.h>

static int get_fd(const char *file, redirection_t choose)
{
    int fd = 0;
    int flag = O_CREAT | O_RDWR;

    if (choose == SIMPLE_RIGHT)
        flag |= O_TRUNC;
    else
        flag |= O_APPEND;
    fd = open(file, flag, 0664);
    if (fd == -1) {
        if (errno == EISDIR) {
            write(1, file, my_strlen(file));
            write(1, ": Is a directory.\n", 18);
        }
        return -1;
    }
    return fd;
}

int right_redirection(const char *file, redirection_t choose)
{
    int fd = 0;

    if (choose == NONE || !file)
        return SUCCESS;
    fd = get_fd(file, choose);
    if (fd == -1)
        return FAILURE;
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return SUCCESS;
}
