/*
** EPITECH PROJECT, 2020
** directory
** File description:
** fonction
*/

#include "my.h"

char **map(int ac, char **av)
{
    int av1 = my_atoi(av[1]);
    int z = 0;
    int y = 0;
    char **square = malloc(sizeof(char *) * av1 + 2);
    for (int i = 0; i != av1 + 2; i++)
        square[i] = malloc(sizeof(char) * av1 * 2 + 1);
    for (int i = 1; i <= av1 + 2; i++) {
        for (int j = 1; j <= (av1 * 2) + 1; j++) {
            if (i == 1 || i == av1 + 2 || j == 1 || j == (av1 * 2) + 1)
                square[z][y++] = '*';
            else
                square[z][y++] = ' ';
        }
        square[z++][y] = '\n';
        y = 0;
    }
    int i = av1;
    for (int bas = 1, badg = av1 * 2 - 1; i > 0; bas++, badg--, i--)
        for (int bas2 = bas; bas2 <= badg; bas2++)
            square[i][bas2] = '|';
    return square;
}

char **removepipe(int nbline, int nbmatches, char **map1)
{
    int i;
    int z;
    for (i = 0; map1[nbline][i] != '|'; i++);
    for (z = i; map1[nbline][z] == '|'; z++);
    z--;
    for (int rm = 0; rm != nbmatches; rm++, z--)
        map1[nbline][z] = ' ';
    return map1;
}
