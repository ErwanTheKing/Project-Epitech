/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** insert_node
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../Headers/linked_lists.h"

static node_t *create_node(void *data)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node) {
        write(2, "MALLOC FAILURE\n", 15);
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

static node_t *find_pos(node_t *head, int pos)
{
    int i = 0;

    while (head != NULL && i < pos - 1) {
        head = head->next;
        i++;
    }
    return head;
}

void insert_node(node_t **head, void *data, int pos)
{
    node_t *new_node;
    node_t *temp;

    if (head == NULL)
        return;
    new_node = create_node(data);
    if (new_node == NULL)
        return;
    if (pos == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    temp = find_pos(*head, pos);
    if (temp == NULL) {
        free(new_node);
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}
