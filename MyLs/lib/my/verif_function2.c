/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** The verif_function2.c
*/

#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "../../include/struct.h"

int verif_opendir(DIR *dir)
{
    if (dir == NULL) {
        return 84;
    }
    return 0;
}

int verif_readdir(struct dirent *dir)
{
    if (dir == NULL) {
        my_printf("%m\n", "Error with readdir");
    }
    return 0;
}

int verif_moptions(options_t *options)
{
    if (options == NULL) {
        my_printf("%m\n", "Error with memory");
    }
    return 0;
}

void verif(DIR *dir, struct dirent *struct_dir)
{
    verif_readdir(struct_dir);
}
