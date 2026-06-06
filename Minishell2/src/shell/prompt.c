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

#include <stdlib.h>
#include "../../lib/my/headers/my.h"
#include "../../lib/my/headers/shell.h"

static void host(char *hostname)
{
    if (hostname) {
        my_putstr("\033[105m 💻 ");
        my_putstr(hostname);
        my_putstr(" \033[0m");
    }
}

static void user(char *username)
{
    if (username) {
        my_putstr("\033[103m 🐧 ");
        my_putstr(username);
        my_putstr(" \033[0m");
    }
}

static void pwd(char *pwd_folder)
{
    if (pwd_folder) {
        my_putstr("\033[102m  ");
        my_putstr(pwd_folder);
        my_putstr(" \033[0m");
        free(pwd_folder);
    }
}

static void git(char *git_branch)
{
    if (git_branch) {
        my_putstr("\033[104m  ");
        my_putstr(git_branch);
        my_putstr(" \033[0m");
        free(git_branch);
    }
}

void display_prompt(shell_t *my_shell)
{
    char *git_branch = get_branch_git();
    char *pwd_folder = get_pwd();

    my_putstr("\033[90m╭─\033[0m ");
    host(my_shell->host);
    user(my_shell->user);
    pwd(pwd_folder);
    git(git_branch);
    my_putstr("\n\033[90m╰─❯\033[0m ");
}
