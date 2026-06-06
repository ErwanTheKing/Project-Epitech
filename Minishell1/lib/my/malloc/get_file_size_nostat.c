/*
** EPITECH PROJECT, 2025
** RADAR
** File description:
** get_file_size_nostat
*/

#include <fcntl.h>
#include <unistd.h>
#include "../headers/my.h"

int get_file_size_no_stat(char const *filepath)
{
    int size = 0;
    char buffer[KB];
    int fd = open(filepath, O_RDONLY);

    if (fd < 0) {
        return FAILURE;
    }
    while (read(fd, buffer, 1) > 0) {
        size++;
    }
    close(fd);
    return size;
}
