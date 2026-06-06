/*
** EPITECH PROJECT, 2025
** swap
** File description:
** echange entre deux variable
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
