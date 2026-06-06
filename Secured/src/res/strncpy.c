/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-CPE-110-NCE-1-1-secured-2/src
** File description:
** strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}
