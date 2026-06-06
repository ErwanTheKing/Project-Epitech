/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** get_back
*/

#include "../../Headers/linked_lists.h"
#include <stdlib.h>

void *get_back(node_t *head)
{
    node_t *temp = head;

    if (temp == NULL)
        return NULL;
    for (; temp->next != NULL; temp = temp->next);
    return temp->data;
}
