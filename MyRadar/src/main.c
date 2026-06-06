/*
** EPITECH PROJECT, 2025
** new_project
** File description:
** The main.c
*/



#include "../include/includes.h"

static int help(void)
{
    char buffer[289];
    int fd = open("help.txt", O_RDONLY);

    if (fd == -1)
        return FAILURE;
    read(fd, buffer, 289);
    write(1, buffer, 289);
    close(fd);
    return SUCCESS;
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return help();
    if (argc != 2) {
        write(2, "./my_radar: bad arguments: 0 given but 84 is required\n"
            , 54);
        write(2, "retry with -h\n", 14);
        return FAILURE;
    }
    return create_window(argv);
}
