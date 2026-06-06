/*
** EPITECH PROJECT, 2025
** my_strstr for 2 str
** File description:
** begin the str at a str starting point
*/

#include "my.h"

static int ncmp(char const *s1, char const *s2, int n)
{
    int compa_s1 = 0;
    int compa_s2 = 0;
    int nmb_same = 0;

    for (int index = 0; index != n; index++) {
        compa_s1 = s1[index];
        compa_s2 = s2[index];
        if (compa_s1 != compa_s2){
            return (-1);
        }
        if (s1[index] == s2[index]){
            nmb_same++;
        }
    }
    return (nmb_same);
}

char *my_strstr(char *str, char const *to_find)
{
    int result;
    int n = my_strlen(str);

    for (int i = 0; i < n; i++) {
        result = ncmp(str, to_find, my_strlen(to_find));
        if (result == my_strlen(to_find)) {
            return (str);
        }
        str++;
    }
    return (0);
}
