/*
** EPITECH PROJECT, 2025
** new_project
** File description:
** The main.c
*/

#include "include/includes.h"

static void description(void)
{
    int fd = open("help.txt", O_RDONLY);
    char str[362];

    if (!fd)
        return;
    read(fd, str, 362);
    write(1, str, 362);
}

int main(int argc, char **argv)
{
    if (argc > 2)
        return EXIT_F;
    if (argc == 2 && my_strcmp(argv[1], "-h") != 0) {
        return EXIT_F;
    }
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        description();
        return EXIT_SUCCESS;
    }
    return create_window();
}
