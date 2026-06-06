/*
** EPITECH PROJECT, 2026
** minishell_1
** File description:
** my_linked_list_to_word_array
*/

#include <stdlib.h>

#include "../headers/my.h"
#include "../headers/linked_lists.h"

char **my_linked_list_to_word_array(node_t *list)
{
    char **word_array = NULL;
    int i = 0;

    if (list == NULL)
        return NULL;
    word_array = malloc(sizeof(char *) * (list_len(list, 0) + 1));
    if (word_array == NULL)
        return NULL;
    while (list != NULL) {
        word_array[i] = my_strdup(list->data, 0);
        if (word_array[i] == NULL) {
            free_many_arrays(1, word_array);
            return NULL;
        }
        list = list->next;
        i++;
    }
    word_array[i] = NULL;
    return word_array;
}
