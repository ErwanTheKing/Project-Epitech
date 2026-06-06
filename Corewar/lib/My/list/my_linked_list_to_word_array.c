/*
** EPITECH PROJECT, 2026
** minishell_1
** File description:
** my_linked_list_to_word_array
*/

#include <stdlib.h>
#include <unistd.h>

#include "../../Headers/my.h"
#include "../../Headers/linked_lists.h"

static int fill_word_array(char **word_array, node_t *list)
{
    int i = 0;

    while (list != NULL) {
        word_array[i] = my_strdup(list->data, 0);
        if (word_array[i] == NULL) {
            free_many_arrays(1, word_array);
            return FAILURE;
        }
        list = list->next;
        i++;
    }
    word_array[i] = NULL;
    return SUCCESS;
}

char **my_linked_list_to_word_array(node_t *list)
{
    char **word_array = NULL;

    if (list == NULL)
        return NULL;
    word_array = malloc(sizeof(char *) * (list_len(list, 0) + 1));
    if (word_array == NULL) {
        write(2, "MALLOC FAILURE\n", 15);
        return NULL;
    }
    if (fill_word_array(word_array, list) == FAILURE)
        return NULL;
    return word_array;
}
