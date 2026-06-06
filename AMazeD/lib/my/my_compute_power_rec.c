/*
** EPITECH PROJECT, 2025
** racine carré
** File description:
** racine carré récurssive
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0){
        return (0);
    }
    if (p == 0){
        return (1);
    } else {
        nb = nb * my_compute_power_rec(nb, p - 1);
    }
    return (nb);
}
