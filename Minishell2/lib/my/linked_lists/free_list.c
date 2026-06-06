/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** free_list
*/

#include <stdlib.h>
#include "../headers/linked_lists.h"

void free_list(node_t **head)
{
    node_t *temp;
    node_t *current = *head;

    while (current != NULL) {
        temp = current->next;
        free(current->data);
        free(current);
        current = temp;
    }
    *head = NULL;
}
