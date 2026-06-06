/*
** EPITECH PROJECT, 2026
** mytop
** File description:
** The get_flags.c
*/
/**
 * @file get_flags.c
 * @brief The get_flags.c
 * @author Erwan Lo Presti
 */

#include <math.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../include/my.h"
#include "../../include/my_top.h"

static void init_flags(flags_t *info_flags)
{
    info_flags->user = NULL;
    info_flags->refresh = 3;
    info_flags->frame = 0;
    info_flags->flag_frame = FALSE;
}

int get_flags(flags_t *info_flags, char **argv, int i)
{
    if (strcmp(argv[i], "-U") == 0) {
        info_flags->user = argv[i + 1];
        return SUCCESS;
    }
    if (strcmp(argv[i], "-d") == 0) {
        info_flags->refresh = strtof(argv[i + 1], NULL);
        return SUCCESS;
    }
    if (strcmp(argv[i], "-n") == 0) {
        info_flags->frame = strtod(argv[i + 1], NULL);
        info_flags->flag_frame = TRUE;
        return SUCCESS;
    }
    return FAILURE;
}

int verif_flag(flags_t *info_flags)
{
    char *nbr = NULL;

    if (info_flags->refresh < 0) {
        write(2, "my_top: -d requires positive argument\n", 38);
        return FAILURE;
    }
    if (floor(info_flags->frame) != info_flags->frame
        || (info_flags->frame <= 0 && info_flags->flag_frame == TRUE)) {
        nbr = my_nbr_to_str(info_flags->frame, 0);
        write(2, "my_top: bad iterations argument '", 33);
        write(2, nbr, strlen(nbr));
        write(2, "'\n", 2);
        free(nbr);
        return FAILURE;
    }
    return SUCCESS;
}

flags_t *prefill_info_flags(int argc, char **argv)
{
    flags_t *info_flags = malloc(sizeof(flags_t));

    if (!info_flags)
        return NULL;
    init_flags(info_flags);
    if (argc > 7 || argc % 2 == 0) {
        free(info_flags);
        return NULL;
    }
    for (int i = 1; argv[i] != NULL; i += 2) {
        if (get_flags(info_flags, argv, i) == FAILURE)
            return NULL;
    }
    if (verif_flag(info_flags) == FAILURE)
        return NULL;
    return info_flags;
}
