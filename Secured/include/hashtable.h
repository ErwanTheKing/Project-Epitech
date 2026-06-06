/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

typedef struct entry_s {
    int hash;
    char *value;
    char *key;
    struct entry_s *next;
} entry_t;

typedef struct hashtable_s {
    entry_t **buckets;
    int len;
    int (*hash)(char *, int);
} hashtable_t;

int hash(char *key, int len);

hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);


int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_nbr_to_str(int nb);
int my_strcmp(char *s1, char *s2);
int str_to_int(char *str);
char *dlong_to_str(long long nb);
char *my_strdup(char const *src);

#endif /* HASHTABLE_H */
