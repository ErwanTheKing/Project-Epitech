/*
** EPITECH PROJECT, 2026
** G-PSU-200-NCE-2-1-minishell2-6
** File description:
** The is_rd.c
*/
/**
 * @file is_rd.c
 * @brief The is_rd.c
 * @author Erwan Lo Presti
 */

int is_left_redirect(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '>')
            return 0;
    }
    return -1;
}

int is_right_redirect(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '<')
            return 0;
    }
    return -1;
}
