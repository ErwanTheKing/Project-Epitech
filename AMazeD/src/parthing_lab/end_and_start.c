/*
** EPITECH PROJECT, 2026
** amazedd
** File description:
** algo
*/

#include "../../include/maze.h"

int start_end(mazed_t *maze, link_t *link)
{
    if (link == NULL || link->viewed == 1)
        return 1;
    link->viewed = 1;
    if (my_strcmp(maze->end->data, link->data) == 0) {
        link->viewed = 0;
        return 0;
    }
    for (nodes_t *tmp = link->next; tmp; tmp = tmp->next) {
        if (start_end(maze, tmp->data) == 0) {
            link->viewed = 0;
            return 0;
        }
    }
    link->viewed = 0;
    return 84;
}
