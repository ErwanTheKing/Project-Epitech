/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** unit tests for src/
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../lib/my/headers/defines.h"
#include "../lib/my/headers/my.h"
#include "../lib/my/headers/shell.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static shell_t init_shell(env_t *env)
{
    shell_t sh = {0};

    sh.my_env = env;
    sh.rd_l = NONE;
    sh.rd_r = NONE;
    return sh;
}

static env_t *make_basic_env(void)
{
    char *envp[] = {
        "USER=tester",
        "PATH=/bin:/usr/bin",
        "HOME=/tmp",
        NULL
    };

    return create_env(envp);
}

// Mocks used by verif_builtin/verif_lines.
static int g_exec_cmd_calls = 0;
static char *g_last_exec_arg = NULL;
static int g_pipe_calls = 0;

int exec_cmd(shell_t *my_shell, char *line)
{
    (void)my_shell;
    g_exec_cmd_calls++;
    free(g_last_exec_arg);
    g_last_exec_arg = my_strdup(line, 0);
    return SUCCESS;
}

int func_pipe(char *lines, shell_t *my_shell, char **array)
{
    (void)lines;
    (void)my_shell;
    (void)array;
    g_pipe_calls++;
    return SUCCESS;
}

Test(is_rd, left_detects_output_symbol)
{
    cr_assert_eq(is_left_redirect("echo hi > out"), 0);
    cr_assert_eq(is_left_redirect("cat < in"), -1);
}

Test(is_rd, right_detects_input_symbol)
{
    cr_assert_eq(is_right_redirect("cat < in"), 0);
    cr_assert_eq(is_right_redirect("echo hi > out"), -1);
}

Test(clear_str, removes_redirection_tokens)
{
    char *res = clear_str("echo hello > out.txt");

    cr_assert_not_null(res);
    cr_assert_str_eq(res, "echo hello ");
    free(res);
}

Test(clear_str, only_redirection_returns_null)
{
    char *res = clear_str("> out.txt");

    cr_assert_null(res);
}

Test(verif_builtin, detects_builtin_on_last_command)
{
    char *array[] = {"echo test", "cd /tmp", NULL};

    cr_assert_eq(verif_builtin(array), SUCCESS);
}

Test(verif_builtin, non_builtin_last_command)
{
    char *array[] = {"env", "ls -la", NULL};

    cr_assert_eq(verif_builtin(array), FAILURE);
}

Test(is_builtin, known_and_unknown_commands)
{
    cr_assert_eq(is_builtin("setenv KEY value"), SUCCESS);
    cr_assert_eq(is_builtin("unsetenv KEY"), SUCCESS);
    cr_assert_eq(is_builtin("env"), SUCCESS);
    cr_assert_eq(is_builtin("pwd"), FAILURE);
}

Test(handle_builtin, calls_exec_cmd_with_clean_command)
{
    shell_t sh = {0};
    char **array = malloc(sizeof(char *) * 2);

    cr_assert_not_null(array);
    array[0] = my_strdup("echo x > out", 0);
    array[1] = NULL;
    g_exec_cmd_calls = 0;
    free(g_last_exec_arg);
    g_last_exec_arg = NULL;

    cr_assert_eq(handle_builtin(array, &sh), SUCCESS);
    cr_assert_eq(g_exec_cmd_calls, 1);
    cr_assert_not_null(g_last_exec_arg);
    cr_assert_str_eq(g_last_exec_arg, "echo x ");
}

Test(create_env, null_input_returns_null)
{
    cr_assert_null(create_env(NULL));
}

Test(create_env, duplicates_env_strings)
{
    char *envp[] = {"FOO=BAR", "HELLO=WORLD", NULL};
    env_t *env = create_env(envp);

    cr_assert_not_null(env);
    cr_assert_str_eq(env->data, "FOO=BAR");
    cr_assert_neq(env->data, envp[0]);
    cr_assert_str_eq(env->next->data, "HELLO=WORLD");
    free_env(&env);
}

Test(my_getenv, finds_existing_variable)
{
    env_t *env = make_basic_env();
    char *value = my_getenv(env, "PATH");

    cr_assert_not_null(value);
    cr_assert_str_eq(value, "/bin:/usr/bin");
    free(value);
    free_env(&env);
}

Test(my_getenv, missing_or_invalid_input)
{
    env_t *env = make_basic_env();

    cr_assert_null(my_getenv(env, "DOES_NOT_EXIST"));
    cr_assert_null(my_getenv(NULL, "PATH"));
    free_env(&env);
}

Test(array_env, returns_pointer_array)
{
    env_t *env = make_basic_env();
    char **arr = array_env(env);

    cr_assert_not_null(arr);
    cr_assert_str_eq(arr[0], "USER=tester");
    cr_assert_eq(arr[0], env->data);
    cr_assert_null(arr[3]);
    free(arr);
    free_env(&env);
}

