/*
** EPITECH PROJECT, 2026
** ~/Epitech/Project/Corewar/Src
** File description:
** init_vm
*/

#include "../lib/Headers/corewar.h"

void init_vm(prog_t *vm)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        vm->memory[i] = 0;
        vm->owner[i] = 0;
    }
    vm->nb_cycle = -1;
    vm->cycle = 0;
    vm->last_live = NULL;
}
