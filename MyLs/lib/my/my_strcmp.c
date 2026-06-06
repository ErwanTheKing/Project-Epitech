/*
** EPITECH PROJECT, 2025
** my_strcomp
** File description:
** comp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1[0] == '.')
        s1 = s1 + 1;
    if (s2[0] == '.')
        s2 = s2 + 1;
    while (s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    return (s1[i] - s2[i]);
}
