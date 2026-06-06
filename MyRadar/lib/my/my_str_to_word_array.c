/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdio.h>

#include "my.h"
#include <stdlib.h>

static int my_char_is_separator(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            return (0);
    }
    return 1;
}

static int count_word(char const *str, char *separator)
{
    int j;
    int b = 1;
    int count_word = 0;

    for (j = 0; str[j] != 0; j++) {
        if (my_char_is_separator(str[j], separator) == 1 && b == 1) {
            b = 0;
            count_word++;
        }
        if (my_char_is_separator(str[j], separator) == 0 && b == 0)
            b = 1;
    }
    return (count_word);
}

static int count_decalage(char const *str, int a, char *separator)
{
    int x = 1;

    while (my_char_is_separator(str[a + x], separator) == 0
        && str[a + x] != '\0') {
        x++;
    }
    return (x);
}

static char **finish(char const *str, char **dest, char *separator)
{
    int count = 0;
    int x;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a + 1] == '\0'
            || my_char_is_separator(str[a + 1], separator) == 0
            && my_char_is_separator(str[a], separator) == 1) {
            dest[count] = my_strndup(str, a + 1);
            count++;
            x = count_decalage(str, a, separator);
            str = str + a + x;
            a = -1;
        }
    }
    return (dest);
}

char **my_str_to_word_array(char const *str, char *separator)
{
    char **str2;
    int j;
    int l;

    j = count_word(str, separator);
    str2 = malloc(sizeof(char *) * (j + 1));
    for (l = 0; my_char_is_separator(str[l], separator) == 0; l++);
    str = str + l;
    str2 = finish(str, str2, separator);
    str2[j] = NULL;
    return (str2);
}
