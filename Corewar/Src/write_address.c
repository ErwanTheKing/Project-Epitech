/*
** EPITECH PROJECT, 2026
** ~/Epitech/Project/Corewar/Src
** File description:
** write_adress
*/

#include "../lib/Headers/corewar.h"

void write_address(unsigned int value)
{
    unsigned char bytes[4];

    for (int i = 0; i < 4; i++)
        bytes[3 - i] = (value >> (i * 8)) & 0xFF;
    for (int i = 0; i < 4; i++)
        write_hex(bytes[i]);
}
