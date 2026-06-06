/*
** EPITECH PROJECT, 2025
** str for n comp
** File description:
** take the différent between two list for n
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int compa_s1 = 0;
    int compa_s2 = 0;

    for (int index = 0; index != n; index++) {
        compa_s1 = s1[index];
        compa_s2 = s2[index];
        if (s1[index] == '\0' && s2[index] == '\0')
            return (0);
        if (s1[index] == '\0' && s2[index] != '\0')
            return (-1);
        if (s1[index] != '\0' && s2[index] == '\0')
            return (1);
        if (compa_s1 != compa_s2) {
            return (compa_s1 - compa_s2);
        }
    }
    return (0);
}
