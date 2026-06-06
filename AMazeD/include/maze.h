/*
** EPITECH PROJECT, 2026
** amazedd
** File description:
** maze
*/

#ifndef AMAZEDD_MAZE_H
    #define AMAZEDD_MAZE_H
    #include "my.h"

enum state {
    ROBOT,
    ROOM,
    LINK,
    LIFE,
    END,
};

typedef struct link {
    char *data;
    int x;
    int y;
    int viewed;
    int height;
    int wait;
    bool occuped;
    nodes_t *next;
}link_t;

typedef struct robot {
    int id;
    int x;
    int y;
    link_t *position;
    link_t *previous;
}robot_t;

typedef struct mazed {
    nodes_t *all_links;
    nodes_t *robot;
    link_t *start;
    link_t *end;
    nodes_t *argv;
}mazed_t;

int robot(mazed_t *maze, nodes_t *node, int *scene);
int linked(mazed_t *maze, nodes_t *node, int *scene);
int room(mazed_t *maze, nodes_t *node, int *scene);
int parsing(mazed_t *maze, nodes_t *argv);
int amaze(void);
void free_nodes(nodes_t *head, void (*func)(void *));
void *free_all_void(mazed_t *maze, void *exit);
int free_all(mazed_t *maze, int exit);
int start_end(mazed_t *maze, link_t *link);
int good_path(mazed_t *maze);
int robot_choice(mazed_t *maze);

nodes_t *new_robot(int id);
int create_robot(mazed_t *maze, int nb_robots);
int right_link(char **argv);
void display_robot(robot_t *robot, mazed_t *maze, nodes_t *dummy);
link_t *search_node(nodes_t *node, char *name);
int link_node(mazed_t *maze, char **argv);
void push_queue(nodes_t **q_head, nodes_t **q_tail, link_t *nb, link_t *cur);
int delete_end_robot(mazed_t *maze);
void do_height(mazed_t *maze, link_t *link);
link_t *good_choice(mazed_t *maze, robot_t *robot);
nodes_t *take_argument(void);
void inside(nodes_t **q_head, nodes_t **q_tail, mazed_t *maze);
void free_links(void *link);
mazed_t *init(void);

#endif
