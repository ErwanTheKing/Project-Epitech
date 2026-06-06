/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The prompt.c
*/
/**
 * @file prompt.c
 * @brief The prompt.c
 * @author Erwan Lo Presti
 */

#include <unistd.h>

#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/shell.h"

void display_prompt(shell_t *my_shell)
{
    my_putchar('[');
    if (my_shell->host) {
        my_putstr(my_shell->host);
        my_putchar(':');
    }
    if (my_shell->user)
        my_putstr(my_shell->user);
    my_putstr("] ");
    my_putstr("% ");
}
