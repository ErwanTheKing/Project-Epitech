/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** The sudoers.c
*/
/**
 * @file sudoers.c
 * @brief The sudoers.c
 * @author Erwan Lo Presti
 */

#include <string.h>

#include "../include/includes.h"

static char *open_sudoers(void)
{
    int fd = open("/etc/sudoers", O_RDONLY);
    struct stat stats;
    char *buffer = NULL;

    if (fd == -1)
        return NULL;
    if (stat("/etc/sudoers", &stats) == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    if (!buffer)
        return NULL;
    if (read(fd, buffer, stats.st_size) == -1) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

char *open_group(void)
{
    int fd = open("/etc/group", O_RDONLY);
    struct stat stats;
    char *buffer = NULL;

    if (fd == -1)
        return NULL;
    if (stat("/etc/group", &stats) == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    if (!buffer)
        return NULL;
    if (read(fd, buffer, stats.st_size) == -1) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

static int verif_user(char **array, char *user)
{
    int i = 0;
    int id = getuid();

    while (my_strcmp(array[i],
            "# Members of the admin group may gain root privileges") != 0) {
        if (strstr(array[i], user))
            return SUCCESS;
        if (my_getnbr(array[i]) == id)
            return SUCCESS;
        i++;
    }
    return ERROR;
}

static int search_group(char **array_group, char **array, int i, char *user)
{
    if (strstr(array_group[i], array[0] + 1)) {
        if (strstr(array_group[i], user)) {
            return SUCCESS;
        }
    }
    return ERROR;
}

static int verif_group(char *str, char *user)
{
    char **array = my_str_to_word_array(str, " \t");
    char *buffer = open_group();
    char **array_group = my_str_to_word_array(buffer, "\n");

    free(buffer);
    for (int i = 0; array_group[i] != NULL; i++) {
        if (search_group(array_group, array, i, user) == SUCCESS)
            return SUCCESS;
    }
    free_array(array_group);
    free_array(array);
    return ERROR;
}

static int search_idgroup(char **array_group, char **array, int i, char *user)
{
    char **array_tmp = my_str_to_word_array(array_group[i], "\n:");

    if (strstr(array_group[i], array[0] + 2)) {
        if (strstr(array_group[i], user)) {
            free_array(array_tmp);
            return SUCCESS;
        }
    }
    free_array(array_tmp);
    return ERROR;
}

static int verif_idgroup(char *str, char *user)
{
    char **array = my_str_to_word_array(str, " \t");
    char *buffer = open_group();
    char **array_group = my_str_to_word_array(buffer, "\n");

    free(buffer);
    for (int i = 0; array_group[i] != NULL; i++) {
        if (search_idgroup(array_group, array, i, user) == SUCCESS)
            return SUCCESS;
    }
    free_array(array_group);
    free_array(array);
    return ERROR;
}

static int check_group(char **array, int i, char *user)
{
    if (array[i][0] == '%') {
        if (verif_group(array[i], user) == SUCCESS)
            return SUCCESS;
        if (verif_idgroup(array[i], user) == SUCCESS)
            return SUCCESS;
    }
    return ERROR;
}

static void write_message(char *user)
{
    write(2, "\n", 1);
    write(2, user, my_strlen(user));
    write(2, " is not in the my_sudoers file.\n", 32);
}

int verif_sudoers(char *user)
{
    char *buffer = open_sudoers();
    char **array = my_str_to_word_array(buffer, "\n");

    free(buffer);
    for (int i = 0; array[i] != NULL; i++) {
        if (my_strcmp(array[i],
                "# User privilege specification") == 0) {
            array = array + i;
            break;
        }
    }
    for (int i = 0; array[i] != NULL; i++) {
        if (check_group(array, i, user) == SUCCESS)
            return SUCCESS;
    }
    if (verif_user(array, user) == SUCCESS)
        return SUCCESS;
    write_message(user);
    return ERROR;
}
