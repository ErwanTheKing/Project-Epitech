/*
** EPITECH PROJECT, 2026
** minishell_1
** File description:
** my_wordarray_to_linked_list
*/

#include <stddef.h>
#include "../../Headers/linked_lists.h"

node_t *my_wordarray_to_linked_list(char **word_array)
{
    node_t *list = NULL;
    int i = 0;

    if (word_array == NULL)
        return NULL;
    while (word_array[i] != NULL) {
        push_back(&list, word_array[i]);
        i++;
    }
    return list;
}
