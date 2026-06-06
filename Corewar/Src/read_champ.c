/*
** EPITECH PROJECT, 2026
** ~/Epitech/Project/Corewar/Src
** File description:
** read_champ
*/

#include "../lib/Headers/corewar.h"

static int fill_process(champ_t *champ, int address,
    header_t *header, prog_t *prog)
{
    champ->process.pc = address;
    champ->process.carry = 0;
    champ->process.alive = 0;
    champ->process.is_dead = 0;
    champ->process.id = 0;
    champ->process.name = NULL;
    for (int i = 0; i < REG_NUMBER; i++)
        champ->process.reg[i] = 0;
    champ->process.reg[0] = champ->nb;
    champ->process.id = champ->prog_number.activate
        ? champ->prog_number.infos : champ->nb;
    champ->process.name = my_strdup(header->prog_name, 0);
    if (!champ->process.name)
        return FAILURE;
    create_cursor(champ->nb, address, prog);
    return SUCCESS;
}

static int read_header_raw(champ_t *champ, header_t *header)
{
    if (lseek(champ->fd, 0, SEEK_SET) == -1)
        return puterr(CORE_FORMATING_ERR);
    if (read(champ->fd, header, sizeof(header_t)) != sizeof(header_t))
        return puterr(CORE_FORMATING_ERR);
    return SUCCESS;
}

static int validate_header(const header_t *header)
{
    if (is_magic_number(header->magic) == FAILURE)
        return puterr(CORE_FORMATING_ERR);
    return SUCCESS;
}

static int read_header(champ_t *champ, header_t *header)
{
    if (read_header_raw(champ, header) == FAILURE)
        return FAILURE;
    return validate_header(header);
}

static int load_code(champ_t *champ, prog_t *prog, int address, int size)
{
    unsigned char *code = malloc(size);

    if (code == NULL)
        return FAILURE;
    if (read(champ->fd, code, size) != size) {
        free(code);
        return puterr(CORE_FORMATING_ERR);
    }
    for (int i = 0; i < size; i++) {
        prog->memory[(address + i) % MEM_SIZE] = code[i];
        prog->owner[(address + i) % MEM_SIZE] = champ->nb;
    }
    free(code);
    return SUCCESS;
}

int read_champ(champ_t *champ, prog_t *prog, int address)
{
    header_t header = {0};
    int size = 0;

    if (read_header(champ, &header) == FAILURE)
        return FAILURE;
    size = __builtin_bswap32(header.prog_size);
    if (load_code(champ, prog, address, size) == FAILURE)
        return FAILURE;
    return fill_process(champ, address, &header, prog);
}
