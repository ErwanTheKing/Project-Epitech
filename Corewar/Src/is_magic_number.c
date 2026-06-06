/*
** EPITECH PROJECT, 2026
** ~/Epitech/Project/Corewar/Src
** File description:
** is_magic_number
*/

#include "../lib/Headers/corewar.h"

int is_magic_number(int nb)
{
    int magic = __builtin_bswap32(nb);

    if (magic == COREWAR_EXEC_MAGIC)
        return SUCCESS;
    return FAILURE;
}
