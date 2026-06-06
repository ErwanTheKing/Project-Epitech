/*
** EPITECH PROJECT, 2026
** amazedd
** File description:
** algo
*/

#include "../../include/maze.h"

void push_queue(nodes_t **q_head, nodes_t **q_tail, link_t *nb, link_t *cur)
{
    nodes_t *node = NULL;

    if (nb->height != -1)
        return;
    nb->height = cur->height + 1;
    node = new_node(nb);
    if (!node)
        return;
    if (!*q_tail) {
        *q_head = node;
        *q_tail = node;
        return;
    }
    (*q_tail)->next = node;
    *q_tail = node;
}

void inside(nodes_t **q_head, nodes_t **q_tail, mazed_t *maze)
{
    link_t *cur = (*q_head)->data;
    nodes_t *next = (*q_head)->next;
    link_t *nb = NULL;

    free(*q_head);
    *q_head = next;
    if (!*q_head)
        *q_tail = NULL;
    for (nodes_t *tmp = cur->next; tmp; tmp = tmp->next) {
        if (tmp->data == maze->start)
            continue;
        nb = tmp->data;
        push_queue(q_head, q_tail, nb, cur);
    }
}

void do_height(mazed_t *maze, link_t *link)
{
    nodes_t *q_head = NULL;
    nodes_t *q_tail = NULL;

    if (link == NULL || maze == NULL)
        return;
    link->height = 0;
    q_head = new_node(link);
    q_tail = q_head;
    while (q_head)
        inside(&q_head, &q_tail, maze);
}

int good_path(mazed_t *maze)
{
    if (!maze->end || !maze->start)
        return 84;
    if (start_end(maze, maze->start) != 0)
        return 84;
    do_height(maze, maze->end);
    maze->end->height = 0;
    for (nodes_t *robot = maze->robot; robot; robot = robot->next)
        ((robot_t *)robot->data)->position = maze->start;
    write(1, "#moves\n", 7);
    return 0;
}
