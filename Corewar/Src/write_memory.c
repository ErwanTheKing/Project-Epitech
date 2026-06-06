/*
** EPITECH PROJECT, 2026
** ~/Epitech/Project/Corewar/Src
** File description:
** write_memory
*/

#include "../lib/Headers/corewar.h"

void write_memory(unsigned char *memory)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0) {
            write_address(i);
            write(1, ": ", 2);
        }
        write_hex(memory[i]);
        if (i % 32 == 31)
            my_putchar('\n');
        else
            write(1, " ", 1);
    }
}
