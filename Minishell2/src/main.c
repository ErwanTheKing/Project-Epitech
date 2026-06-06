/*
** EPITECH PROJECT, 2026
** G-PSU-200-NCE-2-1-minishell1-4
** File description:
** The main.c
*/
/**
 * @file main.c
 * @brief The main.c
 * @author Erwan Lo Presti
 */

#include <stdio.h>
#include "../lib/my/headers/defines.h"
#include <stdlib.h>
#include "../lib/my/headers/shell.h"

int main(int argc, char **argv, char **env)
{
    shell_t *my_shell = init(env);
    int return_val = 0;

    if (!my_shell)
        return FAILURE;
    if (argc != 1 || argv == NULL) {
        free_shell(my_shell);
        return FAILURE;
    }
    pony(my_shell);
    return_val = loop(my_shell);
    free_shell(my_shell);
    return return_val;
}
