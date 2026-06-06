/*
** EPITECH PROJECT, 2026
** struct
** File description:
** struct
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512
    #define MAX_ARGS_NUMBER 4
    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"
    #define PACKED_ATTR __attribute__((packed))
    #define REG_NUMBER 16

    #define NAME_CMD_LEN my_strlen(NAME_CMD_STRING)
    #define COMMENT_CMD_LEN my_strlen(COMMENT_CMD_STRING)
    #define SEPARATOR_LINE "\n"
    #define SEPARATOR_ROWS "\t ,"

typedef char args_type_t;
    #define T_REG 1
    #define T_DIR 2
    #define T_IND 4
    #define T_LAB 8

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE

extern const op_t op_tab[];

    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3
    #define CYCLE_TO_DIE 1536
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40

typedef struct robot {
    unsigned char magic[4];
    char name[PROG_NAME_LENGTH + 1];
    char padding1[3];
    unsigned char prog_size[4];
    char comment[COMMENT_LENGTH + 1];
    char padding2[3];
} robot_t;

typedef struct prog {
    int nb_label;
    char **labels;
    int *pos;
    int prog_size;
} prog_t;

typedef struct write_context_s {
    prog_t *prog;
    int *prog_s;
} write_context_t;

#endif /* !STRUCT_H */
