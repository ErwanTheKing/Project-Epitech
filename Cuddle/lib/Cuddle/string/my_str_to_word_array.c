/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../../Headers/my.h"
#include <stdlib.h>
#include <unistd.h>

static int my_str_isalphanum(char c, char const *separator)
{
    for (int i = 0; separator[i] != '\0'; i++) {
        if (c == separator[i])
            return SUCCESS;
    }
    return 1;
}

static int count_word(char const *str, char const *separator)
{
    int b = 1;
    int count_word = 0;

    if (!str)
        return SUCCESS;
    for (int j = 0; str[j] != 0; j++) {
        if (my_str_isalphanum(str[j], separator) == 1 && b == 1) {
            b = 0;
            count_word++;
        }
        if (my_str_isalphanum(str[j], separator) == 0 && b == 0)
            b = 1;
    }
    return (count_word);
}

static int count_decalage(char const *str, int a, char const *separator)
{
    int x = 1;

    while (my_str_isalphanum(str[a + x], separator)
        == 0 && str[a + x] != '\0') {
        x++;
    }
    return (x);
}

static int is_word_end(char const *str, int a, char const *separator)
{
    int next_is_sep = str[a + 1] == '\0'
        || my_str_isalphanum(str[a + 1], separator) == 0;

    return next_is_sep && my_str_isalphanum(str[a], separator) == 1;
}

static char **finish(char const *str, char **dest, char const *separator)
{
    int count = 0;
    int x;

    for (int a = 0; str[a] != '\0'; a++) {
        if (!is_word_end(str, a, separator))
            continue;
        dest[count] = my_strndup(str, a + 1);
        if (dest[count] == NULL) {
            free_many_arrays(1, dest);
            return NULL;
        }
        count++;
        x = count_decalage(str, a, separator);
        str = str + a + x;
        a = -1;
    }
    return (dest);
}

static char **alloc_word_array(int j)
{
    char **str2 = malloc(sizeof(char *) * (j + 1));

    if (!str2) {
        write(2, "MALLOC FAILURE\n", 15);
        return NULL;
    }
    for (int k = 0; k <= j; k++)
        str2[k] = NULL;
    return str2;
}

char **my_str_to_word_array(char const *str, char const *separator)
{
    char **str2 = NULL;
    int j;
    int l;

    if (!str || !separator)
        return NULL;
    j = count_word(str, separator);
    if (!j)
        return NULL;
    str2 = alloc_word_array(j);
    if (!str2)
        return NULL;
    for (l = 0; str[l] != '\0' && my_str_isalphanum(str[l], separator) == 0;
        l++);
    str = str + l;
    str2 = finish(str, str2, separator);
    if (str2)
        str2[j] = NULL;
    return str2;
}
