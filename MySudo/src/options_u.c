/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** The options u.c
*/
/**
 * @file options u.c
 * @brief The options u.c
 * @author Erwan Lo Presti
 */

#include <string.h>

#include "../include/includes.h"

char *open_passwd(void)
{
    struct stat stats;
    int fd = open("/etc/passwd", O_RDONLY);
    int stat_v = 0;
    int read_v = 0;
    char *buffer;

    stat_v = stat("/etc/passwd", &stats);
    if (stat_v == -1)
        return NULL;
    buffer = malloc(sizeof(char) * stats.st_size + 1);
    if (buffer == NULL)
        return NULL;
    read_v = read(fd, buffer, stats.st_size);
    if (read_v == -1) {
        free(buffer);
        return NULL;
    }
    close(fd);
    return buffer;
}

char **open_shadow(void)
{
    struct stat stats;
    int fd = open("/etc/shadow", O_RDONLY);
    int stat_v = 0;
    char *buffer = NULL;
    int read_v = 0;
    char **array = NULL;

    if (fd == -1)
        return NULL;
    stat_v = stat("/etc/shadow", &stats);
    if (stat_v == -1)
        return NULL;
    buffer = malloc(sizeof(char) * stats.st_size + 1);
    read_v = read(fd, buffer, stats.st_size);
    if (read_v == -1)
        return NULL;
    array = my_str_to_word_array(buffer, "\n:");
    free(buffer);
    close(fd);
    return array;
}

static int get_uid(char *user)
{
    char *buffer = open_passwd();
    char **array = my_str_to_word_array(buffer, "\n");
    char **array_tmp = NULL;
    int id = ERROR;

    free(buffer);
    for (int i = 0; array[i] != NULL; i++) {
        if (strstr(array[i], user)) {
            array_tmp = my_str_to_word_array(array[i], "\n:");
            id = my_getnbr(array_tmp[2]);
            break;
        }
    }
    free_array(array);
    free(array_tmp);
    return id;
}

static int get_guid(char *user)
{
    char *buffer = open_group();
    char **array = my_str_to_word_array(buffer, "\n");
    char **array_tmp = NULL;
    int id = ERROR;

    free(buffer);
    for (int i = 0; array[i] != NULL; i++) {
        if (strstr(array[i], user)) {
            array_tmp = my_str_to_word_array(array[i], "\n:");
            id = my_getnbr(array_tmp[2]);
            break;
        }
    }
    free_array(array);
    free(array_tmp);
    return id;
}

static int get_uidg(char *user)
{
    char *buffer = open_passwd();
    char **array = my_str_to_word_array(buffer, "\n");
    char **array_tmp = NULL;
    int id = ERROR;

    my_printf("%S\n", array);
    free(buffer);
    for (int i = 0; array[i] != NULL; i++) {
        if (strstr(array[i], user)) {
            array_tmp = my_str_to_word_array(array[i], "\n:");
            id = my_getnbr(array_tmp[3]);
            break;
        }
    }
    free_array(array);
    free(array_tmp);
    return id;
}

int set_guid(char *user)
{
    int gid = get_guid(user);

    if (gid == ERROR)
        return ERROR;
    setgid(gid);
    return SUCCESS;
}

int set_uid(char *user)
{
    int id = get_uid(user);
    int gid = get_uidg(user);

    if (id == ERROR || gid == ERROR)
        return ERROR;
    setuid(id);
    setgid(gid);
    return SUCCESS;
}
