/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** get_file_size
*/

#include <sys/stat.h>

int get_file_size_stat(char *filepath)
{
    struct stat statstruct;

    if (stat(filepath, &statstruct) == -1)
        return -84;
    return statstruct.st_size;
}
