/*
** EPITECH PROJECT, 2025
** function file
** File description:
** trun the first letter of each word to upcase
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    my_strlowcase(str);
    if (str[0] >= 97 && str[0] <= 122) {
        str[0] = str[0] - 32;
    }
    if (str[0] == '\0')
        return (str);
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' &&
            (str[i - 1] == 32 || str[i - 1] == '+' || str[i - 1] == '-')){
            str[i] = str[i] - 32;
        }
    }
    return (str);
}
