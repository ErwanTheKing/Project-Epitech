/*
** EPITECH PROJECT, 2026
** nb
** File description:
** nb
*/

#include "../lib/Headers/factory.h"

static int is_comment_start(char c)
{
    return (c == COMMENT_CHAR || c == ';');
}

int skip_comment(char *buff)
{
    int i = 0;

    while (buff[i] != '\n' && buff[i] != '\0')
        i++;
    if (buff[i] == '\n')
        i++;
    return i;
}

int is_label_char(char c, char before)
{
    if (c != LABEL_CHAR)
        return FALSE;
    if (before == DIRECT_CHAR)
        return FALSE;
    for (int i = 0; LABEL_CHARS[i] != '\0'; i++) {
        if (LABEL_CHARS[i] == before) {
            return TRUE;
        }
    }
    return FALSE;
}

int get_pos(char c, char *buff)
{
    int len = my_strlen(buff);

    for (int i = 0; i < len; i++) {
        if (is_comment_start(buff[i]))
            i += skip_comment(&buff[i]);
        if (i < len && i > 0 && is_label_char(buff[i], buff[i - 1]) == TRUE)
            return i;
    }
    return len + 1;
}

int get_nb_label(char *buff)
{
    int nb = 0;
    int len = my_strlen(buff);

    for (int i = get_pos(LABEL_CHAR, buff) + 1; i < len; i++) {
        if (is_comment_start(buff[i]))
            i += skip_comment(&buff[i]);
        if (i < len && i > 0 && is_label_char(buff[i], buff[i - 1]) == TRUE)
            nb++;
    }
    return nb + 1;
}
