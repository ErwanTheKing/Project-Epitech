/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** The functions.h
*/

#ifndef MY_LS_FUNCTIONS_H
    #define MY_LS_FUNCTIONS_H
    #include "includes.h"
int my_ls(int argc, char **argv);
options_t *pre_fill_struct(void);
int fill_struct(options_t *options, int argc, char **argv, int many_options);
char **file_path_array(int argc, char **argv);
void verif(DIR *dir, struct dirent *struct_dir);
int len_array(int argc, char **argv);
int sort_path_case(struct dirent *struct_dir, char **array);
void show_word_array(char **array);
void show_word_array_multi(char **tab, int a, char **array);
int len_word_dir(char **array, struct dirent *struct_dir, int a);
char **sort(char **tab);
int sort_path_case_multi(struct dirent *struct_dir, char **array, int a);
void free_array(char **array);
char **path_case(struct dirent *struct_dir, char **array);
char **path_case_multi(struct dirent *struct_dir, char **array, int a);
int sort_path_case_a(struct dirent *struct_dir, char **array);
int sort_path_case_multi_a(struct dirent *struct_dir, char **array, int a);
char **sort_array(char **array);
int option_a(char **array, int a, int argc,
    char **argv);
int option_d(char **array);
int without_option(char **array, int a, int argc,
    char **argv);
char get_type(struct stat *stats);
int sort_path_case_l(struct dirent *struct_dir, char **array);
int option_l(char **array, int argc,
    char **argv);
#endif /* MY_LS_FUNCTIONS_H */
