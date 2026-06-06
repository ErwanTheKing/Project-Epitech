/*
** EPITECH PROJECT, 2026
** occ
** File description:
** occ
*/

int occurrencies(char *buff, char c)
{
    int occ = 0;

    for (int index = 0; buff[index] != '\0'; index++) {
        if (buff[index] == c)
            occ++;
    }
    return occ;
}
