/*
** EPITECH PROJECT, 2026
** help
** File description:
** help
*/

#include "../lib/Headers/defines.h"
#include "../lib/Headers/my.h"

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./robot-factory file_name[.s]\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("file_name file in assembly language to be ");
    my_putstr("converted into file_name.cor, an executable in the Virtual\n");
    my_putstr("Machine.\n");
    return SUCCESS;
}
