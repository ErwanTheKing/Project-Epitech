/*
** EPITECH PROJECT, 2026
** My_Top
** File description:
** my_top
*/

#ifndef TOP_H
    #define TOP_H
    #include <time.h>
    #include <stdbool.h>
    #define TIME_PATH "/sys/class/rtc/rtc0/time"
    #define UPTIME_PATH "/proc/uptime"
    #define AVG_PATH "/proc/loadavg"
    #define PROC_PATH "/proc/"
    #define STAT_PATH "/proc/stat"
    #define MEMINFO_PATH "/proc/meminfo"
typedef struct flags_s {
    char *user;
    float refresh;
    double frame;
    bool flag_frame;
} flags_t;
typedef struct top_s {
    int down;
    int right;
    flags_t *info_flags;
    time_t start_time;
} top_t;
typedef struct tasks_s {
    int total;
    int running;
    int sleeping;
    int stopped;
    int zombie;
} tasks_t;
typedef struct cpu_s {
    unsigned long long us;
    unsigned long long sy;
    unsigned long long ni;
    unsigned long long id;
    unsigned long long wa;
    unsigned long long hi;
    unsigned long long si;
    unsigned long long st;
} cpu_t;
int print_cpu_percentage(char **PIDs, int i);
int print_mem_percentage(char **PIDS, int i);
int print_state(char **PIDS, int i);
int print_shr(char **PIDS, int i);
int print_res(char **PIDS, int i);
int print_virt(char **PIDS, int i);
int print_ni(char **PIDS, int i);
int print_pr(char **PIDS, int i);
int print_username(char **PIDs, int i);
int count_runnings(void);
top_t *init_screen(void);
int header(void);
int header_meta_data(void);
int header_task_info(void);
int header_cpu_info(void);
int header_mem_info(void);
int header_swap_info(void);
int main_title(void);
int body(top_t *top_struct);
void print_us(double us, double sy, double ni, double id);
void print_wa(double wa, double hi, double si, double st);
flags_t *prefill_info_flags(int argc, char **argv);
#endif /* TOP_H */
