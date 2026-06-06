/*
** EPITECH PROJECT, 2025
** my prime
** File description:
** return des nombres premiers
*/

static int find_my_divisor(int nmb)
{
    int result = 0;

    for (int i = 2; i < nmb; i++){
        result = nmb % i;
        if (result == 0){
            result = 0;
            i = nmb;
        } else {
            result = 1;
        }
    }
    return (result);
}

int my_is_prime(int nb)
{
    if (nb < 2){
        return (0);
    }
    if (nb == 2){
        return (1);
    }
    return (find_my_divisor(nb));
}
