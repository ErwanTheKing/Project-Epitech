/*
** EPITECH PROJECT, 2026
** amazedd
** File description:
** robot_choice
*/

#include "../../include/maze.h"

static link_t *init_link(mazed_t *maze, link_t *link, robot_t *robot)
{
    if (link != maze->end) {
        link->occuped = true;
    }
    if (robot->position != maze->start) {
        robot->position->occuped = false;
    }
    return link;
}

link_t *good_choice(mazed_t *maze, robot_t *robot)
{
    link_t *cur = NULL;

    for (nodes_t *tmp = robot->position->next; tmp; tmp = tmp->next) {
        if (((link_t *)tmp->data)->height == -1 || ((link_t *)tmp->data)->
            occuped == true || tmp->data == maze->start ||
            tmp->data == robot->position || robot->previous == tmp->data)
            continue;
        if (!cur || (((link_t *)tmp->data)->height + ((link_t *)tmp->data)
                ->wait < cur->height + cur->wait)) {
            cur = tmp->data;
        }
    }
    if (!cur)
        return robot->position;
    init_link(maze, cur, robot);
    return cur;
}

void display_robot(robot_t *robot, mazed_t *maze, nodes_t *first)
{
    if (first != maze->robot)
        write(1, " ", 1);
    write(1, "P", 1);
    my_put_nbr(robot->id);
    write(1, "-", 1);
    write(1, robot->position->data, my_strlen(robot->position->data));
}

void in_list(nodes_t **prev, nodes_t **cur, mazed_t *maze)
{
    nodes_t *next = (*cur)->next;

    if (((robot_t *)(*cur)->data)->position == maze->end) {
        if (*prev)
            (*prev)->next = next;
        else
            maze->robot = next;
        free((*cur)->data);
        free(*cur);
    } else {
        *prev = *cur;
    }
    *cur = next;
}

int delete_end_robot(mazed_t *maze)
{
    nodes_t *prev = NULL;
    nodes_t *cur = maze->robot;

    while (cur)
        in_list(&prev, &cur, maze);
    return 0;
}

static void do_wait(mazed_t *maze, robot_t *robot)
{
    link_t *link = NULL;

    for (nodes_t *tmp = robot->position->next; tmp; tmp = tmp->next) {
        if (!link || (tmp->data != maze->end && tmp->data != maze->start &&
                ((link_t *)tmp->data)->height + ((link_t *)tmp->data)->wait <
                robot->position->height && ((link_t *)tmp->data)->height != -1
                && robot->previous != tmp->data))
            link = tmp->data;
    }
    if (!link)
        return;
    link->wait += 1;
}

int robot_choice(mazed_t *maze)
{
    link_t *curr = NULL;

    for (nodes_t *cur = maze->all_links; cur; cur = cur->next)
        ((link_t *)cur->data)->wait = 0;
    for (nodes_t *robot = maze->robot; robot; robot = robot->next) {
        if (((robot_t *)robot->data)->position != maze->start)
            ((robot_t *)robot->data)->position->wait += 1;
        do_wait(maze, robot->data);
    }
    maze->end->wait = 0;
    for (nodes_t *robot = maze->robot; robot; robot = robot->next) {
        curr = ((robot_t *)robot->data)->position;
        ((robot_t *)robot->data)->position = good_choice(maze, robot->data);
        ((robot_t *)robot->data)->previous = curr;
        if (((robot_t *)robot->data)->position != maze->start)
            display_robot(robot->data, maze, robot);
    }
    write(1, "\n", 1);
    delete_end_robot(maze);
    return 0;
}
