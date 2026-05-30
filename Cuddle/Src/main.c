/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Entry point: reads a CSV, writes the output and frees the dataframe
*/
/**
 * @file main.c
 * @brief Entry point: reads a CSV, writes the output and frees the dataframe
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/Headers/dataframe.h"
#include <stdio.h>
#include <stdbool.h>

bool func(void *v) { return *(unsigned int*)v > 30; }

int main(void)
{
    dataframe_t *df = df_read_csv("Utilities/data.csv", NULL);
    dataframe_t *r  = df_filter(df, "age", func);
    if (!r) return 1;
    printf("%d\n", r->nb_rows);
    void *n0 = df_get_value(r, 0, "name");
    void *n1 = df_get_value(r, 1, "name");
    if (n0) printf("%s\n", (char*)n0);
    if (n1) printf("%s\n", (char*)n1);
    free(n0);
    free(n1);
    df_free(df);
    df_free(r);
    return 0;
}
