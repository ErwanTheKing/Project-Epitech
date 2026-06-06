/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/secured
** File description:
** hash
*/

#include "hashtable.h"
#include <stdlib.h>
#include <limits.h>

int str_to_ascii(char *str)
{
    int result = 0;
    int i = 0;

    while (str[i]) {
        result = (result * 33) ^ str[i];
        i++;
    }
    return result;
}

static int get_mid_val(char *str, int len)
{
    char *mid = malloc(sizeof(char) * 5);
    int res = 0;

    if (!mid)
        return 0;
    my_strncpy(mid, str + (len / 2) - 2, 4);
    mid[4] = '\0';
    res = str_to_int(mid);
    free(mid);
    return res;
}

static int extract_mid(char *str)
{
    int len = my_strlen(str);
    int res = 0;

    if (len < 4) {
        res = str_to_int(str);
    } else {
        res = get_mid_val(str, len);
    }
    free(str);
    return res;
}

int mid_square(int num)
{
    long long squared = (long long)num * (long long)num;
    char *str_num = NULL;

    if (squared < 0)
        squared = -squared;
    str_num = dlong_to_str(squared);
    if (!str_num)
        return 0;
    return extract_mid(str_num);
}

int hash(char *key, int len)
{
    int encrypted = str_to_ascii(key);

    encrypted = mid_square(encrypted) + len;
    encrypted ^= 2395;
    if (encrypted < 0)
        encrypted *= -1;
    return encrypted;
}
