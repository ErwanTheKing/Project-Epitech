/*
** EPITECH PROJECT, 2026
** G-PSU-200-NCE-2-1-minishell2-6
** File description:
** The choose_redirection.c
*/
/**
 * @file choose_redirection.c
 * @brief The choose_redirection.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>

#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/shell.h"

static int left_rd(shell_t *my_shell, char *lines)
{
    char **array = my_str_to_word_array(lines, " \t");

    if (!array)
        return FAILURE;
    for (int i = 0; array[i]; i++) {
        if (my_strcmp(array[i], "<") == 0)
            my_shell->rd_l = SIMPLE_LEFT;
        if (my_strcmp(array[i], "<<") == 0)
            my_shell->rd_l = DOUBLE_LEFT;
        if (my_shell->rd_l != NONE) {
            my_shell->file_l = my_strdup(array[i + 1], 0);
            break;
        }
    }
    free_array(array);
    return SUCCESS;
}

static int right_rd(shell_t *my_shell, char *lines)
{
    char **array = my_str_to_word_array(lines, " \t");

    if (!array)
        return FAILURE;
    for (int i = 0; array[i]; i++) {
        if (my_strcmp(array[i], ">") == 0)
            my_shell->rd_r = SIMPLE_RIGHT;
        if (my_strcmp(array[i], ">>") == 0)
            my_shell->rd_r = DOUBLE_RIGHT;
        if (my_shell->rd_r != NONE) {
            my_shell->file_r = my_strdup(array[i + 1], 0);
            break;
        }
    }
    free_array(array);
    return SUCCESS;
}

int choose_redirection(shell_t *my_shell, char **array)
{
    if (my_array_len(array) == 1) {
        if (left_rd(my_shell, array[0]) == FAILURE)
            return FAILURE;
        if (right_rd(my_shell, array[0]) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}
