/*
** EPITECH PROJECT, 2025
** new_project
** File description:
** The main.c
*/

#include "../include/includes.h"

static int help(void)
{
    int fd = open("help.txt", O_RDONLY);
    char buffer[64];
    int rd;

    if (fd == -1)
        return ERROR;
    rd = read(fd, buffer, 64);
    if (rd == -1)
        return ERROR;
    write(1, buffer, 64);
    return SUCCESS;
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        help();
        return ERROR;
    }
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return help();
    return my_sudo(argv);
}
