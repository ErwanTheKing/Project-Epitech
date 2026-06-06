/*
** EPITECH PROJECT, 2026
** ~/epitech/delivery/G-CPE-110-NCE-1-1-secured-2/src
** File description:
** str_to_int
*/

int str_to_int(char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; i++) {
        result = result * 10 + (str[i] - '0');
    }
    return result * sign;
}
