/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** push_front
*/

#include <stdlib.h>
#include "../headers/linked_lists.h"

void push_front(node_t **head, void *data)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (new_node == NULL)
        return;
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}
