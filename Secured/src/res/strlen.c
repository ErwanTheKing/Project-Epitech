/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-CPE-110-NCE-1-1-secured-2/src
** File description:
** strlen
*/

int my_strlen(char const *str)
{
    int len = 0;

    for (; str[len] != '\0'; len++);
    return len;
}
