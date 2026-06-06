/*
** EPITECH PROJECT, 2026
** G-PSU-200-NCE-2-1-minishell2-6
** File description:
** The get_pwd.c
*/
/**
 * @file get_pwd.c
 * @brief The get_pwd.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../lib/my/headers/my.h"

char *get_pwd(void)
{
    char *pwd = getcwd(NULL, 0);
    char *folder = NULL;
    char **array = my_str_to_word_array(pwd, "/");

    if (!array) {
        free(pwd);
        return NULL;
    }
    folder = my_strdup(array[my_array_len(array) - 1], 0);
    if (!folder) {
        free_array(array);
        free(pwd);
        return NULL;
    }
    free_array(array);
    free(pwd);
    return folder;
}
