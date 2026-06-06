/*
** EPITECH PROJECT, 2026
** G-PSU-200-NCE-2-1-minishell2-6
** File description:
** The left_redirection.c
*/
/**
 * @file left_redirection.c
 * @brief The left_redirection.c
 * @author Erwan Lo Presti
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/shell.h"
#include "fcntl.h"
#include "../../lib/my/headers/defines.h"
#include <unistd.h>

static int get_fd(const char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        if (errno == EISDIR) {
            write(1, file, my_strlen(file));
            write(1, ": Is a directory.\n", 18);
        }
        return -1;
    }
    return fd;
}

static int simple(const char *file)
{
    int fd = get_fd(file);

    if (fd == -1)
        return FAILURE;
    dup2(fd, STDIN_FILENO);
    close(fd);
    return SUCCESS;
}

int left_redirection(const char *file, redirection_t choose)
{
    if (choose == NONE || !file)
        return SUCCESS;
    if (choose == SIMPLE_LEFT) {
        if (simple(file) == FAILURE)
            return FAILURE;
        return SUCCESS;
    }
    return SUCCESS;
}
