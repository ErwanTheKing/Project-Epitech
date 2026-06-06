/*
** EPITECH PROJECT, 2025
** include all function
** File description:
** oui
*/

#ifndef MY_LIB
    #define MY_LIB
    #include <limits.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <ctype.h>
    #include <string.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include <stdarg.h>
    #include <dirent.h>
    #include <linux/limits.h>
    #include <sys/types.h>
    #include <ctype.h>
    #include <utmp.h>
    #include <stdbool.h>

typedef struct nodes {
    void *data;
    struct nodes *next;
} nodes_t;

void my_putchar(char c);

int my_isneg(int nb);

int my_put_nbr(int nb);

void my_swap(int *a, int *b);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_getnbr(char const *str);

void my_sort_int_array(int *tab, int size);

int my_compute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

char *my_strstr(char *str, char const *to_find);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_str_isalpha(char const *str);

int my_str_isnum(char *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

char *my_strn(char *str, char flag);

char *my_strdup(char const *src);

char **my_strtwa(char const *str, char *sp);

int my_show_word_array(char *const *tab);

int len(char **array);

void free_array_void(void *data);

void push_front(nodes_t **head, nodes_t *new);

nodes_t *new_node(void *data);

int my_free(void **pointer, int max, int exit);

void *my_free_void(void **pointer, int max, void *exit);

void free_array(char **array);

int len_array(char **array);

void push_back(nodes_t **old, nodes_t *new);

#endif
