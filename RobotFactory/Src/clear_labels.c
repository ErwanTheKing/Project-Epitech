/*
** EPITECH PROJECT, 2026
** clear
** File description:
** clear
*/

#include "../lib/Headers/factory.h"

static int is_label(char c)
{
    for (int i = 0; LABEL_CHARS[i] != '\0'; i++) {
        if (c == LABEL_CHARS[i])
            return TRUE;
    }
    return FALSE;
}

static void remove_label(char *buff, int i)
{
    int pos = i - 1;

    buff[i] = ' ';
    while (is_label(buff[pos]) == TRUE) {
        buff[pos] = ' ';
        pos--;
    }
}

int occ_in_labels(char *label, char **labels)
{
    int occ = 0;

    for (int i = 0; labels[i] != NULL; i++) {
        if (my_strcmp(labels[i], label) == 0)
            occ++;
    }
    return occ;
}

static int is_label_call(char *buff, int i, char **labels)
{
    int len = 0;
    char *label = NULL;
    int res = SUCCESS;

    if (buff[i - 1] != DIRECT_CHAR)
        return FALSE;
    if (buff[i] != LABEL_CHAR)
        return FALSE;
    while (is_label(buff[i + len + 1]) == TRUE) {
        len++;
    }
    label = my_strndup(&buff[i + 1], len + 1);
    label[len] = ':';
    if (occ_in_labels(label, labels) != 1)
        res = FAILURE;
    free(label);
    return res;
}

int clear_labels(char *buff, char **labels)
{
    for (int i = skip_header(buff); buff[i] != '\0'; i++) {
        if (is_label_call(buff, i, labels) == FAILURE)
            return FAILURE;
        if (buff[i] != '\0' && i > 0
            && is_label_char(buff[i], buff[i - 1]) == TRUE) {
            remove_label(buff, i);
        }
    }
    return SUCCESS;
}
