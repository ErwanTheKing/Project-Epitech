/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** linked_lists
*/

#ifndef LINKED_LISTS_H
    #define LINKED_LISTS_H
typedef struct node_s {
    void *data;
    struct node_s *next;
} node_t;
void attach_list_to_back(node_t **head, node_t *to_attach);
int search_in_list(const node_t *head, void *data,
    int (*cmp_func)(void *, void *));
void push_front(node_t **head, void *data);
void push_back(node_t **head, void *data);
void pop_front(node_t **head);
void pop_back(node_t **head);
void pop_at(node_t **head, int pos);
int list_len(node_t *head, int len);
void insert_node(node_t **head, void *data, int pos);
void *get_front(node_t *head);
void *get_back(node_t *head);
node_t *merge_sort_lists(node_t **head, int (*cmp_func)(void *, void *));
node_t *merge_sort_merge_list(node_t *left, node_t *right,
    int (*cmp_func)(void *, void *));
void *get_at(node_t *head, int pos);
void free_list(node_t **head);
node_t *init_list(void *data);
void invert_list(node_t **head);
node_t *get_to_middle(node_t *head);
#endif
