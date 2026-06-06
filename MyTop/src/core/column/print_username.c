/*
** EPITECH PROJECT, 2026
** My_Top
** File description:
** print_username
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../../../include/my_top.h"
#include "../../../include/my.h"

static char *find_line_in_file(char *path)
{
    char *temp = NULL;
    char *file_content = NULL;
    char *line = NULL;
    char *dup_line;

    if (!path)
        return NULL;
    temp = my_strconcat(path, "/status");
    if (!temp)
        return NULL;
    file_content = openator(temp);
    if (!file_content)
        return free_many(1, temp);
    line = my_strstr(file_content, "Uid:");
    if (!line)
        return free_many(2, file_content, temp);
    dup_line = my_strdup(line, 0);
    free_many(2, file_content, temp);
    return dup_line;
}

static char *get_user_id(char *pid)
{
    char *path = my_strconcat(PROC_PATH, pid);
    char *line = find_line_in_file(path);
    char *user_ID = NULL;
    int i = 0;
    int start;

    if (!line)
        return free_many(1, path);
    for (; line[i] && line[i] != '\t' && line[i] != ' '; i++);
    if (!line[i])
        return free_many(2, line, path);
    i++;
    start = i;
    while (line[i] && line[i] != '\t' && line[i] != ' ')
        i++;
    user_ID = my_strndup(&line[start], i - start);
    free_many(2, line, path);
    return user_ID;
}

static char *free_all(char **line_tab, char **tab_passwd, char *passwd)
{
    if (line_tab)
        free_array(line_tab);
    if (tab_passwd)
        free_array(tab_passwd);
    if (passwd)
        free(passwd);
    return NULL;
}

static char **seek_user(int i, char **tab_passwd, char *uid)
{
    char **line_tab;

    if (my_strstr(tab_passwd[i], uid)) {
        line_tab = my_str_to_word_array(tab_passwd[i], ":");
        if (!line_tab)
            return NULL;
        if (line_tab[2] && my_strcmp(line_tab[2], uid) == 0) {
            return line_tab;
        }
        free_array(line_tab);
    }
    return NULL;
}

static char *get_username_from_id(char *uid)
{
    char *passwd = openator("/etc/passwd");
    char **tab_passwd = passwd ? my_str_to_word_array(passwd, "\n") : NULL;
    char **line_tab = NULL;
    char *username = NULL;

    if (!tab_passwd) {
        if (passwd)
            free(passwd);
        return NULL;
    }
    for (int i = 0; tab_passwd[i]; i++) {
        line_tab = seek_user(i, tab_passwd, uid);
        if (line_tab)
            break;
    }
    if (!line_tab)
        return free_all(NULL, tab_passwd, passwd);
    username = my_strdup(line_tab[0], 0);
    free_all(line_tab, tab_passwd, passwd);
    return username;
}

int print_username(char **PIDs, int i)
{
    char *user_id;
    char *username;

    user_id = get_user_id(PIDs[i]);
    username = user_id ? get_username_from_id(user_id) : NULL;
    free(user_id);
    if (!username)
        return FAILURE;
    if (my_strlen(username) > 8) {
        username[7] = '+';
        username[8] = '\0';
    }
    printw("%s ", username);
    for (int j = my_strlen(username); j < 7; j++)
        printw(" ");
    free(username);
    return SUCCESS;
}
