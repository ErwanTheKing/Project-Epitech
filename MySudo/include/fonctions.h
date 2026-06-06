/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** The fonctions.h
*/
/**
 * @file fonctions.h
 * @brief The fonctions.h
 * @author Erwan Lo Presti
 */

#ifndef MY_SUDO_FONCTIONS_H
    #define MY_SUDO_FONCTIONS_H
int my_sudo(char **argv);
int verif_sudoers(char *user);
char *open_passwd(void);
int set_uid(char *user);
char **open_shadow(void);
int set_guid(char *user);
char *open_group(void);
#endif /* MY_SUDO_FONCTIONS_H */
