/*
** EPITECH PROJECT, 2025
** digit return
** File description:
** return 1 if it's only digits
*/

int my_str_isnum(char *str)
{
    if (str[0] == '\0'){
        return (0);
    }
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < 48){
            return (1);
        }
        if (str[i] > 57){
            return (1);
        }
    }
    return (0);
}
