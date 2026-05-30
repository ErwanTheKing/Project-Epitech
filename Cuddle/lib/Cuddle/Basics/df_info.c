/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** Prints column names and their detected data types in the dataframe
*/
/**
 * @file df_info.c
 * @brief Prints column names and their detected data types in the dataframe
 * @author Sacha Le Moign-Avalos && Erwan Lo Presti
 */

#include "../../Headers/dataframe.h"

void df_info(dataframe_t *dataframe)
{
    char *type[5] = {"bool", "int", "unsigned int", "float", "string"};

    if (!dataframe)
        return;
    printf("%d columns:\n", dataframe->nb_columns);
    for (int i = 0; (infos_data_t *)dataframe->data[0][i]; i++) {
        printf("- %s: %s\n", ((infos_data_t *)dataframe->data[0][i])->data,
            type[((infos_data_t *)dataframe->data[0][i])->type]);
    }
}
