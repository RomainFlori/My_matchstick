/*
** EPITECH PROJECT, 2020
** directory
** File description:
** game
*/

#include "my.h"

char **ia(char **map1)
{
    int x = 0;
    int l = 0;
    int z;
    int nb = 0;

    for (l = 0, x = 0; map1[l][x] != '|'; x++) {
        if (map1[l][x] == '\0') {
            l++;
            x = 0;
        }
    }
    if (map1[l][x] == '|') {
        for (z = x; map1[l][z] == '|'; z++);
        z--;
        map1[l][z] = ' ';
    }
    return map1;
}

int line_ia(char **map1)
{
    int x = 0;
    int l = 0;
    int z;
    int nb = 0;

    for (l = 0, x = 0; map1[l][x] != '|'; x++) {
        if (map1[l][x] == '\0') {
            l++;
            x = 0;
        }
    }
    return l;
}

int parse(int ac, char **av, char **square)
{
    int av1 = my_atoi(av[1]);
    int nbpipe = 0;
    for (int i = 1; i != av1+1; i++) {
        for (int x = 0; square[i][x] != '\0'; x++) {
            if (square[i][x] == '|')
                nbpipe++;
        }
    }
    return nbpipe;
}

int reduction_main(char *matches, int passed_in, int nbmatches, int av2)
{
    if ((matches[0] > '9' || matches[0] < '0') || matches[0] == '-') {
        my_putstr("Error: invalid input (positive number expected)\n");
        my_putstr("Line: ");
        passed_in++;
    }
    else if (nbmatches > av2) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(av2);
        my_putstr(" matches per turn\nLine: ");
        passed_in++;
    }
    else if (nbmatches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        my_putstr("Line: ");
        passed_in++;
    }
    return passed_in;
}

int main(int ac, char **av)
{
    if (ac != 3)
        return 84;
    else if (av[1][0] == '-' || av[2][0] == '-' || my_atoi(av[1]) >= 100)
        return 84;
    size_t buffsize = 32;
    char *line = malloc(sizeof(char) * 1000);
    char *matches = malloc(sizeof(char) * 1000);
    int nbmatches = 0;
    int nbline = 0;
    int nbpipe = 1;
    char **map1 = map(ac, av);
    int av1 = my_atoi(av[1]);
    int av2 = my_atoi(av[2]);
    int passed_in = 0;

    while (nbpipe != 0) {
        for (int i = 0; i != av1 + 2; i++)
            my_putstr(map1[i]);
        my_putstr("\nYour turn:\nLine: ");
        line = get_next_line(0);
        if (line == NULL)
            return (0);
        nbline = my_getnbr(line);
        if (nbline <= 0 || nbline > av1) {
            my_putstr("Error: this line is out of range\nLine: ");
            getline(&line, &buffsize, stdin);
            nbline = my_getnbr(line);
        }

        my_putstr("Matches: ");
        matches = get_next_line(0);
        if (matches == NULL)
            return (0);
        nbmatches = my_getnbr(matches);
        passed_in = reduction_main(matches, passed_in, nbmatches, av2);

        if (passed_in != 0) {
            getline(&line, &buffsize, stdin);
            nbline = my_getnbr(line);
            my_putstr("Matches: ");
            getline(&matches, &buffsize, stdin);
            nbmatches = my_getnbr(matches);
            passed_in = 0;
        }
        my_putstr("Player removed ");
        my_putnbr(nbmatches);
        my_putstr(" match(es) from line ");
        my_putnbr(nbline);
        my_putchar('\n');
        map1 = removepipe(nbline, nbmatches, map1);
        nbpipe = parse(ac, av, map1);
        if (nbpipe == 0) {
            for (int i = 0; i != av1 + 2; i++)
                my_putstr(map1[i]);
            my_putstr("You lost, too bad...\n");
            return 2;
        }
        if (nbpipe != 0) {
            for (int i = 0; i != av1 + 2; i++)
                my_putstr(map1[i]);
            my_putstr("\nAI's turn...\n");
            my_putstr("AI removed 1 match(es) from line ");
            my_putnbr(line_ia(map1));
            my_putchar('\n');
            map1 = ia(map1);
            nbpipe = parse(ac, av, map1);
            if (nbpipe == 0) {
                for (int i = 0; i != av1 + 2; i++)
                    my_putstr(map1[i]);
                my_putstr("I lost... snif... but I'll get you next time!!\n");
                return 1;
            }
        }
    }
}
