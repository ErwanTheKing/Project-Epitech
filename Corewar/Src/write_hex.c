/*
** EPITECH PROJECT, 2026
** ~/Epitech/Project/Corewar/Src
** File description:
** write_hex
*/

#include "corewar.h"

void write_hex(unsigned char byte)
{
    char hex[] = "0123456789ABCDEF";
    char c;

    c = hex[(byte >> 4) & 0xF];
    write(1, &c, 1);
    c = hex[byte & 0xF];
    write(1, &c, 1);
}
