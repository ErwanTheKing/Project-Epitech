/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Utility function prototypes for string, math, memory and I/O operations
*/
/**
 * @file my.h
 * @brief Function prototypes for string, math, memory and I/O utilities
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#ifndef LIB_H
    #define LIB_H

    #include "defines.h"
    #include "linked_lists.h"
    #include <stdlib.h>
void my_putchar(char c);
void my_putfloat(float nb);
int my_putstr(char const *str);
long long int my_put_nbr(long long int nb);
int my_show_word_array(char *const *tab);
int my_putnbr_base(int nbr, char const *base);
char *my_revstr(char *str);
int my_strlen(char const *str);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char const *src, int add);
char *my_strndup(char const *src, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strconcat(char *dest, char *src);
char *my_strstr(char *str, char const *to_find);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
int my_str_isnum(char const *str);
int my_str_isfloat(char const *str);
int my_str_isnegnum(char const *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_getnbr(char const *str);
char *my_nbr_to_str(double nb, int precision);
char **my_str_to_word_array(char const *str, char const *separator);
int my_isneg(int nb);
void my_swap(int *a, int *b);
long long len_nb(long long nb);
int my_is_prime(int nb);
int my_char_isnum(char c);
int my_find_prime_sup(int nb);
int my_compute_square_root(int nb);
void my_sort_int_array(int *tab, int size);
int minimum_int_from_list(int count, ...);
long long int my_compute_power_rec(long long int nb, long long int power);
void free_array(char **array);
int my_array_len(char **array);
char **sort_word_array(char **array);
int get_file_size_no_stat(char const *filepath);
int get_file_size_stat(char *filepath);
char **my_char_array_dup(char **array);
char **cmp_alpha(char **array, int to_cmp, int len);
char *openator(char const *filepath);
int free_many_arrays(int count, ...);
int free_many(int count, ...);

#endif /* LIB_H */
