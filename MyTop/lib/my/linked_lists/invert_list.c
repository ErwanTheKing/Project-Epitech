/*
** EPITECH PROJECT, 2025
** organized
** File description:
** invert_list
*/

#include <stdlib.h>
#include "../headers/linked_lists.h"

void invert_list(node_t **head)
{
    node_t *prev = NULL;
    node_t *current = *head;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
