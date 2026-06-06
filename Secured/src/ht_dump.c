/*
** EPITECH PROJECT, 2026
** secured
** File description:
** ht_dump
*/

#include "../include/hashtable.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void write_index(char *buf)
{
    write(1, "[", 1);
    write(1, buf, my_strlen(buf));
    write(1, "]:\n", 3);
}

void write_message(char *buf, entry_t *tmp)
{
    write(1, "> ", 2);
    write(1, buf, my_strlen(buf));
    write(1, " - ", 3);
    write(1, tmp->value, my_strlen(tmp->value));
    write(1, "\n", 1);
}

void ht_dump(hashtable_t *ht)
{
    char *buf = NULL;

    if (!ht)
        return;
    for (int i = 0; i < ht->len; i++) {
        buf = my_nbr_to_str(i);
        write_index(buf);
        free(buf);
        buf = NULL;
        for (entry_t *tmp = ht->buckets[i]; tmp != NULL; tmp = tmp->next) {
            buf = my_nbr_to_str(tmp->hash);
            write_message(buf, tmp);
            free(buf);
        }
    }
}