Test(my_setenv, rejects_invalid_variable_name, .init = redirect_all_std)
{
    env_t *env = make_basic_env();
    shell_t sh = init_shell(env);

    cr_assert_eq(my_setenv(&env, "1BAD", "value", &sh), FAILURE);
    cr_assert_eq(sh.return_va, 1);
    cr_assert_stdout_eq_str("setenv: Variable name must begin with a letter.\n");
    free_env(&env);
}

Test(my_setenv, creates_then_updates_variable)
{
    env_t *env = make_basic_env();
    shell_t sh = init_shell(env);
    char *value = NULL;

    cr_assert_eq(my_setenv(&env, "TEST_KEY", "abc", &sh), SUCCESS);
    value = my_getenv(env, "TEST_KEY");
    cr_assert_not_null(value);
    cr_assert_str_eq(value, "abc");
    free(value);

    cr_assert_eq(my_setenv(&env, "TEST_KEY", "xyz", &sh), SUCCESS);
    value = my_getenv(env, "TEST_KEY");
    cr_assert_not_null(value);
    cr_assert_str_eq(value, "xyz");

    free(value);
    free_env(&env);
}

Test(my_setenv, rejects_non_alnum_variable_name, .init = redirect_all_std)
{
    env_t *env = make_basic_env();
    shell_t sh = init_shell(env);

    cr_assert_eq(my_setenv(&env, "BAD-KEY", "value", &sh), FAILURE);
    cr_assert_eq(sh.return_va, 1);
    cr_assert_stdout_eq_str(
        "setenv: Variable name must contain alphanumeric characters.\n");
    free_env(&env);
}

Test(my_setenv, null_env_pointer_returns_failure)
{
    shell_t sh = {0};

    cr_assert_eq(my_setenv(NULL, "KEY", "value", &sh), FAILURE);
}

Test(my_setenv, creates_variable_in_empty_env)
{
    env_t *env = NULL;
    shell_t sh = init_shell(env);
    char *value = NULL;

    cr_assert_eq(my_setenv(&env, "FIRST_KEY", "v", &sh), SUCCESS);
    value = my_getenv(env, "FIRST_KEY");
    cr_assert_not_null(value);
    cr_assert_str_eq(value, "v");
    free(value);
    free_env(&env);
}

Test(my_setenv, supports_null_value)
{
    env_t *env = make_basic_env();
    shell_t sh = init_shell(env);
    char *value = NULL;

    cr_assert_eq(my_setenv(&env, "EMPTY_VALUE", NULL, &sh), SUCCESS);
    value = my_getenv(env, "EMPTY_VALUE");
    cr_assert_null(value);
    free_env(&env);
}

Test(my_unsetenv, removes_variable)
{
    env_t *env = make_basic_env();

    cr_assert_eq(my_unsetenv(&env, "HOME"), SUCCESS);
    cr_assert_null(my_getenv(env, "HOME"));
    free_env(&env);
}

Test(my_unsetenv, removes_head_variable)
{
    env_t *env = make_basic_env();

    cr_assert_eq(my_unsetenv(&env, "USER"), SUCCESS);
    cr_assert_null(my_getenv(env, "USER"));
    free_env(&env);
}

Test(my_unsetenv, invalid_params)
{
    env_t *env = make_basic_env();

    cr_assert_eq(my_unsetenv(NULL, "HOME"), FAILURE);
    cr_assert_eq(my_unsetenv(&env, NULL), FAILURE);
    free_env(&env);
}

Test(display_env, prints_all_lines, .init = redirect_all_std)
{
    env_t *env = make_basic_env();

    display_env(env);
    cr_assert_stdout_eq_str("USER=tester\nPATH=/bin:/usr/bin\nHOME=/tmp\n");
    free_env(&env);
}

Test(free_env, nullifies_head)
{
    env_t *env = make_basic_env();

    free_env(&env);
    cr_assert_null(env);
}

Test(choose_redirection, reads_left_and_right_files)
{
    shell_t sh = {0};
    char *array[] = {"cat < input.txt > output.txt", NULL};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    cr_assert_eq(choose_redirection(&sh, array), SUCCESS);
    cr_assert_eq(sh.rd_l, SIMPLE_LEFT);
    cr_assert_eq(sh.rd_r, SIMPLE_RIGHT);
    cr_assert_str_eq(sh.file_l, "input.txt");
    cr_assert_str_eq(sh.file_r, "output.txt");
    free(sh.file_l);
    free(sh.file_r);
}

Test(choose_redirection, skips_pipe_arrays)
{
    shell_t sh = {0};
    char *array[] = {"cat < in", "wc", NULL};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    cr_assert_eq(choose_redirection(&sh, array), SUCCESS);
    cr_assert_eq(sh.rd_l, NONE);
    cr_assert_eq(sh.rd_r, NONE);
}

