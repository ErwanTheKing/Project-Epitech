/*
** EPITECH PROJECT, 2025
** square root
** File description:
** racine carré
*/

int my_compute_square_root(int nb)
{
    int temp = 0;
    int result = 0;

    for (int i = 0; i < nb + 1; i++){
        temp = i * i;
        if (temp == nb){
            result = i;
            i = nb;
        }
        if (temp > nb){
            result = 0;
            i = nb + 1;
        }
    }
    return (result);
}
