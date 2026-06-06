/*
** EPITECH PROJECT, 2026
** secured
** File description:
** ht_delete
*/

#include <stdlib.h>
#include "../include/hashtable.h"

static void free_node(entry_t *node)
{
    if (node->key)
        free(node->key);
    if (node->value)
        free(node->value);
    free(node);
}

static void remove_node(hashtable_t *ht, int idx, entry_t *prev, entry_t *curr)
{
    if (prev)
        prev->next = curr->next;
    else
        ht->buckets[idx] = curr->next;
    free_node(curr);
}

static int get_hash_idx(hashtable_t *ht, char *key, int *h_val)
{
    int idx = 0;

    *h_val = ht->hash(key, ht->len);
    idx = *h_val % ht->len;
    if (idx < 0)
        idx += ht->len;
    return idx;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int h_val = 0;
    int idx = 0;
    entry_t *curr;
    entry_t *prev = NULL;

    if (!ht || !key || ht->len == 0)
        return 84;
    idx = get_hash_idx(ht, key, &h_val);
    curr = ht->buckets[idx];
    while (curr != NULL) {
        if (curr->hash == h_val && my_strcmp(curr->key, key) == 0) {
            remove_node(ht, idx, prev, curr);
            return 0;
        }
        prev = curr;
        curr = curr->next;
    }
    return 84;
}
