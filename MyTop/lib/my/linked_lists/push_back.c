/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** push_back²²²
*/

#include <stdlib.h>
#include "../headers/linked_lists.h"

void push_back(node_t **head, void *data)
{
    node_t *new_node = malloc(sizeof(node_t));
    node_t *temp = *head;

    if (new_node == NULL)
        return;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    for (; temp->next != NULL; temp = temp->next);
    temp->next = new_node;
}
