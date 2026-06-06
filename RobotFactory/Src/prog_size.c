/*
** EPITECH PROJECT, 2026
** UsineAMarvin
** File description:
** The prog_size.c
*/
/**
 * @file prog_size.c
 * @brief The prog_size.c
 * @author Erwan Lo Presti
 */

#include "../lib/Headers/defines.h"
#include "../lib/Headers/factory.h"

unsigned char prog_size(char **instruction, int start)
{
    int prog_size = 1;
    int code = get_op_index(instruction[start]);

    if (there_is_coding_byte(code) == SUCCESS)
        prog_size += 1;
    for (int i = start + 1; instruction[i]; i++) {
        if (instruction[i][0] == 'r') {
            prog_size += 1;
            continue;
        }
        if (instruction[i][0] == '%') {
            prog_size += is_index(code);
            continue;
        }
        prog_size += IND_SIZE;
    }
    return prog_size;
}
