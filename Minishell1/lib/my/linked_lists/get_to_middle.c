/*
** EPITECH PROJECT, 2025
** organized
** File description:
** get_to_middle
*/

#include <stdlib.h>
#include "../headers/linked_lists.h"

node_t *get_to_middle(node_t *head)
{
    node_t *slow = head;
    node_t *fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}
