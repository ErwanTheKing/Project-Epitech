/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** sort_word_array
*/

#include "../../Headers/my.h"
#include <stddef.h>

char **sort_word_array(char **array)
{
    int len = my_array_len(array);

    for (int i = 0; i < len; i++) {
        array = cmp_alpha(array, i, len);
    }
    return array;
}
