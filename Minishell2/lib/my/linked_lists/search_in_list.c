/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** search_in_list
*/

#include "../headers/linked_lists.h"
#include "../headers/my.h"
#include <stdlib.h>

int search_in_list(const node_t *head,
    void *data, int (*cmp_func)(void *, void *))
{
    int pos = 0;

    for (; head != NULL; head = head->next) {
        pos++;
        if (cmp_func(head->data, data) == 0)
            return (pos);
    }
    return FAILURE;
}
