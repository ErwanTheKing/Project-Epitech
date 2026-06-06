/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** COREWAR_H
*/

#ifndef COREWAR_H
    #define COREWAR_H

    /* include */
    #include "my.h"
    #include <unistd.h>
    #include "op.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdbool.h>

    /* status */
    #define SUCCESS 0
    #define FAILED 84
    #define ALIVE 1

    /* function exit */
    #define ERR 42

    /* str */
    #define FLAG_HELP "-h"
    #define FLAG_DUMP "-dump"
    #define FLAG_ADDRESS "-a"
    #define FLAG_NUMBER "-n"
    #define FLAG_VISUAL "-v"
    #define FLAG_VISUAL_LONG "--visual"
    #define VISUAL_CELL_WIDTH 2
    #define VISUAL_CYCLES_PER_FRAME 10
    #define CORE_FORMATING ".cor"
    #define COREWAR "corewar: "

    /* other */
    #define CORE_LEN my_strlen(CORE_FORMATING)
    #define END_CYCLE 0
    #define SPEED 1
    #define OPTAB_OFFSET 1
    #define MAX_CHECKS 10

    /* error */
    #define CORE_FORMATING_ERR COREWAR "formating error\n"
    #define NOT_ENOUGHT_ARG COREWAR "not enought argument\n"
    #define RETRY_HELP COREWAR "retry with -h for help\n"
    #define NB_CYCLE_ERR COREWAR "you need a integer after -dump\n"
    #define NUMBER_ERR COREWAR "you need a integer after -n\n"
    #define ADDRESS_ERR COREWAR "you need a integer after -a\n"
    #define CANT_OPEN_FILE COREWAR "can't open file\n"

    /* index increment */
    #define OPCODE 1
    #define LIVE OPCODE + DIR_SIZE

typedef struct process_s {
    int pc;
    int carry;
    int reg[REG_NUMBER];
    int alive;
    int is_dead;
    int id;
    char *name;
} process_t;

typedef struct option_s {
    bool activate;
    int infos;
} option_t;

typedef struct champ {
    int fd;
    op_t *ops;
    header_t *header;
    int nb;
    process_t process;
    option_t prog_number;
    option_t address;
} champ_t;

typedef struct cursor {
    int index;
    int champion;
    int alive;
    process_t process;
    struct cursor *next;
    int cooldown;
    unsigned char opcode;
} cursor_t;

typedef struct prog {
    int nb_champ;
    node_t *list;
    int nb_cycle;
    int cycle;
    int speed;
    int dump_cycle;
    int total_cycles;
    int cycle_to_die;
    int nbr_live;
    int checks;
    bool dump_done;
    champ_t *last_live;
    unsigned char memory[MEM_SIZE];
    unsigned char owner[MEM_SIZE];
    bool visual;
    bool visual_stop;
    int visual_delay;
    cursor_t *cursors;
} prog_t;


typedef struct visual_grid_s {
    int width;
    int height;
    int cols;
    int rows;
    int cells;
} visual_grid_t;

typedef struct arg_read_s {
    int type;
    int pos;
    int direct_size;
    int value;
} arg_read_t;

typedef int (*instruction_t[])(prog_t *, cursor_t *);

/* functions */
int puterr(const char *error);
int my_help(int ac, char **av);
int check_corewar(int ac, char **av);
int corewar(int ac, char **av);
int is_cor_file(char *str);
int is_flag(char **av, int i, int ac);
int is_integer(char *str);
int is_dump(char **av, int i, int ac);
int is_number(char **av, int i, int ac);
int is_address(char **av, int i, int ac);
int is_champion(char *str);
void add_champion(prog_t *prog, char *filename);
int count_champions(prog_t *prog, int ac, char **av);
void close_files(prog_t *prog);
int is_files_open(prog_t *prog);
int champions_alive(prog_t *prog);
int corewar_loop(prog_t *prog);
void corewar_check_period(prog_t *prog);
int fill_prog(prog_t *prog, int ac, char **av);
void init_vm(prog_t *vm);
void write_hex(unsigned char byte);
void write_address(unsigned int value);
void write_memory(unsigned char *memory);
int read_champ(champ_t *champ, prog_t *prog, int address);
int is_magic_number(int nb);
void dump(prog_t *prog);
void create_cursor(int nb, int index, prog_t *prog);
void move_cursors(prog_t *prog);
void fill_champs_options(prog_t *prog, int ac, char **av);
int get_instruction_size(prog_t *prog, cursor_t *cursor, int op_index);
int16_t read_i16(const prog_t *prog, int pos);
champ_t *get_champ(prog_t *prog, int nb);
void print_winner(prog_t *prog);
int cw_addr(int pos);
int cw_read_mem(const prog_t *prog, int pos, int size);
void cw_write_mem(prog_t *prog, int pos, int value, int size);
void cw_set_owner(prog_t *prog, int pos, int size, int champion);
int cw_arg_type(unsigned char coding, int arg);
int cw_direct_size(int op_code);
int cw_arg_size(int type, int direct_size);
int cw_is_valid_reg(int reg);
int cw_get_reg(prog_t *prog, cursor_t *cursor, int reg, int *value);
int cw_set_reg(prog_t *prog, cursor_t *cursor, int reg, int value);
int cw_read_arg(prog_t *prog, cursor_t *cursor, arg_read_t *arg, int mod);
int cw_parse_arg_pos(prog_t *prog, cursor_t *cursor, arg_read_t args[],
    int op_index);
void cw_update_pc(prog_t *prog, cursor_t *cursor);
int is_visual_flag(char *str);
int corewar_visual_loop(prog_t *prog);

int visual_get_champ_color(prog_t *prog, int champion);
void visual_get_grid(visual_grid_t *grid);
int visual_get_cell_start(const visual_grid_t *grid, int cell);
int visual_get_cell_end(const visual_grid_t *grid, int cell);
int visual_get_range_owner(prog_t *prog, int start, int end);
int visual_get_cursor_owner(prog_t *prog, int start, int end);
void visual_draw_memory(prog_t *prog);
void visual_draw_winner(prog_t *prog);
void visual_handle_key(prog_t *prog, int key);
void visual_init(void);


/* Instruction prototypes */
int live(prog_t *prog, cursor_t *cursor);
int ld_corewar(prog_t *prog, cursor_t *cursor);
int st_corewar(prog_t *prog, cursor_t *cursor);
int add(prog_t *prog, cursor_t *cursor);
int sub(prog_t *prog, cursor_t *cursor);
int and(prog_t *prog, cursor_t *cursor);
int or_corewar(prog_t *prog, cursor_t *cursor);
int xor(prog_t *prog, cursor_t *cursor);
int zjmp(prog_t *prog, cursor_t *cursor);
int ldi(prog_t *prog, cursor_t *cursor);
int sti(prog_t *prog, cursor_t *cursor);
int fork_corewar(prog_t *prog, cursor_t *cursor);
int lld(prog_t *prog, cursor_t *cursor);
int lldi(prog_t *prog, cursor_t *cursor);
int lfork(prog_t *prog, cursor_t *cursor);
int print(prog_t *prog, cursor_t *cursor);


#endif /* !COREWAR_H */
