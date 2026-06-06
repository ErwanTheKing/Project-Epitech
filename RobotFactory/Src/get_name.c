/*
** EPITECH PROJECT, 2026
** get
** File description:
** name
*/

#include "../lib/Headers/factory.h"

char *get_name(char *buff)
{
    int pos = NOT_FOUND;
    int len = 0;
    int i = 0;
    char *name = NULL;
    char *sub = NULL;

    for (int index = 0; pos == NOT_FOUND && buff[index] != '\0'; index++) {
        if (my_strncmp(NAME_CMD_STRING, &buff[index], NAME_CMD_LEN) == 0)
            pos = index;
    }
    if (pos == NOT_FOUND)
        return NULL;
    sub = &buff[pos + NAME_CMD_LEN];
    len = get_name_len(sub);
    while (sub[i] == ' ' || sub[i] == '\t')
        i++;
    if (sub[i] != '"')
        return NULL;
    name = my_strndup(&sub[i + 1], len - i - 2);
    return name;
}
