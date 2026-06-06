/*
** EPITECH PROJECT, 2026
** amazedd
** File description:
** nodes
*/

#include "my.h"

nodes_t *new_node(void *data)
{
    nodes_t *node = malloc(sizeof(nodes_t));

    if (!node)
        return NULL;
    if (!data) {
        free(node);
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void push_front(nodes_t **head, nodes_t *new)
{
    new->next = *head;
    *head = new;
}
