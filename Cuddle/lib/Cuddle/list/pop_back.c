/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** pop_back
*/

#include <stdlib.h>
#include "../../Headers/linked_lists.h"

void pop_back(node_t **head)
{
    node_t *temp = *head;
    node_t *to_delete;

    if (*head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    for (; temp->next->next != NULL; temp = temp->next);
    to_delete = temp->next;
    temp->next = NULL;
    free(to_delete);
}
