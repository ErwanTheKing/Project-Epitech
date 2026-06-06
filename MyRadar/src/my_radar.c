/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** myradar
*/

#include "../include/includes.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

static char *open_file(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buffer = NULL;
    struct stat file_stat;

    if (fd == -1)
        return NULL;
    stat(file, &file_stat);
    buffer = malloc(sizeof(char) * (file_stat.st_size + 1));
    if (buffer == NULL)
        return NULL;
    read(fd, buffer, file_stat.st_size);
    buffer[file_stat.st_size] = '\0';
    close(fd);
    return buffer;
}

static int verif_isnum(main_radar_t *radar, int i)
{
    for (int j = 1; radar->file_infos[i][j] != '\0'; j++) {
        if (my_char_isnum(radar->file_infos[i][j]) == 0
            && radar->file_infos[i][j] != ' '
            && radar->file_infos[i][j] != '\t')
            return FAILURE;
    }
    return SUCCESS;
}

int verif_file(char *file, main_radar_t *radar)
{
    char *buffer = open_file(file);

    if (buffer == NULL)
        return FAILURE;
    radar->file_infos = my_str_to_word_array(buffer, "\n");
    free(buffer);
    if (radar->file_infos == NULL)
        return FAILURE;
    for (int i = 0; radar->file_infos[i] != NULL; i++) {
        if (radar->file_infos[i][0] != 'A' && radar->file_infos[i][0] != 'T')
            return FAILURE;
        if (verif_isnum(radar, i) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

static int init(main_radar_t *radar)
{
    radar->st_game = MAIN;
    radar->st_main = PLAY;
    radar->st_pause = RESUME;
    radar->clock.clock = sfClock_create();
    radar->last_clock.clock = sfClock_create();
    radar->clock_time = sfClock_create();
    if (create_sounds(radar) == FAILURE)
        return FAILURE;
    if (create_main(radar) == FAILURE)
        return FAILURE;
    if (create_game(radar) == FAILURE)
        return FAILURE;
    if (create_pause(radar) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

static void destroy(main_radar_t *radar)
{
    destroy_main_menu(radar);
    destroy_sounds(radar);
    destroy_game(radar);
    destroy_pause(radar);
    sfClock_destroy(radar->last_clock.clock);
    sfClock_destroy(radar->clock.clock);
    sfClock_destroy(radar->clock_time);
    del_plane(&radar->plane);
    del_tower(&radar->tower);
    free(radar->file_infos);
    sfRenderWindow_destroy(radar->window);
    free(radar);
}

static void window_open(main_radar_t *radar)
{
    while (sfRenderWindow_isOpen(radar->window)) {
        radar->clock.time = sfClock_restart(radar->clock.clock);
        radar->last_clock.time
        = sfClock_getElapsedTime(radar->last_clock.clock);
        radar->clock.seconds = sfTime_asSeconds(radar->clock.time);
        radar->last_clock.seconds = sfTime_asSeconds(radar->last_clock.time);
        radar->time = sfClock_getElapsedTime(radar->clock_time);
        radar->seconds = sfTime_asSeconds(radar->time);
        event_basic(radar);
        display_state(radar);
        sfRenderWindow_display(radar->window);
    }
}

static int verif(main_radar_t *radar)
{
    if (!radar->window) {
        free(radar);
        return FAILURE;
    }
    if (init(radar) == FAILURE)
        return FAILURE;
    window_open(radar);
    return SUCCESS;
}

int create_window(char **argv)
{
    main_radar_t *radar = malloc(sizeof(main_radar_t));
    sfVideoMode mode = {1920, 1080, 32};

    if (!radar)
        return FAILURE;
    if (verif_file(argv[1], radar) == FAILURE) {
        write(2, "Error with file\n", 16);
        return FAILURE;
    }
    radar->mode = mode;
    radar->window = sfRenderWindow_create(radar->mode, "NebulaRadar",
        sfTitlebar | sfClose, NULL);
    if (verif(radar) == FAILURE)
        return FAILURE;
    window_open(radar);
    destroy(radar);
    return SUCCESS;
}
