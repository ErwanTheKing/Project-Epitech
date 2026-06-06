/*
** EPITECH PROJECT, 2026
** shell
** File description:
** The display_env.c
*/
/**
 * @file display_env.c
 * @brief The display_env.c
 * @author Erwan Lo Presti
 */

#include "../../lib/my/headers/shell.h"
#include <unistd.h>
#include "../../lib/my/headers/my.h"

void display_env(env_t *my_env)
{
    if (!my_env)
        return;
    for (env_t *tmp = my_env; tmp; tmp = tmp->next) {
        write(1, tmp->data, my_strlen(tmp->data));
        write(1, "\n", 1);
    }
}
