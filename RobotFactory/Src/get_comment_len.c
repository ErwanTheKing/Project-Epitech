/*
** EPITECH PROJECT, 2026
** get
** File description:
** len
*/

#include "../lib/Headers/factory.h"

int get_comment_len(char *buff)
{
    int occ = occurrencies(buff, '"');
    int count = 0;
    int index = 0;

    if (occ != 2)
        return EMPTY;
    for (; buff[index] != '\0' && count != 2; index++) {
        if (buff[index] == '"')
            count++;
    }
    return index;
}
