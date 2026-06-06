/*
** EPITECH PROJECT, 2025
** strncpy
** File description:
** copy the n catacter to another str
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i != n; i++){
        if (src[i] == '\0'){
            dest[i] = '\0';
            return (dest);
        }
        dest[i] = src[i];
    }
    return (dest);
}
