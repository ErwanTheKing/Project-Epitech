/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** The options.c
*/

#include "include/includes.h"

static int is_option(char c)
{
    char *options = "alRdt";

    for (int i = 0; options[i] != '\0'; i++) {
        if (c == options[i])
            return 0;
    }
    return 1;
}

static int verif_options(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            return 0;
    }
    return 1;
}

char *str_clean(char *str)
{
    char *str_clean = malloc(sizeof(char) * 6);
    char *verif = malloc(sizeof(char) * 6);
    int a = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (is_option(str[i]) == 0 && verif_options(verif, str[i]) == 1) {
            str_clean[a] = str[i];
            verif[a] = str[i];
            a++;
        }
    }
    str_clean[i] = '\0';
    free(verif);
    return str_clean;
}

static int len_str(int argc, char **argv)
{
    int len = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-')
            len += my_strlen(argv[i] + 1);
    }
    return len;
}

char *fill_str(int argc, char **argv)
{
    char *str = malloc(sizeof(char) * (len_str(argc, argv) + 1));
    int i = 1;

    str[0] = '\0';
    if (argc == 1) {
        str = "";
        return str;
    }
    for (; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] != '\0')
            my_strcat(str, argv[i] + 1);
    }
    return str;
}

void erase_flag(options_t *options)
{
    if ((options->option1 == 'd' || options->option2 == 'd'
            || options->option3 == 'd' || options->option4 == 'd'
            || options->option5 == 'd') && (options->option1 == 'a'
            || options->option2 == 'a' || options->option3 == 'a'
            || options->option4 == 'a' || options->option5 == 'a')) {
        options->option1 = 'd';
        options->option2 = '0';
        options->option3 = '0';
        options->option4 = '0';
        options->option5 = '0';
    }
}

options_t *pre_fill_struct(void)
{
    options_t *options = malloc(sizeof(options_t));

    verif_moptions(options);
    options->option1 = '0';
    options->option2 = '0';
    options->option3 = '0';
    options->option4 = '0';
    options->option5 = '0';
    return options;
}

int fill_struct(options_t *options, int argc, char **argv, int many_options)
{
    char *str = fill_str(argc, argv);

    str = str_clean(str);
    many_options = my_strlen(str);
    for (int i = 0; i < many_options; i++) {
        if (i == 0)
            options->option1 = str[0];
        if (i == 1)
            options->option2 = str[1];
        if (i == 2)
            options->option3 = str[2];
        if (i == 3)
            options->option4 = str[3];
        if (i == 4)
            options->option5 = str[4];
    }
    erase_flag(options);
    free(str);
    return 0;
}
