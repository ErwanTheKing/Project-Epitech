/*
** EPITECH PROJECT, 2026
** amazedd
** File description:
** amazed
*/

#include "../include/maze.h"

int command_right(char *line)
{
    if (my_strcmp(line, "##end\n") == 0 || my_strcmp(line, "##start\n") == 0)
        return 0;
    return 1;
}

nodes_t *take_argument(void)
{
    nodes_t *res = NULL;
    size_t n = 0;
    char *line = NULL;

    for (nodes_t *tmp = NULL; getline(&line, &n, stdin) != EOF; tmp = NULL) {
        if (line[0] == '#' && command_right(line) != 0)
            continue;
        tmp = new_node(my_strtwa(my_strn(line, '#'), " \t\n"));
        if (!tmp)
            continue;
        push_back(&res, tmp);
    }
    return my_free_void((void*[]){line}, 1, res);
}

mazed_t *init(void)
{
    mazed_t *maze = malloc(sizeof(mazed_t));
    nodes_t *argv = NULL;

    if (!maze)
        return NULL;
    maze->all_links = NULL;
    maze->robot = NULL;
    maze->end = NULL;
    maze->start = NULL;
    argv = take_argument();
    if (!argv)
        return my_free_void((void*[]){maze}, 1, NULL);
    maze->argv = argv;
    if (parsing(maze, argv) == 84)
        return free_all_void(maze, NULL);
    return maze;
}

int amaze(void)
{
    mazed_t *maze = init();
    int exit = 0;

    if (maze == NULL)
        return 84;
    exit = good_path(maze);
    if (exit == 0)
        while (maze->robot)
            robot_choice(maze);
    return free_all(maze, exit);
}
