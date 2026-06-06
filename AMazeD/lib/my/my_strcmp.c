/*
** EPITECH PROJECT, 2025
** compare two str
** File description:
** compare the two and return how much caracter is different
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] != 0; i++)
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    return (s1[i] - s2[i]);
}
