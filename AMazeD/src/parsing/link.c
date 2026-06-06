/*
** EPITECH PROJECT, 2026
** amazedd
** File description:
** link
*/

#include "../../include/maze.h"

int right_link(char **argv)
{
    int len = len_array(argv);

    if (len != 2)
        return 84;
    return 0;
}

link_t *search_node(nodes_t *all_link, char *str)
{
    for (nodes_t *node = all_link; node; node = node->next)
        if (my_strcmp(((link_t *)node->data)->data, str) == 0)
            return node->data;
    return NULL;
}

int link_node(mazed_t *maze, char **argv)
{
    link_t *first = search_node(maze->all_links, argv[0]);
    link_t *second = search_node(maze->all_links, argv[1]);
    nodes_t *new = NULL;

    if (!first || !second)
        return 84;
    if (first == second)
        return 0;
    new = new_node(second);
    if (!new)
        return 84;
    push_front(&first->next, new);
    new = new_node(first);
    if (!new)
        return 84;
    push_front(&second->next, new);
    return 0;
}

int linked(mazed_t *maze, nodes_t *node, int *scene)
{
    char **argv = NULL;

    if (len_array(node->data) != 1)
        return 6;
    argv = my_strtwa(((char **)node->data)[0], "-");
    if (!argv)
        return 84;
    if (right_link(argv) == 84) {
        free_array(argv);
        return 6;
    }
    if (link_node(maze, argv) == 84) {
        free_array(argv);
        return 84;
    }
    write(1, ((char **)node->data)[0], strlen(((char **)node->data)[0]));
    write(1, "\n", 1);
    free_array(argv);
    return 0;
}
