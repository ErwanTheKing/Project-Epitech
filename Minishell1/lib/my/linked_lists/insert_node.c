/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** insert_node
*/

#include <stdlib.h>
#include "../headers/linked_lists.h"

void insert_node(node_t **head, void *data, int pos)
{
    node_t *new_node = malloc(sizeof(node_t));
    node_t *temp = *head;
    int i = 0;

    if (!new_node)
        return;
    new_node->data = data;
    new_node->next = NULL;
    if (pos == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    for (; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL)
        return;
    new_node->next = temp->next;
    temp->next = new_node;
}
