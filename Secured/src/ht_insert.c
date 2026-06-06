/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-CPE-110-NCE-1-1-secured-2
** File description:
** ht_insert
*/

#include "hashtable.h"
#include <stdlib.h>

static void free_new_node(entry_t *new_node)
{
    if (new_node->key)
        free(new_node->key);
    if (new_node->value)
        free(new_node->value);
    free(new_node);
}

static entry_t *create_node(int h_val, char *key, char *value)
{
    entry_t *new_val = malloc(sizeof(entry_t));

    if (!new_val)
        return NULL;
    new_val->hash = h_val;
    new_val->key = my_strdup(key);
    new_val->value = my_strdup(value);
    new_val->next = NULL;
    if (!new_val->key || !new_val->value) {
        free_new_node(new_val);
        return NULL;
    }
    return new_val;
}

static int handle_update(entry_t *curr, char *value)
{
    char *new_val = my_strdup(value);

    if (!new_val)
        return 84;
    free(curr->value);
    curr->value = new_val;
    return 0;
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

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int h_val = 0;
    int idx = 0;
    entry_t *curr = NULL;
    entry_t *new_node = NULL;

    if (!ht || !key || !value)
        return 84;
    idx = get_hash_idx(ht, key, &h_val);
    curr = ht->buckets[idx];
    while (curr != NULL) {
        if (curr->hash == h_val && my_strcmp(curr->key, key) == 0)
            return handle_update(curr, value);
        curr = curr->next;
    }
    new_node = create_node(h_val, key, value);
    if (!new_node)
        return 84;
    new_node->next = ht->buckets[idx];
    ht->buckets[idx] = new_node;
    return 0;
}
