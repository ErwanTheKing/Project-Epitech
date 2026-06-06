/*
** EPITECH PROJECT, 2025
** str for low case
** File description:
** put an str from up case to low case
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 65 && str[i] <= 90){
            str[i] = str[i] + 32;
        }
    }
    return (str);
}
