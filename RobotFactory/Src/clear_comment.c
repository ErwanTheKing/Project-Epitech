/*
** EPITECH PROJECT, 2026
** clear
** File description:
** clear
*/

#include "../lib/Headers/factory.h"

static void clear_line(char *buff, int i)
{
    int pos = i;

    while (buff[pos] != '\n') {
        buff[pos] = ' ';
        pos++;
    }
}

void clear_comment(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == COMMENT_CHAR) {
            clear_line(buff, i);
        }
    }
}
