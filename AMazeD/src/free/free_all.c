/*
** EPITECH PROJECT, 2026
** amazedd
** File description:
** free_array
*/

#include "../../include/maze.h"

void free_nodes(nodes_t *head, void (*func)(void *))
{
    for (nodes_t *current = head; current;) {
        head = head->next;
        if (current->data)
            func(current->data);
        free(current);
        current = head;
    }
}

void free_links(void *link)
{
    nodes_t *current = ((link_t *)link)->next;
    nodes_t *forward = NULL;

    forward = current;
    while (current) {
        forward = forward->next;
        if (current->data)
            free(current);
        current = forward;
    }
    free(link);
}

int free_all(mazed_t *maze, int exit)
{
    if (maze->argv)
        free_nodes(maze->argv, free_array_void);
    if (maze->robot)
        free_nodes(maze->robot, free);
    if (maze->all_links)
        free_nodes(maze->all_links, free_links);
    free(maze);
    return exit;
}

void *free_all_void(mazed_t *maze, void *exit)
{
    if (maze->argv)
        free_nodes(maze->argv, free_array_void);
    if (maze->robot)
        free_nodes(maze->robot, free);
    if (maze->all_links)
        free_nodes(maze->all_links, free_links);
    free(maze);
    return exit;
}
