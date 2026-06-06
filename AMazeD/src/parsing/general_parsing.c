/*
** EPITECH PROJECT, 2026
** amazedd
** File description:
** general_parsing
*/

#include "../../include/maze.h"

int parsing(mazed_t *maze, nodes_t *argv)
{
    int (*func[])(mazed_t *, nodes_t *, int *) = {robot, room, linked};
    int scene = ROBOT;
    int check = 0;

    for (nodes_t *tmp = argv; tmp;) {
        check = func[scene](maze, tmp, &scene);
        if (check == 6)
            break;
        if (check == 84)
            return 84;
        if (check == 0 || check == 1)
            tmp = tmp->next;
        if (check == 1)
            tmp = tmp->next;
    }
    return 0;
}
