/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** my_sudo
*/

#include "../include/includes.h"

static int my_exec(char *arg0, char **arg1)
{
    int id = getuid();

    if (id != 0)
        write(1, "\n", 1);
    if (execvp(arg0, arg1) == -1) {
        write(2, "sudo: ", 6);
        write(2, arg0, my_strlen(arg0));
        write(2, ": command not found\n", 20);
        return ERROR;
    }
    return SUCCESS;
}

static char *usr(void)
{
    char *buffer = open_passwd();
    int id = getuid();
    char **array = my_str_to_word_array(buffer, "\n:");
    char *user;

    free(buffer);
    for (int i = 0; array[i] != NULL; i++) {
        if (my_getnbr(array[i]) == id) {
            user = my_strdup(array[i - 2]);
            free(array);
            return user;
        }
    }
    free(array);
    exit(84);
}

static void write_message(char *user)
{
    write(1, "[my_sudo] password for ", 23);
    write(1, user, my_strlen(user));
    write(1, ": ", 2);
}

static char *get_pass(void)
{
    struct termios old;
    struct termios new;
    size_t len = 0;
    ssize_t nread;
    char *line = NULL;

    tcgetattr(STDIN_FILENO, &old);
    new = old;
    new.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &new);
    nread = getline(&line, &len, stdin);
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    if (nread == -1)
        return NULL;
    line[nread - 1] = '\0';
    return line;
}

static char *verif_pass(char *user)
{
    char **array = open_shadow();
    char *pass = NULL;

    if (array == NULL) {
        write(2, "Impossible d'ouvrir le shadow\n", 30);
        return NULL;
    }
    for (int i = 0; array[i] != NULL; i++) {
        if (my_strcmp(array[i], user) == 0) {
            pass = my_strdup(array[i + 1]);
            free_array(array);
            return pass;
        }
    }
    return NULL;
}

static int check_password(char *pass, char *user)
{
    char *line = NULL;
    char *crypt_line = NULL;

    write_message(user);
    line = get_pass();
    crypt_line = crypt(line, pass);
    free(line);
    if (my_strcmp(crypt_line, pass) == 0) {
        free(pass);
        return SUCCESS;
    }
    return ERROR;
}

static int password_attempts(char *pass, char *user, int attempt)
{
    while (check_password(pass, user) != SUCCESS) {
        attempt -= 1;
        if (attempt == 0) {
            write(2, "my_sudo: 3 incorrect password attempts\n", 39);
            free(pass);
            return ERROR;
        }
        write(1, "Sorry, try again.\n", 19);
    }
    return SUCCESS;
}

static int basic_case(char *pass, char *user)
{
    int id = getuid();
    int attempt = 3;

    if (id == 0)
        return SUCCESS;
    if (pass == NULL) {
        return ERROR;
    }
    if (password_attempts(pass, user, attempt) == ERROR)
        return ERROR;
    if (verif_sudoers(user) == ERROR)
        return ERROR;
    return SUCCESS;
}

static int exec(char **argv)
{
    if (my_strcmp(argv[1], "-u") == 0 || my_strcmp(argv[1], "-g") == 0) {
        if (my_exec(argv[3], &argv[3]) == ERROR)
            return ERROR;
    } else {
        if (my_exec(argv[1], &argv[1]) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}

int my_sudo(char **argv)
{
    char *user = NULL;
    char *pass = NULL;
    int id = getuid();

    if (id != 0) {
        user = usr();
        pass = verif_pass(user);
    }
    if (basic_case(pass, user) == ERROR)
        return ERROR;
    if (my_strcmp(argv[1], "-u") == 0)
        if (set_uid(argv[2]) == ERROR)
            return ERROR;
    if (my_strcmp(argv[1], "-g") == 0)
        if (set_guid(argv[2]) == ERROR)
            return ERROR;
    if (exec(argv) == ERROR)
        return ERROR;
    return SUCCESS;
}
