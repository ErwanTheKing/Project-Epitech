/*
** EPITECH PROJECT, 2026
** fill
** File description:
** buffer
*/

#include "../lib/Headers/factory.h"

char *fill_buffer(int dest, char *filename)
{
    char *buff = NULL;
    int size = 0;
    struct stat st;

    if (!dest)
        return NULL;
    if (stat(filename, &st) == -1)
        return NULL;
    buff = malloc(st.st_size + 1);
    if (!buff)
        return NULL;
    size = read(dest, buff, st.st_size);
    if (size < 0) {
        free(buff);
        return NULL;
    }
    buff[size] = '\0';
    return buff;
}
