/*
** EPITECH PROJECT, 2025
** organized
** File description:
** init_list
*/

#include <stdlib.h>
#include "../headers/linked_lists.h"

node_t *init_list(void *data)
{
    node_t *head = malloc(sizeof(node_t));

    if (head == NULL)
        return NULL;
    head->data = data;
    head->next = NULL;
    return head;
}
