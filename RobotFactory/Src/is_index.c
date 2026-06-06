/*
** EPITECH PROJECT, 2026
** UsineAMarvin
** File description:
** The is_index.c
*/
/**
 * @file is_index.c
 * @brief The is_index.c
 * @author Erwan Lo Presti
 */

#include "../lib/Headers/defines.h"
#include "../lib/Headers/struct.h"

int is_index(int code)
{
    if (code == 9 || code == 10 || code == 11 || code == 12 || code == 15
        || code == 14)
        return IND_SIZE;
    return DIR_SIZE;
}
