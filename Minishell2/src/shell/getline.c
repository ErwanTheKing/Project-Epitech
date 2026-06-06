/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The getline.c
*/
/**
 * @file getline.c
 * @brief The getline.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <stdlib.h>

#include "../../lib/my/headers/shell.h"
#include <unistd.h>
#include "../../lib/my/headers/my.h"

static char *getline_error(void)
{
    char *str = NULL;

    if (isatty(1)) {
        str = my_strdup("exit", 0);
        return str;
    }
    return NULL;
}

char *read_getline(shell_t *my_shell)
{
    ssize_t read;
    size_t len;
    char *line = NULL;

    if (isatty(0))
        display_prompt(my_shell);
    read = getline(&line, &len, stdin);
    if (read == -1) {
        free(line);
        return getline_error();
    }
    line[read - 1] = '\0';
    return line;
}
