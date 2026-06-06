/*
** EPITECH PROJECT, 2025
** BSsetting_up
** File description:
** The my_malloc.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int verif_malloc(char *str)
{
    if (str == NULL) {
        write(2, "Error with memory\n", 20);
        return 84;
    }
    return 0;
}

int verif_mstat(struct stat *stats)
{
    if (stats == NULL) {
        write(2, "Error with memory\n", 20);
        return 84;
    }
    return 0;
}

int verif_open(int fd)
{
    if (fd == -1) {
        write(2, "Error with file\n", 18);
        return 84;
    }
    return 0;
}

int verif_read(int return_read)
{
    if (return_read == -1) {
        write(2, "Error with read\n", 18);
        return 84;
    }
    return 0;
}

int verif_stat(int stat)
{
    if (stat == -1) {
        write(2, "Error with stat\n", 18);
        return 84;
    }
    return 0;
}
