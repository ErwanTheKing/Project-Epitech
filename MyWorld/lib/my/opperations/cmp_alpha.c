/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** cmp_alpha
*/

#include "../headers/my.h"

char **cmp_alpha(char **array, int to_cmp, int len)
{
    char *temp;

    for (int j = 0; j < len; j++) {
        if (my_strcmp(array[to_cmp], array[j]) < 0) {
            temp = array[j];
            array[j] = array[to_cmp];
            array[to_cmp] = temp;
        }
    }
    return array;
}
