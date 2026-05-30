/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Prints a statistical summary of all columns in the dataframe
*/
/**
 * @file df_describe.c
 * @brief Prints a statistical summary of all columns in the dataframe
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include "../../Headers/dataframe.h"
#include <math.h>

static int verif_type(column_type_t type)
{
    if (type == INT)
        return SUCCESS;
    if (type == UINT)
        return SUCCESS;
    if (type == FLOAT)
        return SUCCESS;
    return FAILURE;
}

static void standard_deviation(dataframe_t *dataframe, float mean, int i,
    int count)
{
    float sd = 0;
    float values = 0;
    char ***column = (char ***)dataframe->data;
    float min = atof(column[1][i]);
    float max = atof(column[1][i]);

    for (int j = 1; j < dataframe->nb_rows + 1; j++) {
        if (!column[j][i])
            continue;
        values = atof(column[j][i]);
        sd += (values - mean) * (values - mean);
        if (values < min)
            min = values;
        if (values > max)
            max = values;
    }
    sd = sd / count;
    sd = sqrt(sd);
    printf("Std: %.2f\n", sd);
    printf("Min: %.2f\nMax: %.2f\n", min, max);
}

static void calcul(char ***column, int i, dataframe_t *dataframe)
{
    int count = 0;
    float total = 0;
    float mean = 0;
    float values = 0;

    for (int j = 1; j < dataframe->nb_rows + 1; j++) {
        if (!column[j][i])
            continue;
        count++;
        values = atof(column[j][i]);
        total += values;
    }
    mean = total / count;
    printf("Count: %d\n", count);
    printf("Mean: %.2f\n", mean);
    standard_deviation(dataframe, mean, i, count);
}

void df_describe(dataframe_t *dataframe)
{
    if (!dataframe)
        return;
    for (int i = 0; i < dataframe->nb_columns; i++) {
        if (verif_type(((infos_data_t *)dataframe->data[0][i])->type)
            == SUCCESS) {
            printf("Column: %s\n",
                ((infos_data_t *)dataframe->data[0][i])->data);
            calcul((char ***)dataframe->data, i, dataframe);
        }
    }
}
