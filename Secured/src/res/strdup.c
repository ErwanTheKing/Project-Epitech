/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-CPE-110-NCE-1-1-secured-2/src
** File description:
** strdup
*/

#include "hashtable.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dup = malloc(sizeof(char) * (len + 1));

    if (!dup)
        return NULL;
    my_strncpy(dup, src, len);
    dup[len] = '\0';
    return dup;
}
