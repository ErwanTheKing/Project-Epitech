/*
** EPITECH PROJECT, 2025
** str alpha
** File description:
** reurn 1 if the string contain only letter of alphabet
*/

int my_str_isalpha(char const *str)
{
    if (str[0] == '\0'){
        return (1);
    }
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < 65){
            return (0);
        }
        if (str[i] > 122){
            return (0);
        }
        if (str[i] < 97 && str[i] > 90){
            return (0);
        }
    }
    return (1);
}
