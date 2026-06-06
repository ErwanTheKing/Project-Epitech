/*
** EPITECH PROJECT, 2026
** put
** File description:
** err
*/

#include "../lib/Headers/factory.h"
#include <unistd.h>

int put_err(const char *text)
{
    write(2, text, my_strlen(text));
    return FAILURE;
}
