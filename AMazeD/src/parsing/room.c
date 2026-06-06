/*
** EPITECH PROJECT, 2026
** amazedd
** File description:
** room
*/

#include <float.h>

#include "../../include/maze.h"

static int is_that_room(char **argv)
{
    int len = len_array(argv);

    if (len < 3)
        return 2;
    if (len > 3 || my_str_isnum(argv[1]) != 0 || my_str_isnum(argv[2]) != 0)
        return 84;
    return 0;
}

static void print_room(char **argv)
{
    write(1, argv[0], my_strlen(argv[0]));
    write(1, " ", 1);
    write(1, argv[1], my_strlen(argv[1]));
    write(1, " ", 1);
    write(1, argv[2], my_strlen(argv[2]));
    write(1, "\n", 1);
}

static void filled(link_t *start, char **argv, bool occuped)
{
    start->data = argv[0];
    start->x = my_getnbr(argv[1]);
    start->y = my_getnbr(argv[2]);
    start->viewed = 0;
    start->wait = 0;
    start->occuped = occuped;
    start->height = -1;
    start->next = NULL;
}

static int new_start(mazed_t *maze, nodes_t *data)
{
    char **argv = data->data;
    link_t *start = NULL;
    nodes_t *node = NULL;
    int check = is_that_room(argv);

    if (check != 0)
        return check;
    start = malloc(sizeof(link_t));
    if (!start || maze->start != NULL)
        return my_free((void*[]){start}, 1, 84);
    filled(start, argv, true);
    maze->start = start;
    node = new_node(start);
    if (node == NULL)
        return my_free((void*[]){start}, 1, 84);
    push_front(&maze->all_links, node);
    print_room(argv);
    return 1;
}

static int new_end(mazed_t *maze, nodes_t *data)
{
    char **argv = data->data;
    link_t *end = NULL;
    nodes_t *node = NULL;
    int check = is_that_room(argv);

    if (check != 0)
        return check;
    end = malloc(sizeof(link_t));
    if (!end || maze->end != NULL)
        return my_free((void*[]){end}, 1, 84);
    filled(end, argv, false);
    maze->end = end;
    node = new_node(end);
    if (node == NULL)
        return my_free((void*[]){end}, 1, 84);
    push_front(&maze->all_links, node);
    print_room(argv);
    return 1;
}

static int already_here(nodes_t *nodes, char *name)
{
    for (nodes_t *node = nodes; node; node = node->next)
        if (my_strcmp(((link_t *)node->data)->data, name) == 0)
            return 84;
    return 0;
}

static int add_room(mazed_t *maze, nodes_t *data)
{
    char **argv = data->data;
    link_t *room = NULL;
    nodes_t *node = NULL;
    int check = is_that_room(argv);

    if (check != 0)
        return check;
    room = malloc(sizeof(link_t));
    if (!room || already_here(maze->all_links, argv[0]) == 84)
        return my_free((void*[]){room}, 1, 84);
    filled(room, argv, false);
    node = new_node(room);
    if (node == NULL)
        return my_free((void*[]){room}, 1, 84);
    push_front(&maze->all_links, node);
    print_room(argv);
    return 0;
}

static int is_it_right_format(nodes_t *node, mazed_t *maze)
{
    char **data = node->data;
    int len = len_array(data);

    if (my_strcmp(data[0], "##start") == 0 && len == 1) {
        write(1, "##start\n", 8);
        if (node->next)
            return new_start(maze, node->next);
    }
    if (my_strcmp(data[0], "##end") == 0 && len == 1) {
        write(1, "##end\n", 6);
        if (node->next)
            return new_end(maze, node->next);
    }
    return add_room(maze, node);
}

int room(mazed_t *maze, nodes_t *node, int *scene)
{
    int res = 0;

    if (!node || !node->data)
        return 84;
    res = is_it_right_format(node, maze);
    if (res == 2) {
        if (!maze->start || !maze->end)
            return 84;
        *scene = LINK;
        write(1, "#tunnels\n", 9);
        return res;
    }
    return res;
}
