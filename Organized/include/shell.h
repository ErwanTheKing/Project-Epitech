/*
** EPITECH PROJECT, 2025
** G-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data);
int workshop_shell(void *data);
typedef struct hardware_s {
    char *type;
    char *name;
    int id;
} hardware_t;
typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;

typedef struct infos_s {
    linked_list_t *hardware;
    int id;
} infos_t;
#endif /* SHELL_H */
