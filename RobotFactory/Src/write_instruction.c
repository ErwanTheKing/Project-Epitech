/*
** EPITECH PROJECT, 2026
** write_instruction
** File description:
** instruction encoding helpers
*/

#include <stdlib.h>
#include <unistd.h>
#include "../lib/Headers/factory.h"

static int is_comment_token(char *token)
{
    if (!token || token[0] == '\0')
        return FALSE;
    return (token[0] == COMMENT_CHAR || token[0] == ';');
}

static int is_blank_line(char *buf)
{
    if (!buf)
        return TRUE;
    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\r')
            return FALSE;
    }
    return TRUE;
}

static void trim_inline_comment(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++) {
        if (!is_comment_token(array[i]))
            continue;
        for (int j = i; array[j]; j++) {
            free(array[j]);
            array[j] = NULL;
        }
        return;
    }
}

static int get_pos_label(char *label, prog_t *prog)
{
    for (int i = 0; prog->labels[i]; i++) {
        if (prog->labels[i][my_strlen(prog->labels[i]) - 1] == ':')
            prog->labels[i][my_strlen(prog->labels[i]) - 1] = '\0';
        if (my_strcmp(prog->labels[i], label) == 0)
            return prog->pos[i];
    }
    return -1;
}

static int direct_value(char *arg, write_context_t *ctx)
{
    int nbr = 0;

    if (arg[1] == ':') {
        nbr = get_pos_label(arg + 2, ctx->prog);
        nbr -= *ctx->prog_s;
        return nbr;
    }
    return my_getnbr(arg);
}

static void write_direct_value(int fd, int code, int nbr)
{
    unsigned char byte[2] = {0};
    unsigned char byte2[4] = {0};

    if (is_index(code) == IND_SIZE) {
        big_endian_2(nbr, byte);
        write(fd, byte, IND_SIZE);
        return;
    }
    big_andian(nbr, byte2);
    write(fd, byte2, is_index(code));
}

static void write_argument(int fd, char *arg, int code, write_context_t *ctx)
{
    int nbr = my_getnbr(arg);
    unsigned char byte[2] = {0};

    if (arg[0] == 'r') {
        write(fd, &nbr, 1);
        return;
    }
    if (arg[0] == '%') {
        nbr = direct_value(arg, ctx);
        write_direct_value(fd, code, nbr);
        return;
    }
    big_andian(nbr, byte);
    write(fd, byte, IND_SIZE);
}

static int emit_instruction(char **array, int fd, write_context_t *ctx)
{
    int code = get_op_index(array[0]);
    int coding = 0;

    if (code <= 0 || code >= 17)
        return FAILURE;
    write(fd, &code, 1);
    coding = coding_byte(array, code);
    if (there_is_coding_byte(code) == SUCCESS)
        write(fd, &coding, 1);
    for (int i = 1; array[i]; i++)
        write_argument(fd, array[i], code, ctx);
    *ctx->prog_s += prog_size(array, 0);
    return SUCCESS;
}

int write_instruction(char *buf, int fd, prog_t *prog, int *prog_s)
{
    char **array = my_str_to_word_array(buf, SEPARATOR_ROWS);
    write_context_t ctx = {prog, prog_s};
    int status = SUCCESS;

    if (is_blank_line(buf))
        return SUCCESS;
    if (!array)
        return FAILURE;
    trim_inline_comment(array);
    if (array[0])
        status = emit_instruction(array, fd, &ctx);
    free_array(array);
    return status;
}
