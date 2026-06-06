/*
** EPITECH PROJECT, 2026
** PainAuChocolat
** File description:
** The my_strlowcase.c
*/
/**
 * @file my_strlowcase.c
 * @brief The my_strlowcase.c
 * @author Erwan Lo Presti
 */

char *my_strlowcase(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return (str);
}
