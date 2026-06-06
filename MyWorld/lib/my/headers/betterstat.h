/*
** EPITECH PROJECT, 2025
** bootstrap_my_ls
** File description:
** betterstat
*/

#ifndef BETTERSTAT_H
    #define BETTERSTAT_H
typedef struct  betterstat_s {
    char *name;
    int minor;
    int major;
    int inode;
    int hard_link;
    int size;
    int allocated_space;
    int UID;
    int GID;
    char type;
} betterstat_t;
#endif
