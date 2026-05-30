/*
** EPITECH PROJECT, 2026
** G-AIA-200-NCE-2-1-cuddle-5
** File description:
** The type_to_str.c
*/
/**
 * @file type_to_str.c
 * @brief The type_to_str.c
 * @author Erwan Lo Presti
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *int_to_str(void *ptr)
{
    char *s = malloc(snprintf(NULL, 0, "%d", *(int *)ptr) + 1);

    sprintf(s, "%d", *(int *)ptr);
    return s;
}

char *uint_to_str(void *ptr)
{
    char *s = malloc(snprintf(NULL, 0, "%u", *(unsigned int *)ptr) + 1);

    sprintf(s, "%u", *(unsigned int *)ptr);
    return s;
}

char *float_to_str(void *ptr)
{
    char *s = malloc(snprintf(NULL, 0, "%f", *(float *)ptr) + 1);

    sprintf(s, "%f", *(float *)ptr);
    return s;
}

char *bool_to_str(void *ptr)
{
    char *s = malloc(snprintf(NULL, 0, "%d", *(bool *)ptr) + 1);

    sprintf(s, "%d", *(bool *)ptr);
    return s;
}

char *string_to_str(void *ptr)
{
    if (!ptr)
        return NULL;
    return strdup(*(char **)ptr);
}
