/*
** EPITECH PROJECT, 2025
** organized
** File description:
** attach_list_to_back
*/

#include <stdlib.h>
#include "../../Headers/linked_lists.h"

void attach_list_to_back(node_t **head, node_t *to_attach)
{
    node_t *current;

    if (head == NULL)
        return;
    if (*head == NULL) {
        *head = to_attach;
        return;
    }
    current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = to_attach;
}
