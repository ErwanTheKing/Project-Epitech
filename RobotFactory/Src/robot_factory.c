/*
** EPITECH PROJECT, 2026
** robt
** File description:
** factory
*/

#include <stdlib.h>
#include "../lib/Headers/defines.h"
#include "../lib/Headers/factory.h"

int robot_factory(int ac, char *filename)
{
    int dest = 0;
    char *buff = NULL;
    int status = 0;

    if (is_valid_filename(filename) == FALSE)
        return FAILURE;
    dest = open(filename, O_RDONLY);
    buff = fill_buffer(dest, filename);
    if (!buff)
        return FAILURE;
    status = write_in(buff, filename);
    if (status != SUCCESS) {
        close(dest);
        free(buff);
        return status;
    }
    close(dest);
    free(buff);
    return SUCCESS;
}
