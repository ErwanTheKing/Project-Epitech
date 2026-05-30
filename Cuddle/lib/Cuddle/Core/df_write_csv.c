/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Writes the contents of a dataframe to a CSV file
*/
/**
 * @file df_write_csv.c
 * @brief Writes the contents of a dataframe to a CSV file
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */


#include "../../Headers/dataframe.h"

static void print_content(FILE *file, dataframe_t *dataframe, size_t i)
{
    for (size_t j = 0; j < dataframe->nb_columns; j++) {
        if (dataframe->data[i][j])
            fprintf(file, "%s", (char *)dataframe->data[i][j]);
        if (j < dataframe->nb_columns - 1)
            fprintf(file, "%s", dataframe->separator);
    }
    fprintf(file, "\n");
}

int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    FILE *file;

    if (!dataframe || !filename)
        return FAILURE;
    file = fopen(filename, "w");
    if (!file)
        return FAILURE;
    for (size_t j = 0; j < dataframe->nb_columns; j++) {
        if (dataframe->data[0][j])
            fprintf(file, "%s",
                ((infos_data_t *)dataframe->data[0][j])->data);
        if (j < dataframe->nb_columns - 1)
            fprintf(file, "%s", dataframe->separator);
    }
    fprintf(file, "\n");
    for (size_t i = 1; i < dataframe->nb_rows + 1; i++) {
        print_content(file, dataframe, i);
    }
    fclose(file);
    return SUCCESS;
}
