/*
** EPITECH PROJECT, 2026
** cor
** File description:
** formating
*/

#include "../lib/Headers/factory.h"

char *cor_formating(char *filename)
{
    int pos = NOT_FOUND;
    char *formated = NULL;

    for (int index = 0; filename[index] != '\0'; index++) {
        if (filename[index] == '.') {
            pos = index;
        }
    }
    if (pos == NOT_FOUND)
        return NULL;
    formated = malloc(pos + my_strlen("cor") + 2);
    if (!formated)
        return NULL;
    for (int i = 0; i <= pos; i++)
        formated[i] = filename[i];
    formated[pos + 1] = '\0';
    my_strcat(formated, "cor");
    return formated;
}
