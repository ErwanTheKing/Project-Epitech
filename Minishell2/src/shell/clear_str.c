/*
** EPITECH PROJECT, 2026
** G-PSU-200-NCE-2-1-minishell2-6
** File description:
** The clear_str.c
*/
/**
 * @file clear_str.c
 * @brief The clear_str.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../../lib/my/headers/defines.h"
#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/shell.h"
#include <stdlib.h>

static int is_rd(char *line)
{
    if (my_strcmp(line, "<") == 0)
        return SUCCESS;
    if (my_strcmp(line, "<<") == 0)
        return SUCCESS;
    if (my_strcmp(line, ">") == 0)
        return SUCCESS;
    if (my_strcmp(line, ">>") == 0)
        return SUCCESS;
    if (my_strcmp(line, "|") == 0)
        return SUCCESS;
    return FAILURE;
}

char *clear_str(char *line)
{
    char *str = NULL;
    char *tmp = NULL;
    char **array = my_str_to_word_array(line, " \t");

    if (!array)
        return NULL;
    for (int i = 0; array[i]; i++) {
        if (is_rd(array[i]) == SUCCESS)
            continue;
        if (i - 1 >= 0 && is_rd(array[i - 1]) == SUCCESS)
            continue;
        tmp = my_strconcat(str, array[i]);
        free(str);
        str = tmp;
        tmp = my_strconcat(str, " ");
        free(str);
        str = tmp;
    }
    free_array(array);
    return str;
}
