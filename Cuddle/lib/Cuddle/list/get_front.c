/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** get_front
*/

#include "../../Headers/linked_lists.h"
#include <stdlib.h>

void *get_front(node_t *head)
{
    if (head == NULL)
        return (NULL);
    return (head->data);
}
