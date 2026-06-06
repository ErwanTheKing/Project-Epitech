/*
** EPITECH PROJECT, 2026
** skip
** File description:
** header
*/

#include "../lib/Headers/factory.h"

int skip_header(char *buff)
{
    int pos = NOT_FOUND;

    for (int index = 0; pos == NOT_FOUND && buff[index] != '\0'; index++) {
        if (my_strncmp(NAME_CMD_STRING, &buff[index], NAME_CMD_LEN) == 0)
            pos = index;
    }
    for (int index = pos; buff[index] != '\0'; index++) {
        if (my_strncmp(COMMENT_CMD_STRING, &buff[index], COMMENT_CMD_LEN) == 0)
            pos = index;
    }
    pos += skip_comment(&buff[pos]);
    return pos;
}