Test(choose_redirection, reads_double_redirections)
{
    shell_t sh = {0};
    char *array[] = {"cat << eof >> out.log", NULL};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    cr_assert_eq(choose_redirection(&sh, array), SUCCESS);
    cr_assert_eq(sh.rd_l, DOUBLE_LEFT);
    cr_assert_eq(sh.rd_r, DOUBLE_RIGHT);
    cr_assert_str_eq(sh.file_l, "eof");
    cr_assert_str_eq(sh.file_r, "out.log");
    free(sh.file_l);
    free(sh.file_r);
}

Test(get_pwd, returns_current_folder_name)
{
    char cwd[PATH_MAX] = {0};
    char *pwd = NULL;
    char *last = NULL;

    cr_assert_not_null(getcwd(cwd, sizeof(cwd)));
    last = strrchr(cwd, '/');
    pwd = get_pwd();

    cr_assert_not_null(pwd);
    cr_assert_not_null(last);
    cr_assert_str_eq(pwd, last + 1);
    free(pwd);
}

Test(get_pwd, root_directory_returns_null)
{
    char old_pwd[PATH_MAX] = {0};

    cr_assert_not_null(getcwd(old_pwd, sizeof(old_pwd)));
    cr_assert_eq(chdir("/"), 0);
    cr_assert_null(get_pwd());
    cr_assert_eq(chdir(old_pwd), 0);
}

