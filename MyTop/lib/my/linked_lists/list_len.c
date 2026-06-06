/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** list_len
*/

#include "../headers/linked_lists.h"
#include <stdlib.h>

int list_len(node_t *head, int len)
{
    for (; head != NULL; head = head->next)
        len++;
    return (len);
}
