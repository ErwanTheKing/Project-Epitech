/*
** EPITECH PROJECT, 2026
** factory
** File description:
** factory
*/

#ifndef FACTORY_H
    #define FACTORY_H
    /*basic include*/
    #include "../lib/Headers/defines.h"
    #include "../lib/Headers/my.h"
    #include "struct.h"
    /*handle file include*/
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    /*getline include*/
    #include <stdio.h>
    /*write include*/
    #include <unistd.h>
//Functions
void clear_comment(char *buff);
int clear_labels(char *buff, char **labels);
int help(void);
int skip_header(char *buff);
int get_labels(char *buff, int nb, prog_t *prog);
int is_label_char(char c, char before);
int robot_factory(int ac, char *filename);
char *fill_buffer(int dest, char *filename);
int write_instruction(char *buf, int fd, prog_t *prog, int *prog_s);
int write_in(char *buff, char *filename);
int put_err(const char *text);
int is_valid_filename(char *filename);
char *cor_formating(char *filename);
char *my_strcat(char *dest, char const *src);
robot_t create_robot(char *buff);
char *get_name(char *buff);
char *get_comment(char *buff);
int occurrencies(char *buff, char c);
int get_name_len(char *buff);
int get_comment_len(char *buff);
void big_andian(int value, unsigned char *stock);
int get_nb_label(char *buff);
int get_pos(char c, char *buff);
int skip_comment(char *buff);
int get_op_index(char *op);
int is_index(int code);
unsigned char coding_byte(char **instruction, int code);
unsigned char prog_size(char **instruction, int start);
int there_is_coding_byte(int code);
void big_endian_2(int value, unsigned char *stock);

#endif /* !FACTORY_H */
