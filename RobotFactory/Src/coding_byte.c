/*
** EPITECH PROJECT, 2026
** UsineAMarvin
** File description:
** The coding_byte.c
*/
/**
 * @file coding_byte.c
 * @brief The coding_byte.c
 * @author Erwan Lo Presti
 */

#include "../lib/Headers/my.h"
#include "../lib/Headers/factory.h"

static unsigned char get_type_code(char *arg)
{
    if (arg[0] == 'r')
        return 1;
    if (arg[0] == '%')
        return 2;
    return 3;
}

static unsigned char count_coding_byte(char **instruction)
{
    unsigned char coding_byte = 0;

    for (int i = 1; instruction[i]; i++) {
        coding_byte |= get_type_code(instruction[i]) << (6 - (i - 1) * 2);
    }
    return coding_byte;
}

unsigned char coding_byte(char **instruction, int code)
{
    if (code == 1 || code == 9 || code == 12 || code == 15)
        return -1;
    return count_coding_byte(instruction);
}
