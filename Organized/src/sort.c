/*
** EPITECH PROJECT, 2025
** organized
** File description:
** The sort.c
*/
/**
 * @file sort.c
 * @brief The sort.c
 * @author Erwan Lo Presti
 */

#include "../include/includes.h"

static int verif_sort(char **args, int sort)
{
    char *tag[4] = {"TYPE", "NAME", "ID", NULL};
    int good_tag = 0;
    char *str = my_strdup(args[sort]);

    for (int i = 0; tag[i] != NULL; i++) {
        if (my_strcmp(my_strupcase(str), tag[i]) == 0) {
            good_tag = 1;
            break;
        }
    }
    if (good_tag == 0) {
        write(2, "The tag is not good\n", 20);
        free(str);
        return ERROR;
    }
    free(str);
    return SUCCESS;
}

int sort(void *data, char **args)
{
    int sort = 0;
    bool reverse = false;

    while (args[sort] != NULL) {
        if (args[sort + 1] != NULL && my_strcmp(args[sort + 1], "-r") == 0)
            reverse = true;
        if (verif_sort(args, sort) == SUCCESS) {
            return SUCCESS;
        }
        if (reverse == true) {
            sort += 2;
            reverse = false;
        } else {
            sort++;
        }
    }
    return SUCCESS;
}
