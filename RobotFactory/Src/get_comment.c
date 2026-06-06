/*
** EPITECH PROJECT, 2026
** get
** File description:
** name
*/

#include "../lib/Headers/factory.h"

char *get_comment(char *buff)
{
    int pos = NOT_FOUND;
    int len = 0;
    char *name = NULL;

    for (int index = 0; pos == NOT_FOUND && buff[index] != '\0'; index++) {
        if (my_strncmp(COMMENT_CMD_STRING, &buff[index], COMMENT_CMD_LEN) == 0)
            pos = index;
    }
    if (pos == NOT_FOUND)
        return NULL;
    len = get_comment_len(&buff[pos + COMMENT_CMD_LEN]);
    if (len == EMPTY)
        return NULL;
    name = my_strndup(&buff[pos + COMMENT_CMD_LEN + 2], len - 3);
    return name;
}
