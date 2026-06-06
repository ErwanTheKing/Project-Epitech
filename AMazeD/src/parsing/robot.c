/*
** EPITECH PROJECT, 2026
** amazedd
** File description:
** robot
*/

#include "../../include/maze.h"

nodes_t *new_robot(int id)
{
    robot_t *robot = malloc(sizeof(robot_t));

    if (!robot)
        return NULL;
    robot->id = id;
    robot->x = 0;
    robot->y = 0;
    robot->position = NULL;
    robot->previous = NULL;
    return new_node(robot);
}

int create_robot(mazed_t *maze, int nmb)
{
    nodes_t *robot = NULL;

    if (nmb == 0)
        return 84;
    for (int id = nmb; id > 0; id--) {
        robot = new_robot(id);
        if (!robot)
            return 84;
        push_front(&maze->robot, robot);
    }
    return 0;
}

int robot(mazed_t *maze, nodes_t *node, int *scene)
{
    char **data = NULL;

    if (!node || !node->data)
        return 84;
    data = node->data;
    if (my_str_isnum(data[0]) != 0 || len_array(data) != 1)
        return 84;
    write(1, "#number_of_robots\n", 18);
    write(1, data[0], my_strlen(data[0]));
    write(1, "\n", 1);
    write(1, "#rooms\n", 7);
    *scene = ROOM;
    return create_robot(maze, my_getnbr(data[0]));
}
