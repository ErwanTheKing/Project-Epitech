/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-CPE-110-NCE-1-1-secured-2
** File description:
** hashtable
*/

#include "hashtable.h"
#include <stdlib.h>

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (!ht || len <= 0)
        return NULL;
    ht->len = len;
    ht->hash = hash;
    ht->buckets = malloc(sizeof(entry_t *) * len);
    if (!ht->buckets) {
        free(ht);
        return NULL;
    }
    for (int i = 0; i < len; i++)
        ht->buckets[i] = NULL;
    return ht;
}

void delete_hashtable(hashtable_t *ht)
{
    entry_t *current;
    entry_t *next;

    if (!ht)
        return;
    for (int i = 0; i < ht->len; i++) {
        current = ht->buckets[i];
        while (current) {
            next = current->next;
            free(current->key);
            free(current->value);
            free(current);
            current = next;
        }
    }
    free(ht->buckets);
    free(ht);
}
