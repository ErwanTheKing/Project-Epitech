/*
** EPITECH PROJECT, 2026
** label
** File description:
** label
*/

#include <string.h>

#include "../lib/Headers/factory.h"
#include "../lib/Headers/my.h"

static int has_label(char **array_rows)
{
    int len = 0;

    if (!array_rows || !array_rows[0])
        return 0;
    len = my_strlen(array_rows[0]);
    return (len > 0 && array_rows[0][len - 1] == ':');
}

static int get_opcode_from_rows(char **array_rows)
{
    if (has_label(array_rows))
        return get_op_index(array_rows[1]);
    return get_op_index(array_rows[0]);
}

static int save_label(char **tab, int *pos, prog_t *prog, char **array_rows)
{
    int i = my_array_len(tab);

    tab[i] = my_strdup(array_rows[0], 0);
    if (!tab[i])
        return FAILURE;
    pos[i] = prog->prog_size;
    return SUCCESS;
}

static int update_prog_size(prog_t *prog, char **array_rows, int start)
{
    if (!array_rows[start])
        return SUCCESS;
    prog->prog_size += prog_size(array_rows, start);
    return SUCCESS;
}

static int is_valid_op(char **array_rows, int op_code, int array_skip)
{
    if (op_code == -1 || op_code == 0 || op_code == 17)
        return 0;
    if (my_array_len(array_rows + array_skip) != op_tab[op_code].nbr_args)
        return 0;
    return 1;
}

static void strip_comment_tokens(char **array_rows)
{
    for (int i = 0; array_rows[i]; i++) {
        if (array_rows[i][0] != COMMENT_CHAR && array_rows[i][0] != ';')
            continue;
        for (int j = i; array_rows[j]; j++) {
            free(array_rows[j]);
            array_rows[j] = NULL;
        }
        return;
    }
}

static int handle_instruction(
    char **array_rows,
    char **tab,
    int *pos,
    prog_t *prog)
{
    int array_skip = has_label(array_rows) ? 2 : 1;
    int start = has_label(array_rows) ? 1 : 0;
    int op_code = get_opcode_from_rows(array_rows);

    if (!is_valid_op(array_rows, op_code, array_skip))
        return FAILURE;
    if (has_label(array_rows)
        && save_label(tab, pos, prog, array_rows) == FAILURE)
        return FAILURE;
    update_prog_size(prog, array_rows, start);
    return SUCCESS;
}

static int get_label(char *buff, char **tab, int *pos, prog_t *prog)
{
    char **array_rows = my_str_to_word_array(buff, SEPARATOR_ROWS);
    int status = SUCCESS;

    if (!array_rows)
        return SUCCESS;
    strip_comment_tokens(array_rows);
    if (!array_rows[0]) {
        free_array(array_rows);
        return SUCCESS;
    }
    if (has_label(array_rows) && !array_rows[1])
        status = save_label(tab, pos, prog, array_rows);
    else
        status = handle_instruction(array_rows, tab, pos, prog);
    free_array(array_rows);
    return status;
}

static int free_get_labels(char **tab, int *pos, char **array_line)
{
    free_array(tab);
    free(pos);
    free_array(array_line);
    return FAILURE;
}

int get_labels(char *buff, int nb, prog_t *prog)
{
    char **tab = malloc(sizeof(char *) * (nb + 1));
    int *pos = malloc(sizeof(int) * nb);
    char **array_line = my_str_to_word_array(buff, SEPARATOR_LINE);

    if (!tab || !pos || !array_line) {
        free(tab);
        free(pos);
        if (array_line)
            free_array(array_line);
        return -1;
    }
    for (int i = 0; i <= nb; i++)
        tab[i] = NULL;
    for (int i = 0; array_line[i]; i++)
        if (get_label(array_line[i], tab, pos, prog) == FAILURE)
            return free_get_labels(tab, pos, array_line);
    free_array(array_line);
    prog->labels = tab;
    prog->pos = pos;
    return SUCCESS;
}
