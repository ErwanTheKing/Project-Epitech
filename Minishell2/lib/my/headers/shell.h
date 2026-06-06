/*
** EPITECH PROJECT, 2026
** G-PSU-200-NCE-2-1-minishell1-4
** File description:
** The shell.h
*/
/**
 * @file shell.h
 * @brief The shell.h
 * @author Erwan Lo Presti
 */

#ifndef G_PSU_200_NCE_2_1_MINISHELL1_4_SHELL_H
    #define G_PSU_200_NCE_2_1_MINISHELL1_4_SHELL_H
typedef struct env_s {
    char *data;
    struct env_s *next;
} env_t;
typedef enum redirection_e {
    NONE,
    SIMPLE_RIGHT,
    DOUBLE_RIGHT,
    SIMPLE_LEFT,
    DOUBLE_LEFT
} redirection_t;
typedef struct pipe_data_s {
    int prev_read;
    int *fd;
    int i;
    int nb_cmds;
} pipe_data_t;
typedef struct shell_s {
    env_t *my_env;
    int return_va;
    char *host;
    char *user;
    char *last_path;
    char *home;
    char *old_path;
    redirection_t rd_l;
    redirection_t rd_r;
    char *file_l;
    char *file_r;
    int in_pipe;
} shell_t;
env_t *create_env(char **env);
int my_setenv(env_t **my_env, char *variable, char *value, shell_t *my_shell);
void free_env(env_t **my_env);
int my_unsetenv(env_t **my_env, char *variable);
void display_env(env_t *my_env);
shell_t *init(char **env);
void free_shell(shell_t *my_shell);
char *my_getenv(env_t *my_env, char *var);
char *read_getline(shell_t *my_shell);
int loop(shell_t *my_shell);
void display_prompt(shell_t *my_shell);
int exec_env(shell_t *my_shell, char *line);
char *verif_cmd(char *line, shell_t *my_shell);
char **array_env(env_t *my_env);
int exec_cmd(shell_t *my_shell, char *line);
int manage_cd(shell_t *my_shell, char *arg);
char *get_branch_git(void);
char *get_pwd(void);
int pony(shell_t *my_shell);
void verif_lines(char *lines, shell_t *my_shell);
int right_redirection(const char *file, redirection_t choose);
int choose_redirection(shell_t *my_shell, char **array);
char *clear_str(char *line);
int is_left_redirect(char *str);
int is_right_redirect(char *str);
int left_redirection(const char *file, redirection_t choose);
int func_pipe(char *lines, shell_t *my_shell, char **array);
int is_builtin(char *str);
int verif_builtin(char **array);
int handle_builtin(char **array, shell_t *my_shell);
int nbr_cmd(char *line);
#endif /* G_PSU_200_NCE_2_1_MINISHELL1_4_SHELL_H */
