/*
** EPITECH PROJECT, 2026
** create
** File description:
** robot
*/

#include "../lib/Headers/factory.h"

void big_andian(int value, unsigned char *stock)
{
    stock[0] = (value >> 24) & 0xFF;
    stock[1] = (value >> 16) & 0xFF;
    stock[2] = (value >> 8) & 0xFF;
    stock[3] = value & 0xFF;
}

void big_endian_2(int value, unsigned char *stock)
{
    stock[0] = (value >> 8) & 0xFF;
    stock[1] = value & 0xFF;
}

void fill_robot(robot_t *robot, char *buff)
{
    char *name = get_name(buff);
    char *comment = get_comment(buff);

    if (!name || !comment)
        return;
    my_strcpy(robot->name, name);
    my_strcpy(robot->comment, comment);
    free(name);
    free(comment);
    big_andian(MAGIC, robot->magic);
}

robot_t create_robot(char *buff)
{
    robot_t new = {0};

    clear_comment(buff);
    fill_robot(&new, buff);
    return new;
}
