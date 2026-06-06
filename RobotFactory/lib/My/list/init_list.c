/*
** EPITECH PROJECT, 2025
** organized
** File description:
** init_list
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../Headers/linked_lists.h"

node_t *init_list(void *data)
{
    node_t *head = malloc(sizeof(node_t));

    if (head == NULL) {
        write(2, "MALLOC FAILURE\n", 15);
        return NULL;
    }
    head->data = data;
    head->next = NULL;
    return head;
}
