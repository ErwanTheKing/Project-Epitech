/*
** EPITECH PROJECT, 2026
** G-PSU-200-NCE-2-1-minishell2-6
** File description:
** The verif_lines.c
*/
/**
 * @file verif_lines.c
 * @brief The lines_to_array.c
 * @author Erwan Lo Presti
 */

#include <unistd.h>
#include "../../lib/my/headers/shell.h"
#include "../../lib/my/headers/my.h"
#include <stdio.h>
#include <stdlib.h>

static void verif_double_redirect(char **tmp, int *redirect_r, int *redirect_l)
{
    for (int i = 0; tmp[i]; i++) {
        if (is_right_redirect(tmp[i]) == 0)
            (*redirect_r)++;
        if (is_left_redirect(tmp[i]) == 0)
            (*redirect_l)++;
    }
    if (*redirect_l >= 2) {
        write(1, "Ambiguous output redirect.\n", 27);
        return;
    }
    if (*redirect_r >= 2)
        write(1, "Ambiguous input redirect.\n", 26);
}

static int verif_syntax(char **array)
{
    int redirect_r = 0;
    int redirect_l = 0;
    char **tmp = NULL;

    for (int i = 0; array[i]; i++) {
        redirect_r = 0;
        redirect_l = 0;
        tmp = my_str_to_word_array(array[i], " \t");
        if (!tmp)
            return FAILURE;
        verif_double_redirect(tmp, &redirect_r, &redirect_l);
        if (redirect_l >= 2 || redirect_r >= 2) {
            free_array(tmp);
            return -1;
        }
        free_array(tmp);
    }
    return SUCCESS;
}

static int verif_redirect_pipe(int i, char **array)
{
    char *redirect_r[3] = {">", ">>", NULL};
    char *redirect_l[3] = {"<", "<<", NULL};
    int len = my_array_len(array);

    for (int j = 0; redirect_r[j]; j++) {
        if (i != 0 && my_strstr(array[i], redirect_l[j]) != NULL) {
            write(1, "Ambiguous input redirect.\n", 26);
            return FAILURE;
        }
        if (i != len - 1 && my_strstr(array[i], redirect_r[j]) != NULL) {
            write(1, "Ambiguous output redirect.\n", 27);
            return FAILURE;
        }
    }
    return SUCCESS;
}

static int handle_error_pipe(char **array, int nbr)
{
    int len = my_array_len(array);

    if (nbr != len) {
        write(1, "Invalid null command.\n", 22);
        return FAILURE;
    }
    for (int i = 0; array[i]; i++) {
        if (verif_redirect_pipe(i, array) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

static int verif_missing_name(char *lines)
{
    char **array = my_str_to_word_array(lines, "<>;");
    char **tmp = NULL;

    if (!array || my_array_len(array) == 1) {
        write(1, "Missing name for redirect.\n", 27);
        free_array(array);
        return FAILURE;
    }
    for (int i = 0; array[i]; i++) {
        tmp = my_str_to_word_array(array[i], " \t");
        if (!tmp) {
            write(1, "Missing name for redirect.\n", 27);
            free_array(array);
            return FAILURE;
        }
        free_array(tmp);
    }
    free_array(array);
    return SUCCESS;
}

static int handle_single(char *lines, shell_t *my_shell, char **array)
{
    char *str = clear_str(lines);

    exec_cmd(my_shell, str);
    free(str);
    free_array(array);
    return SUCCESS;
}

static int verif_pipe(char *lines, shell_t *my_shell, int nbr)
{
    char **array = my_str_to_word_array(lines, "|");

    if (!array) {
        write(1, "Invalid null command.\n", 22);
        return FAILURE;
    }
    if (handle_error_pipe(array, nbr) == FAILURE) {
        free_array(array);
        return FAILURE;
    }
    choose_redirection(my_shell, array);
    if (my_array_len(array) == 1)
        return handle_single(lines, my_shell, array);
    if (verif_builtin(array) == SUCCESS)
        return handle_builtin(array, my_shell);
    func_pipe(lines, my_shell, array);
    free_array(array);
    return SUCCESS;
}

static void reset_rd(shell_t *my_shell)
{
    if (my_shell->rd_l != NONE)
        free(my_shell->file_l);
    if (my_shell->rd_r != NONE)
        free(my_shell->file_r);
    my_shell->file_l = NULL;
    my_shell->file_r = NULL;
    my_shell->rd_l = NONE;
    my_shell->rd_r = NONE;
}

static int syntax(char *lines, char **array, shell_t *my_shell)
{
    if (is_left_redirect(lines) == 0 || is_right_redirect(lines) == 0) {
        if (verif_missing_name(lines) == FAILURE) {
            free_array(array);
            return FAILURE;
        }
    }
    if (verif_syntax(array) == -1) {
        my_shell->return_va = 1;
        free_array(array);
        return FAILURE;
    }
    return SUCCESS;
}

void verif_lines(char *lines, shell_t *my_shell)
{
    int nbr = 0;
    char **array = my_str_to_word_array(lines, ";");

    if (!array)
        return;
    if (syntax(lines, array, my_shell) == FAILURE)
        return;
    for (int i = 0; array[i]; i++) {
        nbr = nbr_cmd(array[i]);
        if (verif_pipe(array[i], my_shell, nbr) == FAILURE)
            break;
        reset_rd(my_shell);
    }
    free_array(array);
}
