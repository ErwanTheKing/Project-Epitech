/*
** EPITECH PROJECT, 2025
** bootstrap_setting_up
** File description:
** openator
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/my.h"

int check_open(int fd)
{
    if (fd < 0) {
        return FAILURE;
    }
    return SUCCESS;
}

int check_read(char *buffer, int bytes_read)
{
    if (bytes_read < 0) {
        write(2, "READ FAILURE\n", 13);
        free(buffer);
        return FAILURE;
    }
    if (bytes_read == 0) {
        write(2, "FILE IS EMPTY\n", 14);
        free(buffer);
        return FAILURE;
    }
    return SUCCESS;
}

int check_buffer(char *buffer)
{
    if (!buffer) {
        write(2, "BUFFER MEMORY ALLOCATION FAILURE\n", 26);
        return FAILURE;
    }
    return SUCCESS;
}

char *openator(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = get_file_size_no_stat(filepath);
    char *buffer;
    int bytes_read;

    if (check_open(fd) == FAILURE)
        return NULL;
    buffer = malloc(sizeof(char) * (size + 1));
    if (check_buffer(buffer) == FAILURE) {
        close(fd);
        return NULL;
    }
    bytes_read = read(fd, buffer, size);
    if (check_read(buffer, bytes_read) == FAILURE) {
        close(fd);
        return NULL;
    }
    buffer[bytes_read] = '\0';
    close(fd);
    return buffer;
}
