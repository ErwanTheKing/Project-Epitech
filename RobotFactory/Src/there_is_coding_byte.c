/*
** EPITECH PROJECT, 2026
** UsineAMarvin
** File description:
** The there_is_coding_byte.c
*/
/**
 * @file there_is_coding_byte.c
 * @brief The there_is_coding_byte.c
 * @author Erwan Lo Presti
 */

#include "../lib/Headers/defines.h"

int there_is_coding_byte(int code)
{
    if (code == 1 || code == 9 || code == 12 || code == 15)
        return FAILURE;
    return SUCCESS;
}
