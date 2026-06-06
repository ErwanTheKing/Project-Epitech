/*
** EPITECH PROJECT, 2026
** write
** File description:
** write
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../lib/Headers/my.h"
#include "../lib/Headers/defines.h"
#include "../lib/Headers/factory.h"

static int open_cor_file(char *filename, int *fd)
{
    char *cor_file = cor_formating(filename);

    if (!cor_file)
        return FAILURE;
    *fd = open(cor_file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    free(cor_file);
    if (*fd == -1)
        return FAILURE;
    return SUCCESS;
}

void free_prog(prog_t *prog)
{
    if (prog->labels)
        free_array(prog->labels);
    if (prog->pos)
        free(prog->pos);
}

static int write_program(int fd, char *buff, int pos, prog_t *prog)
{
    char **array = my_str_to_word_array(&buff[pos], SEPARATOR_LINE);
    int prog_s = 0;

    if (!array)
        return FAILURE;
    for (int i = 0; array[i]; i++)
        if (write_instruction(array[i], fd, prog, &prog_s) == FAILURE) {
            free_array(array);
            return FAILURE;
        }
    free_array(array);
    return SUCCESS;
}

static int check_robot(robot_t *robot)
{
    if (robot->name[0] == '\0' || robot->comment[0] == '\0')
        return FAILURE;
    if (my_strlen(robot->name) > PROG_NAME_LENGTH)
        return put_err(".name too long\n");
    if (my_strlen(robot->comment) > COMMENT_LENGTH)
        return put_err(".comment too long\n");
    return SUCCESS;
}

int write_in(char *buff, char *filename)
{
    robot_t robot = create_robot(buff);
    int pos = skip_header(buff);
    prog_t prog = {0};
    int fd = 0;

    if (check_robot(&robot) == FAILURE)
        return FAILURE;
    if (get_labels(&buff[pos], get_nb_label(&buff[pos]), &prog) == FAILURE)
        return FAILURE;
    big_andian(prog.prog_size, robot.prog_size);
    if (open_cor_file(filename, &fd) == FAILURE)
        return FAILURE;
    if (clear_labels(buff, prog.labels) == FAILURE)
        return FAILURE;
    write(fd, &robot, sizeof(robot));
    if (write_program(fd, buff, pos, &prog) == FAILURE)
        return FAILURE;
    free_prog(&prog);
    close(fd);
    return SUCCESS;
}
