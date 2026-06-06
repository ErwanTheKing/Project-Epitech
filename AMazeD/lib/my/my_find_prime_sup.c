/*
** EPITECH PROJECT, 2025
** my prime sup
** File description:
** renvoi le prime sup ou egal
*/

static int find_my_divisor2(int nmb)
{
    int result = 0;

    for (int i = 2; i < nmb; i++){
        result = nmb % i;
        if (result == 0){
            result = 0;
            i = nmb;
        } else {
            result = i;
        }
    }
    return (result);
}

static int my_is_prime2(int nb)
{
    if (nb < 2){
        return (0);
    }
    if (nb == 2){
        return (2);
    }
    return (find_my_divisor2(nb));
}

int my_find_prime_sup(int nb)
{
    for (int i = nb; i != nb - 1; i++){
        if (my_is_prime2(i) > 0){
            return (i);
        }
    }
    return 0;
}
