/*
** EPITECH PROJECT, 2026
** My_Top
** File description:
** count_runnings
*/

#include <dirent.h>
#include <stdlib.h>
#include "../../include/my_top.h"
#include "../../lib/my/headers/my.h"
#include <unistd.h>

int count_runnings(void)
{
    DIR *proc = opendir(PROC_PATH);
    struct dirent *entry = NULL;
    int count = 0;

    if (!proc)
        return FAILURE;
    for (entry = readdir(proc); entry != NULL; entry = readdir(proc)) {
        if (my_getnbr(entry->d_name) > 0)
            count += 1;
    }
    closedir(proc);
    return count;
}
