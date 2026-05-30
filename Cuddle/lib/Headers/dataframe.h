/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Dataframe types, enums and function prototypes for the Cuddle library
*/
/**
 * @file dataframe.h
 * @brief Dataframe types, enums and function prototypes for the Cuddle library
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#ifndef CUDDLE_H_
    #define CUDDLE_H_
    #include "my.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
typedef struct dataframe_shape_s {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;
typedef enum column_type_e {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED,
} column_type_t;
typedef struct infos_data_s {
    char *data;
    column_type_t type;
} infos_data_t;
typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    void ***data;
    char *separator;
} dataframe_t;
typedef struct sort_ctx_s {
    int col;
    int cols;
    column_type_t type;
    bool (*sort_func)(void *, void *);
} sort_ctx_t;
typedef struct groupby_s {
    dataframe_t *dataframe;
    const char *aggregate_by;
    const char **to_aggregate;
    void *(*agg_func)(void **values, int nb_values);
} groupby_t;
typedef struct cell_s {
    groupby_t *group;
    void ***data;
    int i;
    size_t j;
} cell_t;
typedef struct value_pair_s {
    void *a;
    void *b;
} value_pair_t;
void free_data(void ***data);
dataframe_t *df_read_csv(const char *filename, const char *separator);
dataframe_t *df_groupby(dataframe_t *dataframe, const char *aggregate_by,
    const char **to_aggregate, void *(*agg_func)(void **values, int nb_values));
void df_describe(dataframe_t *dataframe);
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
void df_info(dataframe_t *dataframe);
dataframe_shape_t df_shape(dataframe_t *dataframe);
dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows);
int df_write_csv(dataframe_t *dataframe, const char *filename);
dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *value));
dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool (*sort_func)(void *value1, void *value2));
dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value));
dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast);
void df_free(dataframe_t *dataframe);
void **df_get_unique_values(dataframe_t *dataframe, const char *column);
void *df_get_value(dataframe_t *dataframe, int row, const char *column);
void **df_get_values(dataframe_t *dataframe, const char *column);
column_type_t find_type(char *data, column_type_t type);
int get_nbr_columns(char *str, const char *separator);
void *str_to_str(char *data);
void *str_to_bool(char *data);
void *str_to_unsigned_int(char *data);
void *str_to_float(char *data);
void *str_to_int(char *data);
void ***my_triple_array_dup(void ***array);
void ***my_triple_array_n_dup(void ***array, int n);
int my_triple_array_len(void ***array);
dataframe_t *build_sorted_result(dataframe_t *df, void ***rows,
    struct sort_ctx_s *ctx);
void free_row(void **row, int cols, bool header);
void **dup_row(void **row, int cols, bool header);
void free_rows(void ***rows, int count, int cols, bool header);
int fill_sorted_rows(void ***rows, const dataframe_t *df, const int cols);
int sort_row_buffer(void ***rows, void ***tmp, const dataframe_t *df,
    struct sort_ctx_s *ctx);
int get_sell_values(void **left, void **right,
    struct value_pair_s *pair, const struct sort_ctx_s *ctx);
dataframe_t *convert_collumn(dataframe_t *dataframe, const char *column);
int get_collumn_index(dataframe_t *dataframe, char *column);
dataframe_t *reset_collumn_type(dataframe_t *dataframe, int index);
void **get_values_rows(dataframe_t *dataframe, const char *column, char *rows,
    char *agg);
char *int_to_str(void *ptr);
char *uint_to_str(void *ptr);
char *float_to_str(void *ptr);
char *bool_to_str(void *ptr);
char *string_to_str(void *ptr);
#endif
