/*
** EPITECH PROJECT, 2026
** ~/Epitech/Project/Corewar/Src
** File description:
** main
*/

#include "../lib/Headers/corewar.h"

int main(int argc, char **argv)
{
    if (my_help(argc, argv) == FALSE)
        return puterr(RETRY_HELP);
    if (my_strcmp(argv[1], "-h") == 0)
        return SUCCESS;
    if (argc < 3)
        return puterr(NOT_ENOUGHT_ARG);
    if (check_corewar(argc, argv) == FALSE)
        return FAILURE;
    return corewar(argc, argv);
}
