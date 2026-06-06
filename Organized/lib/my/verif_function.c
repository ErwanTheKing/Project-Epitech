/*
** EPITECH PROJECT, 2025
** BSsetting_up
** File description:
** The my_malloc.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
