/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** array_len
*/

int len(char **array)
{
    int i;

    for (i = 0; array[i] != 0; i++);
    return i;
}