Test(get_branch_git, reads_branch_from_git_head)
{
    char old_pwd[PATH_MAX] = {0};
    char tmp_dir[] = "/tmp/mysh_branch_test_XXXXXX";
    char git_dir[PATH_MAX] = {0};
    char head_path[PATH_MAX] = {0};
    int fd = -1;
    char *branch = NULL;

    cr_assert_not_null(getcwd(old_pwd, sizeof(old_pwd)));
    cr_assert_not_null(mkdtemp(tmp_dir));
    snprintf(git_dir, sizeof(git_dir), "%s/.git", tmp_dir);
    cr_assert_eq(mkdir(git_dir, 0700), 0);
    {
        size_t git_len = strlen(git_dir);

        cr_assert_lt(git_len + sizeof("/HEAD"), sizeof(head_path));
        memcpy(head_path, git_dir, git_len);
        memcpy(head_path + git_len, "/HEAD", sizeof("/HEAD"));
    }
    fd = open(head_path, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    cr_assert_neq(fd, -1);
    cr_assert_eq(write(fd, "ref: refs/heads/unit_branch\n", 28), 28);
    close(fd);

    cr_assert_eq(chdir(tmp_dir), 0);
    branch = get_branch_git();

    cr_assert_not_null(branch);
    cr_assert_str_eq(branch, "unit_branch");

    free(branch);
    cr_assert_eq(chdir(old_pwd), 0);
    unlink(head_path);
    rmdir(git_dir);
    rmdir(tmp_dir);
}

Test(get_branch_git, detached_head_returns_null)
{
    char old_pwd[PATH_MAX] = {0};
    char tmp_dir[] = "/tmp/mysh_detached_test_XXXXXX";
    char git_dir[PATH_MAX] = {0};
    char head_path[PATH_MAX] = {0};
    int fd = -1;
    char *branch = NULL;

    cr_assert_not_null(getcwd(old_pwd, sizeof(old_pwd)));
    cr_assert_not_null(mkdtemp(tmp_dir));
    snprintf(git_dir, sizeof(git_dir), "%s/.git", tmp_dir);
    cr_assert_eq(mkdir(git_dir, 0700), 0);
    {
        size_t git_len = strlen(git_dir);

        cr_assert_lt(git_len + sizeof("/HEAD"), sizeof(head_path));
        memcpy(head_path, git_dir, git_len);
        memcpy(head_path + git_len, "/HEAD", sizeof("/HEAD"));
    }
    fd = open(head_path, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    cr_assert_neq(fd, -1);
    cr_assert_eq(write(fd, "0123456789abcdef\n", 17), 17);
    close(fd);

    cr_assert_eq(chdir(tmp_dir), 0);
    branch = get_branch_git();

    cr_assert_null(branch);
    cr_assert_eq(chdir(old_pwd), 0);
    unlink(head_path);
    rmdir(git_dir);
    rmdir(tmp_dir);
}

Test(exec_env, handles_env_setenv_unsetenv)
{
    env_t *env = make_basic_env();
    shell_t sh = init_shell(env);
    char *value = NULL;

    cr_assert_eq(exec_env(&sh, "setenv NEW_VAR value"), SUCCESS);
    value = my_getenv(sh.my_env, "NEW_VAR");
    cr_assert_not_null(value);
    free(value);
    cr_assert_eq(exec_env(&sh, "unsetenv NEW_VAR"), SUCCESS);
    cr_assert_null(my_getenv(sh.my_env, "NEW_VAR"));
    cr_assert_eq(exec_env(&sh, "something_else"), FAILURE);

    free_env(&sh.my_env);
}

Test(exec_env, env_builtin_prints, .init = redirect_all_std)
{
    env_t *env = make_basic_env();
    shell_t sh = init_shell(env);

    cr_assert_eq(exec_env(&sh, "env"), SUCCESS);
    cr_assert_eq(sh.return_va, 0);
    cr_assert_stdout_eq_str("USER=tester\nPATH=/bin:/usr/bin\nHOME=/tmp\n");
    free_env(&sh.my_env);
}

Test(exec_env, setenv_too_many_arguments, .init = redirect_all_std)
{
    env_t *env = make_basic_env();
    shell_t sh = init_shell(env);

    cr_assert_eq(exec_env(&sh, "setenv A B C"), SUCCESS);
    cr_assert_eq(sh.return_va, 1);
    cr_assert_stdout_eq_str("setenv: Too many arguments.\n");
    free_env(&sh.my_env);
}

Test(exec_env, setenv_without_arguments_displays_env, .init = redirect_all_std)
{
    env_t *env = make_basic_env();
    shell_t sh = init_shell(env);

    cr_assert_eq(exec_env(&sh, "setenv"), SUCCESS);
    cr_assert_eq(sh.return_va, 0);
    cr_assert_stdout_eq_str("USER=tester\nPATH=/bin:/usr/bin\nHOME=/tmp\n");
    free_env(&sh.my_env);
}

Test(verif_lines, ambiguous_output_sets_error_code, .init = redirect_all_std)
{
    shell_t sh = {0};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    verif_lines("echo hi > a > b", &sh);

    cr_assert_eq(sh.return_va, 1);
    cr_assert_stdout_eq_str("Ambiguous output redirect.\n");
}

Test(verif_lines, ambiguous_input_sets_error_code, .init = redirect_all_std)
{
    shell_t sh = {0};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    verif_lines("cat < a < b", &sh);

    cr_assert_eq(sh.return_va, 1);
    cr_assert_stdout_eq_str("Ambiguous input redirect.\n");
}

Test(verif_lines, missing_redirect_name_is_reported, .init = redirect_all_std)
{
    shell_t sh = {0};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    verif_lines("echo hello >", &sh);
    cr_assert_stdout_eq_str("Missing name for redirect.\n");
}

Test(verif_lines, single_commands_call_exec_cmd)
{
    shell_t sh = {0};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    g_exec_cmd_calls = 0;
    free(g_last_exec_arg);
    g_last_exec_arg = NULL;

    verif_lines("echo one;echo two", &sh);

    cr_assert_eq(g_exec_cmd_calls, 2);
    cr_assert_not_null(g_last_exec_arg);
    cr_assert_str_eq(g_last_exec_arg, "echo two ");
}

Test(verif_lines, pipeline_path_calls_func_pipe)
{
    shell_t sh = {0};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    g_pipe_calls = 0;

    verif_lines("echo hi | wc", &sh);

    cr_assert_eq(g_pipe_calls, 1);
}

Test(verif_lines, pipeline_builtin_uses_handle_builtin)
{
    shell_t sh = {0};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    g_pipe_calls = 0;
    g_exec_cmd_calls = 0;
    free(g_last_exec_arg);
    g_last_exec_arg = NULL;

    verif_lines("echo a | cd /tmp", &sh);

    cr_assert_eq(g_pipe_calls, 0);
    cr_assert_eq(g_exec_cmd_calls, 1);
    cr_assert_not_null(g_last_exec_arg);
    cr_assert_str_eq(g_last_exec_arg, "cd /tmp ");
}

Test(verif_lines, pipe_with_input_redirect_reports_ambiguity,
    .init = redirect_all_std)
{
    shell_t sh = {0};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    verif_lines("echo hi | wc < in", &sh);
    cr_assert_stdout_eq_str("Ambiguous input redirect.\n");
}

Test(verif_lines, pipe_with_output_redirect_reports_ambiguity,
    .init = redirect_all_std)
{
    shell_t sh = {0};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    verif_lines("echo hi > out | wc", &sh);
    cr_assert_stdout_eq_str("Ambiguous output redirect.\n");
}

Test(verif_lines, resets_right_redirection_after_command)
{
    shell_t sh = {0};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    verif_lines("echo hi > out.txt", &sh);
    cr_assert_eq(sh.rd_r, NONE);
}

Test(verif_lines, resets_left_redirection_after_command)
{
    shell_t sh = {0};

    sh.rd_l = NONE;
    sh.rd_r = NONE;
    verif_lines("cat < in.txt", &sh);
    cr_assert_eq(sh.rd_l, NONE);
}



