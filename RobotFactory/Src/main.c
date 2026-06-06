/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Entry point: reads a CSV, writes the output and frees the dataframe
*/
/**
 * @file main.c
 * @brief Entry point: reads a CSV, writes the output and frees the dataframe
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <stdio.h>
#include <unistd.h>
#include "../lib/Headers/defines.h"
#include "../include/my.h"
#include "../lib/Headers/factory.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return FAILURE;
    if (!av[1] || av[1][0] == '\0')
        return FAILURE;
    if (my_strcmp("-h", av[1]) == 0)
        return help();
    return robot_factory(ac, av[1]);
}
