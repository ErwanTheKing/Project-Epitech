/*
** EPITECH PROJECT, 2026
** Cuddle
** File description:
** my_triple_array_len
*/

int my_triple_array_len(void ***array)
{
    int i = 0;

    if (!array)
        return 0;
    for (; array[i]; i++);
    return i;
}
