/*
** EPITECH PROJECT, 2026
** secured
** File description:
** ht_search
*/

#include "hashtable.h"
#include <stddef.h>

char *ht_search(hashtable_t *ht, char *key)
{
    int h_val = 0;
    int idx = 0;
    entry_t *curr = NULL;

    if (!ht || !key || ht->len == 0)
        return NULL;
    h_val = ht->hash(key, ht->len);
    idx = h_val % ht->len;
    if (idx < 0)
        idx += ht->len;
    curr = ht->buckets[idx];
    while (curr != NULL) {
        if (curr->hash == h_val && my_strcmp(curr->key, key) == 0)
            return curr->value;
        curr = curr->next;
    }
    return NULL;
}
